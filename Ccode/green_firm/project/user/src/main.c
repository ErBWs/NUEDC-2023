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



void packReceiveHandle(uint8_t *d, uint16_t s)
{
    rxData.cx = (d[1] << 8) | d[0];
    rxData.cy =  ((d[3] << 8)| d[2]);
    printf("%d %d\n",rxData.cx,rxData.cy);
}

void packSendHandle(uint8_t *d, uint16_t s)
{
    uart_write_buffer(UART_7, d, s);
//    for (int i = 0; i < s; i++)
//    {
//        printf("%c\n",i);
//    }
}

int main (void)
{
    clock_init(SYSTEM_CLOCK_120M);      // ��ʼ��оƬʱ�� ����Ƶ��Ϊ 120MHz
    debug_init();                       // ��ر��������������ڳ�ʼ��MPU ʱ�� ���Դ���

    uart_init(UART_7, 115200, UART7_MAP3_TX_E12, UART7_MAP3_RX_E13);
    upacker_inst myPack;
    upacker_inst_t myPackPtr = &myPack;
    upacker_init(myPackPtr,&packReceiveHandle,&packSendHandle);
    // �˴���д�û����� ���������ʼ�������
    pwmInit();
    pidAllInit();
    BuzzerInit();
    // �˴���д�û����� ���������ʼ�������
    taskTimAllInit();
    uart_rx_interrupt(UART_7,ENABLE);
    while(1)
    {
        // �˴���д��Ҫѭ��ִ�еĴ���
        if(BufferFinish == 1)
        {
            upacker_unpack(myPackPtr,Buffer,sizeof(Buffer));
            upacker_pack(myPackPtr,(uint8_t*)&rxData,sizeof(rxData));
            BufferFinish = 0;
            uart_rx_interrupt(UART_7,ENABLE);
        }
//        printf("aaaa\n");
//        system_delay_ms(500);
        // �˴���д��Ҫѭ��ִ�еĴ���
    }
}

