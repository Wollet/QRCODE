
#include "QRcode_main.h"

#define m_OFFSET_VALUE_X  60  //X坐标偏移
#define m_OFFSET_VALUE_Y  15  //Y坐标偏移

void QRGenerator(char *input)
{
	int side, i,j,a;
	uint8_t bitdata[QR_MAX_BITDATA];
		
	//remove newline
	if(input[strlen(input) - 1] == '\n')
	{
		input[strlen(input) - 1] = 0;
	}
     
	side = qr_encode(QR_LEVEL_M, 0, input, 0, bitdata);//QR_LEVEL_L
	displayQRCode(side, bitdata);
}
    
void displayQRCode(int side, uint8_t *bitdata)
{
	int i=0;
	int j=0;
	int a=0;
	int l=0;
	int n=0;
	int OUT_FILE_PIXEL_PRESCALER = 10;//1  //查看发现太小了，我们可以修改显示函数的参数
    
    LCD_Fill(55,10,280,230,WHITE);  ///画二维码的白色外框
	
	if(side==21)
	{
		OUT_FILE_PIXEL_PRESCALER = 10;//2
	}

	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++) 
		{
			a=j*side+i;

			if((bitdata[a / 8] & (1 << (7 - a%8))))
			{
				for (l = 0; l < OUT_FILE_PIXEL_PRESCALER; l++)
				{
					for(n = 0; n < OUT_FILE_PIXEL_PRESCALER; n++)
					{
//						ILI9341_SetPointPixel(OUT_FILE_PIXEL_PRESCALER*i+l,OUT_FILE_PIXEL_PRESCALER*(j)+n,0x0);
						LCD_Fast_DrawPoint(OUT_FILE_PIXEL_PRESCALER*i+l+m_OFFSET_VALUE_X,OUT_FILE_PIXEL_PRESCALER*(j)+n+m_OFFSET_VALUE_Y,0xf);
					}
				}
			}
		}
	}
	
//	QRcode_free(qrcode);
} //？end displayQRCode?



