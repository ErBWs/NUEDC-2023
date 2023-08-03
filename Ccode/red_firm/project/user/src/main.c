/*********************************************************************************************************************
* CH32V307VCT6 Opensourec Library ����CH32V307VCT6 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
*
* ���ļ���CH32V307VCT6 ��Դ���һ����
*
* CH32V307VCT6 ��Դ�� ��������
* �����Ը��������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ���֤Э�� �����������Ϊ���İ汾
* �������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ���֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          main
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          MounRiver Studio V1.8.1
* ����ƽ̨          CH32V307VCT6
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����                                      ����                             ��ע
* 2022-09-15        ��W            first version
********************************************************************************************************************/
#include "zf_common_headfile.h"

uint8_t receiveSuccess = 1;

void packReceiveHandle(uint8_t *d, uint16_t s)
{
    rxData.cx = (d[1] << 8) | d[0];
    rxData.cy =  ((d[3] << 8)| d[2]);
    cornerPoint[0][0] = (d[5]<<8 | d[4]) - FRAME_WIDTH / 2 - 1;
    cornerPoint[0][1] = FRAME_HEIGHT / 2 - 1 - (d[7]<<8 | d[6]);
    cornerPoint[1][0] = (d[9]<<8 | d[8]) - FRAME_WIDTH / 2 - 1;
    cornerPoint[1][1] = FRAME_HEIGHT / 2 - 1 - (d[11]<<8 | d[10]);
    cornerPoint[2][0] = (d[13]<<8 | d[12]) - FRAME_WIDTH / 2 - 1;
    cornerPoint[2][1] = FRAME_HEIGHT / 2 - 1 - (d[15]<<8 | d[14]);
    cornerPoint[3][0] = (d[17]<<8 | d[16]) - FRAME_WIDTH / 2 - 1;
    cornerPoint[3][1] = FRAME_HEIGHT / 2 - 1 - (d[19]<<8 | d[18]);
    receiveSuccess = d[20];
    printf("%d %d %d %d %d %d %d %d %d %d %d\n",rxData.cx,rxData.cy ,
           (d[5]<<8 | d[4]),
           (d[5]<<8 | d[4]),
           (d[9]<<8 | d[8]),
           (d[11]<<8 | d[10]),
           (d[13]<<8 | d[12]),
           (d[15]<<8 | d[14]),
           (d[17]<<8 | d[16]),
           (d[19]<<8 | d[18]), d[20]);
}

void packSendHandle(uint8_t *d, uint16_t s)
{
    uart_write_buffer(UART_7, d, s);
//    for (int i = 0; i < s; i++)
//    {
//        printf("%c\n",i);
//    }
}

void pwm_set_servo_duty(pwm_channel_enum pin, uint32 duty)
{
    duty = Limitation(duty, (SERVO_MID-SERVO_DUTY_MAX), (SERVO_MID + SERVO_DUTY_MAX));
    pwm_set_duty(pin, duty);
}

int main (void)
{
    clock_init(SYSTEM_CLOCK_120M);                                              // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 144MHz
    debug_init();                                                               // ��ʼ��Ĭ�� Debug UART

    MenuInit();
    EasyUIInit(1);
//    vofaData[0] = cornerPoint[0][0];
//    vofaData[1] = cornerPoint[0][1];
//    VofaSendFrame();
//    vofaData[0] = cornerPoint[1][0];
//    vofaData[1] = cornerPoint[1][1];
//    VofaSendFrame();
//    vofaData[0] = cornerPoint[2][0];
//    vofaData[1] = cornerPoint[2][1];
//    VofaSendFrame();
//    vofaData[0] = cornerPoint[3][0];
//    vofaData[1] = cornerPoint[3][1];
//    VofaSendFrame();

    uart_init(UART_7, 115200, UART7_MAP3_TX_E12, UART7_MAP3_RX_E13);
    upacker_inst myPack;
    upacker_inst_t myPackPtr = &myPack;
    upacker_init(myPackPtr,&packReceiveHandle,&packSendHandle);
    uart_rx_interrupt(UART_7,ENABLE);

    system_delay_ms(500);

    pwm_init(TIM4_PWM_MAP1_CH1_D12, SERVO_FREQ, SERVO_UP_MID);          // Upper servo
    pwm_init(TIM4_PWM_MAP1_CH3_D14, SERVO_FREQ, SERVO_BOTTOM_MID);      // Bottom servo
    system_delay_ms(500);
//    BuzzerInit();
//    beepTime = 100;

//    system_delay_ms(2000);

    EasyUITransitionAnim();
    pit_ms_init(TIM1_PIT, 10);
    pit_ms_init(TIM2_PIT, 10);
    pit_disable(TIM2_PIT);
    extern uint16_t maxIndex;

    while(1)
    {
//        pwm_set_duty(TIM4_PWM_MAP1_CH1_D12, 00);
        if(BufferFinish == 1)
        {
            upacker_unpack(myPackPtr,Buffer,sizeof(Buffer));
//            upacker_pack(myPackPtr,(uint8_t*)&rxData,sizeof(rxData));
            BufferFinish = 0;
            uart_rx_interrupt(UART_7,ENABLE);
        }
        if (receiveSuccess)
        {
            GetRectLine();
            maxIndex = GetLaserPoint();
        }
        EasyUI(20);
//        system_delay_ms(20);
    }
}