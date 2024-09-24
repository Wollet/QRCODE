#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "QRcode_main.h"
#include "lcd.h"



int main(void)
{ 
 	
	delay_init(168);      //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
				
 	LCD_Init();           //��ʼ��LCD FSMC�ӿ�
	LCD_Clear(BLUE);	
	QRGenerator("12"); 
	//QRGenerator("999uU//*$%881_^");
	
}
