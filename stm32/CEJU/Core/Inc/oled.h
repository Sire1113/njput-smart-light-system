//
// Created by liyufan on 2021/10/14.
//

#ifndef INC_2022_LESSON_OLED_H
#define INC_2022_LESSON_OLED_H
#include "main.h"


#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64
//-----------------OLED�˿ڶ���----------------
//
//#define  OLED_RST_Pin RES_OLED_Pin
//#define  OLED_DC_Pin DC_OLED_Pin
//#define  OLED_CS_Pin SPI1_NSS_Pin
//
//#define OLED_RST_GPIO_Port GPIOB
//#define OLED_DC_GPIO_Port GPIOB
//#define OLED_CS_GPIO_Port GPIOA
//
//
//#define OLED_RST_Clr()  HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_RESET);
//#define OLED_RST_Set()  HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_SET);
//
//#define OLED_DC_Set()   HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_SET);
//#define OLED_DC_Clr()   HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_RESET);
//
//#define OLED_CS_Set()   HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);
//#define OLED_CS_Clr()   HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);
//
//#define OLED_CMD  0	//д����
//#define OLED_DATA 1	//д����

#define  SCL_PORT  GPIOA   // �ӣ�SCL��
#define  SCL_PIN   GPIO_PIN_5      // �ӣ�SCL��
#define  SDA_PORT  GPIOA   // �ӣ�SDA��
#define  SDA_PIN   GPIO_PIN_7      // �ӣ�SDA��
#define  RES_PORT  GPIOB   // �� (RST/RES)
#define  RES_PIN   GPIO_PIN_0      // �� (RST/RES)
#define  DC_PORT   GPIOB   // �� ��DC��
#define  DC_PIN    GPIO_PIN_1      // �� ��DC��
#define  CS_PORT   GPIOB  // �� ��CS��
#define  CS_PIN    GPIO_PIN_10     // �� ��CS��
//-----------------OLED�˿ڶ���----------------
//
#define OLED_SCLK_Clr() HAL_GPIO_WritePin(SCL_PORT,SCL_PIN,GPIO_PIN_RESET)//CLK
#define OLED_SCLK_Set() HAL_GPIO_WritePin(SCL_PORT,SCL_PIN,GPIO_PIN_SET)

#define OLED_SDIN_Clr() HAL_GPIO_WritePin(SDA_PORT,SDA_PIN,GPIO_PIN_RESET)//DIN
#define OLED_SDIN_Set() HAL_GPIO_WritePin(SDA_PORT,SDA_PIN,GPIO_PIN_SET)

#define OLED_RST_Clr()  HAL_GPIO_WritePin(RES_PORT,RES_PIN,GPIO_PIN_RESET)//RES
#define OLED_RST_Set()  HAL_GPIO_WritePin(RES_PORT,RES_PIN,GPIO_PIN_SET)

#define OLED_DC_Clr()   HAL_GPIO_WritePin(DC_PORT,DC_PIN,GPIO_PIN_RESET)//DC
#define OLED_DC_Set()   HAL_GPIO_WritePin(DC_PORT,DC_PIN,GPIO_PIN_SET)

#define OLED_CS_Clr()   HAL_GPIO_WritePin(CS_PORT,CS_PIN,GPIO_PIN_RESET)//CS
#define OLED_CS_Set()   HAL_GPIO_WritePin(CS_PORT,CS_PIN,GPIO_PIN_SET)

#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����
#define OLED_Width 128



//OLED�����ú���
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
//void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);
void OLED_Fill(unsigned char Fill_Data);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);
void OLED_Show_float(uint8_t x,uint8_t y,float num);
void OLED_Show_int(uint8_t x,uint8_t y,int num);
void OLED_Show_double(uint8_t x,uint8_t y,double num);
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
#endif //INC_2022_LESSON_OLED_H