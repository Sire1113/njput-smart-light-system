//
// Created by liyufan on 2021/10/17.
//

#ifndef INC_2022_LESSON_BMP_H
#define INC_2022_LESSON_BMP_H


static  unsigned char yuanshen[]={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xF0,0xFC,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x80,0x80,0xE0,0xF0,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x80,0x80,0xE0,0xF0,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0xC0,0xF0,0xFE,0xFF,0xFF,0xFF,0xF8,0xE0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x07,0x03,0x03,0xE1,0xE1,0xE1,0xE1,0xE1,0xE1,
0xC1,0xC1,0x41,0x41,0x41,0x41,0x41,0x59,0x7F,0x7F,0x7F,0x79,0x49,0x41,0x41,0x41,
0x41,0x41,0xE1,0xE1,0xE1,0xE1,0xE1,0xE1,0xC1,0xC1,0x01,0x01,0x01,0x41,0x41,0x41,
0x41,0x43,0x43,0x43,0x43,0xC7,0xCF,0xFF,0xDF,0xC7,0xE3,0xE3,0xF3,0xF1,0xF0,0xE0,
0xC0,0x80,0x00,0x00,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0x40,0x43,0x43,0x43,
0x47,0x47,0x4F,0xFF,0xFF,0xFF,0x47,0x47,0x43,0x43,0x43,0x41,0x40,0xE0,0xE0,0xF0,
0xF0,0xE0,0xE0,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0x88,0x88,0x88,0x88,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x88,0x80,
0x80,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,
0xFF,0xFF,0xFE,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0x01,0x01,0xF1,0xF1,0xF1,
0xF1,0x01,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x18,0x18,0x18,0x38,
0x3C,0x7E,0xFF,0xFF,0xFF,0xFF,0x7E,0x7C,0x3C,0x38,0x18,0x18,0x18,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xF0,0xFE,
0xFF,0x7F,0x3F,0x3F,0x0F,0x87,0xC1,0xC0,0xE0,0xE0,0xE3,0xE3,0xF3,0x73,0x71,0x71,
0x71,0x70,0x60,0x40,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x40,
0x40,0x61,0x73,0x73,0x73,0x73,0xF1,0xF1,0xE1,0xE0,0xE0,0xE0,0xC0,0xE0,0xFF,0xFF,
0x7F,0x3F,0x07,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x1F,0x0F,0x0F,
0x07,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x1F,0x1F,0x0F,0x0F,0x07,0x02,0x80,0x80,0x80,
0xC0,0xE0,0xF6,0xFF,0xFF,0xF7,0xE2,0xC0,0x80,0x80,0x80,0x82,0x06,0x07,0x0F,0x1F,
0x1F,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x02,0x03,0x01,0x01,0x01,
0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,0x03,0x04,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x1F,0x1F,0x0F,0x07,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x01,0x01,0x00,
0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x1F,0x1F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x03,
0x07,0x3F,0xFF,0xFF,0xFF,0xFF,0x7F,0x0F,0x07,0x03,0x01,0x01,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x01,0xFF,0xFF,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};/*"C:\Users\22007\Documents\Tencent Files\2200740542\FileRecv\取模软件\新建文件夹\WP73SSGO1)(ZTM1L~O]]6IH.bmp",0*/
/* (128 X 64 )*/


#define Sea_Logo_x 64
#define Sea_Logo_y 57

static  unsigned char Sea_Logo[] = {
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X80,0X80,0XC0,0X40,0X00,0X00,0X10,0X18,0X18,0X80,0X80,0X80,
        0XC0,0XC0,0XE0,0X60,0X60,0X60,0X60,0X60,0X60,0X60,0X60,0X60,0X60,0X60,0XE0,0XC0,
        0XC0,0X80,0X80,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0XC0,0X60,0X30,0X10,0X18,0X0C,
        0X06,0X82,0XC3,0XE1,0XF0,0X70,0X18,0XDC,0XEE,0XFE,0X7F,0XBB,0X9B,0X9D,0XCF,0XCE,
        0XC6,0XC7,0XC7,0XC3,0XC3,0XC3,0X83,0X03,0X03,0X07,0X07,0X07,0X07,0X0F,0X1E,0X1E,
        0XFE,0XF8,0XF1,0XC1,0X03,0X07,0X0E,0X1C,0XF0,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X80,0XE0,0XF0,0X78,0X0E,0X07,0X01,0X00,0X00,0X00,0X00,0X00,0X38,
        0XFF,0XFF,0XFF,0XF7,0XE0,0XE0,0XC3,0XC7,0XC7,0XC3,0XC3,0XE1,0XE1,0XE1,0XE1,0XF1,
        0XF1,0XF9,0X79,0X7F,0X3F,0X1F,0X0F,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0XE0,0XF0,
        0XFF,0X7F,0X1F,0X0F,0X00,0X00,0X00,0X80,0XFF,0X1F,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X3F,0XFF,0XFF,0XF0,0XE0,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X01,0X03,0X03,0X03,0X03,0X07,0X07,0X03,0X03,0X03,0X03,0X01,0X01,0X00,
        0X00,0X00,0X80,0X80,0XC0,0XE0,0XE0,0XF0,0XF0,0X78,0X3C,0X3E,0X1F,0X0F,0X07,0X03,
        0X01,0X00,0XC0,0XE0,0X70,0X1C,0X06,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X00,0X01,0X03,0X07,0X0F,0X0F,0X0F,0X0E,0X1E,0X1E,0X1E,0X1C,
        0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1C,0X1E,0X1E,0X0E,0X0E,0X0E,0X0F,
        0X07,0X07,0X07,0X03,0X03,0X01,0X01,0X00,0X00,0X00,0XC0,0XE0,0XF0,0X10,0X08,0X0C,
        0X06,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
        0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};
#define Sea_Log_x 36
#define Sea_Log_y 64

static  unsigned char Sea_Log[] = {
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 

};
#define Dinosaur_x 16
#define Dinosaur_y 16
//static unsigned char Dinosaur[] ={
//        0x00,0x3E,0x00,0x7B,0x00,0xFF,0x00,0xFF,0x00,0x0F,0x00,0x3F,0x83,0x07,0xE6,0x1F,
//        0xFE,0x17,0xFE,0x07,0xFC,0x07,0xF8,0x03,0xF0,0x01,0x20,0x01,0x20,0x01,0x60,0x03,/*"D:\桌面\dino.bmp",0*/
//};

static  unsigned char Dinosaur[] = {
        0X40,0XC0,0X80,0X00,0X00,0X80,0X80,0XC0,0XFE,0XFF,0XFD,0XBF,0XAF,0X2F,0X0E,0X0C,
        0X00,0X03,0X07,0X0F,0X1F,0XFF,0X9F,0X1F,0XFF,0X8F,0X07,0X00,0X01,0X00,0X00,0X00,
};
#define Bar1_x 8
#define Bar1_y 16
static  unsigned char Bar1[] ={
        0XF0,0XE0,0X00,0XFF,0XFF,0X80,0XFC,0X78,0X03,0X07,0X16,0XFF,0XFF,0X01,0X00,0X00,
};
#define Bar2_x 12
#define Bar2_y 24
static unsigned char Bar2[] ={
        0XC0,0XC0,0X00,0X00,0XFE,0XFF,0XFF,0XFE,0X00,0XE0,0XE0,0XC0,0X1F,0X3F,0X60,0X60,
        0XFF,0XFF,0XFF,0XFF,0X60,0X7F,0X3F,0X1F,0X00,0X00,0X00,0X00,0XFF,0XFF,0XFF,0XFF,
        0X00,0X00,0X00,0X00,
};

#endif //INC_2022_LESSON_BMP_H
