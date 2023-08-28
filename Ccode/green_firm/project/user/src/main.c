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
#include "inc_all.h"

void packReceiveHandle(uint8_t *d, uint16_t s) {
    rxData.cx = (d[1] << 8) | d[0];
    rxData.cy = ((d[3] << 8) | d[2]);

    rxData.cx-=SOLID_BIAS_X;
    rxData.cy-=SOLID_BIAS_Y;
//    if(rxData.cx!=0||rxData.cy!=0)
//        beepTime=100;
//    printf("%d %d\n", rxData.cx, rxData.cy);
}

void packSendHandle(uint8_t *d, uint16_t s) {
    uart_write_buffer(UART_7, d, s);
//    for (int i = 0; i < s; i++)
//    {
//        printf("%c\n",i);
//    }
}
upacker_inst myPack;
upacker_inst_t myPackPtr = &myPack;
int main(void) {
    clock_init(SYSTEM_CLOCK_120M);      // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 120MHz
    debug_init();                       // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���

    uart_init(UART_7, 115200, UART7_MAP3_TX_E12, UART7_MAP3_RX_E13);


    upacker_init(myPackPtr, &packReceiveHandle, &packSendHandle);
    // �˴���д�û����� ���������ʼ�������
    gpio_init(A8,GPI,1,GPI_PULL_UP);
    MenuInit();
    EasyUIInit(1);
    pwmInit();
    pidAllInit();
    BuzzerInit();
    cursorInit(&global_cursor, 0, 0, 0, 0, 0, 0);
    // �˴���д�û����� ���������ʼ�������
    taskTimAllInit();
    cursorResume(&global_cursor);
    system_delay_ms(2000);
    uart_rx_interrupt(UART_7, ENABLE);
    while (1) {
        EasyUI(20);
        // �˴���д��Ҫѭ��ִ�еĴ���

//        system_delay_ms(500);
        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}

