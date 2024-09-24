#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "QRcode_main.h"
#include "lcd.h"



int main(void)
{ 
 	
	delay_init(168);      //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
				
 	LCD_Init();           //初始化LCD FSMC接口
	LCD_Clear(BLUE);	
	QRGenerator("12"); 
	//QRGenerator("999uU//*$%881_^");
	
}
