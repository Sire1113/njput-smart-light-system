/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "oled.h"
#include "bmp.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t gpioReadStatus = GPIO_PIN_RESET;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
float pulseWidth;//脉宽（测距）
int second=0;//秒数
double m=0;
double s=0;
extern int keyflag;//回退键标志位
extern int keyflag2;//其他标志位
extern int keyflag3;
int taskflag1=0;
int task2flag=0;
int task3freq=1000;
float task3duty_change=0.5;
int task3duty_flag=1;
uint8_t  DATA[5]={0x3C,0x02,0,0,0x32};//串口数据包
int uart_task_flag1=0;
uint8_t RxBuffer[50];//串口接收
extern DMA_HandleTypeDef hdma_usart1_rx;//串口接收 关闭dma传输过半中断 需要的外部变量
void Trig()//触发函数，超声波测距起始信号
{
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET);
HAL_Delay(1);//延时1ms
HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET);
}

float duty=0;
float freq=0;
int fputc(int ch, FILE *f)
{
HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
return ch;
}

uint8_t Key_Scan(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	/*?4????????*/
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);
	
	//?4???????
	GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	//?4???????
	GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = GPIO_PIN_15;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_Delay(10);
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_15)==GPIO_PIN_RESET)//???1?
	{
		/*?4????????*/
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_15;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==GPIO_PIN_RESET)return 10;//+
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==GPIO_PIN_RESET)return 3;
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==GPIO_PIN_RESET)return 2;
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12)==GPIO_PIN_RESET)return 1;
	}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==GPIO_PIN_RESET)//???2?
	{
			/*?4????????*/
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_15;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==GPIO_PIN_RESET)return 11;//-
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==GPIO_PIN_RESET)return 6;
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==GPIO_PIN_RESET)return 5;
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12)==GPIO_PIN_RESET)return 4;
	}	
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==GPIO_PIN_RESET)//???3?
	{
			/*?4????????*/
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_15;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==GPIO_PIN_RESET)return 12;//*
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==GPIO_PIN_RESET)return 9;
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==GPIO_PIN_RESET)return 8;
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12)==GPIO_PIN_RESET)return 7;
	}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)==GPIO_PIN_RESET)//???4?
	{
			/*?4????????*/
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_15;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		//?4???????
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
	  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15)==GPIO_PIN_RESET)return 13;///
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14)==GPIO_PIN_RESET)return 14;//=
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13)==GPIO_PIN_RESET)return 0;
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12)==GPIO_PIN_RESET)return 15;//.
	}
	return 20;
}
void SendIlluminanceData(uint8_t illuminance, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    char dataToSend[5]; // ????????
    // ????:LxxRy,?? xx ?????(???),y ??GPIO???1?0

    // ??????? 00 ? 99 ????
    if (illuminance <10) {
        illuminance = 99;
    }
		else if(illuminance <10)illuminance=10;
    // ????GPIO?????,??????????1?0
    gpioReadStatus = HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);

    // ??????
    dataToSend[0] = 'L'; // ????'L'
    dataToSend[1] = '0' + (illuminance / 10); // ???????
    dataToSend[2] = '0' + (illuminance % 10); // ???????
    dataToSend[3] = 'R'; // ????'R'
    dataToSend[4] = gpioReadStatus ? '1' : '0';  // ????????GPIO??

    // ????????
    HAL_UART_Transmit(&huart1, (uint8_t *)dataToSend, sizeof(dataToSend), HAL_MAX_DELAY);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM4_Init();
  MX_TIM2_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  MX_TIM9_Init();
  MX_TIM5_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	OLED_Init();
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_4);
	//TIM4->CCR1=200;TIM4->ARR=300;//产生一个占空比50%，频率1k的pwm波
	TIM5->CCR3=50;
	HAL_TIM_Base_Start_IT(&htim4);
HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
//HAL_UART_Receive_IT(&huart1, RxBuffer, 3);
HAL_UARTEx_ReceiveToIdle_DMA(&huart1,RxBuffer, 50);//第一次开启串口接收
//uint32_t adc_value1;
//uint32_t adc_value2;
uint32_t adc_value[3];
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		
		
		
		
		
	  /*******ADC测量********/
		//HAL_ADC_Start_DMA(&hadc1,&adc_value1,1);
    //HAL_ADC_Start_DMA(&hadc1,&adc_value2,1);
		
	  //adc_value=HAL_ADC_GetValue(&hadc1);
		
			for(int i=0;i<2;i++)
		{
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1,50);
			adc_value[i]=HAL_ADC_GetValue(&hadc1);
		}
			HAL_ADC_Stop(&hadc1);
		
		
		int a=(int)adc_value[1]/41;  //light 
		//printf("%d\n",a);
		/*
		TIM4->CCR1=a/2;
		TIM4->ARR=a;
		*/
		OLED_ShowString(0,4,"            ");
		//OLED_Show_int(60,4,adc_value[0]);
		OLED_Show_int(0,4,abs(a-99));
		OLED_ShowString(0,8,"status:");
		OLED_Show_int(0,8,gpioReadStatus);
		SendIlluminanceData((uint8_t)abs(a-99),GPIOA,GPIO_PIN_11);
		//printf("%d\n",abs(a-99));
		HAL_Delay(500);
		
		
		
		
		
		/*******画图******/
		//OLED_DrawBMP(0, 0, 128, 8, yuanshen);
		
		
		/*******按键检测*****/
		{
//		if(keyflag)
//		{
//			do//等到有输入值再继续执行程序
//			{
//				 b=Key_Scan();
//			}
//		while(b==20);
//			if(b==0)
//				HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
//			if(b==1)
//			{
//			 TIM5->CCR3=50;//PWM占空比
//			 TIM5->ARR=100;//PWM周期
//			}
//			if(b==2)
//			{
//			 TIM5->ARR=100;//改周期
//			 if(task2flag==0)
//			 {
//				 TIM5->CCR3=10;//改占空比
//			 task2flag=1;
//			 }
//			 else
//			 {
//				 task2flag=1;
//				 if(TIM5->CCR3>90)
//					 task2flag=0;
//				else
//					{
//					TIM5->CCR3++;
//				  }
//			 }
//			}
//			if(b==3)
//			{
//				printf("task3ferq:%d\n",task3freq);printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);
//				
//				task3duty_change=(float)TIM5->CCR3/(float)TIM5->ARR;
//				TIM5->ARR=(int)(100000.0/task3freq);printf("arr:%d\n",TIM5->ARR);
//				TIM5->CCR3=(int)(task3duty_change*(float)TIM5->ARR);OLED_Show_int(60,2,(int)(task3duty_change*(float)TIM5->ARR));OLED_Show_int(60,4,TIM5->ARR);printf("arr2:%d\n",TIM5->ARR);
//				if(task3freq>9500)
//					task3freq=500;
//				task3freq=task3freq+500;
//				printf("task3ferq:%d\n",task3freq);printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);printf("task3duty_change:%f\n\n",task3duty_change);
//			}
//			if(b==4)
//			{
//				OLED_Show_float(0,0,duty);
//				OLED_Show_float(60,0,freq);
//			}
//			if(b==5)
//			{

//			}
//			
//			
//			
//			
//			
//			
//			
//			keyflag=0;
//		}
}




switch(Key_Scan())
{
	case 0:
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
	while(keyflag==0){HAL_Delay(1);}//按下按键返回上一级
	break;
	case 1:/********输出定频率方波********/
		OLED_Clear();
	 TIM5->CCR3=500;//PWM占空比
	 TIM5->ARR=1000-1;//PWM周期
	 printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);
	while(keyflag==0){HAL_Delay(1);}//按下按键返回上一级
	break;
	case 2:/********改占空比+1%********/
		OLED_Clear();
	 TIM5->ARR=1000-1;//改周期
	 if(task2flag==0)
	 {
		 TIM5->CCR3=100;//改占空比
		task2flag=1;
	 }
	 else
	 {
		 task2flag=1;
		 if(TIM5->CCR3>900)
			 task2flag=0;
			else
			TIM5->CCR3=TIM5->CCR3+10;
	 }
	  printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);
	 while(keyflag==0){HAL_Delay(1);}//按下按键返回上一级
		break;
	case 3:/********变化输出频率+500********/
		OLED_Clear();
		//printf("task3ferq:%d\n",task3freq);printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);
		if(task3duty_flag)
			task3duty_change=(float)TIM5->CCR3/(float)TIM5->ARR;//获取原先的输出占空比
		TIM5->ARR=(int)(1000000.0/task3freq)-1;//根据频率调整周期（arr）
		TIM5->CCR3=(int)(task3duty_change*(float)TIM5->ARR);//根据占空比和周期调整ccr，使输出的占空比不变
		/*OLED_Show_int(60,2,TIM5->CCR3);OLED_Show_int(60,4,TIM5->ARR);*/printf("ccr:%d\n",TIM5->CCR3);printf("arr:%d\n",TIM5->ARR);//打印频率和占空比
		OLED_Show_float(60,2,(float)TIM5->CCR3/TIM5->ARR);OLED_Show_int(60,4,task3freq);
		if(task3freq>9500)//范围是500-9500Hz
			task3freq=500;
		task3freq=task3freq+500;//频率调整，执行一次加500Hz
		printf("task3ferq:%d\n",task3freq);printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);printf("task3duty_change:%f\n\n",task3duty_change);
		task3duty_flag=0;//获取过占空比后就不再改变目标占空比task3duty_change的值
		while(keyflag==0){HAL_Delay(1);}//按下按键返回上一级
		break;
	case 4:/********输入捕获检测占空比和频率并显示出来********/
		OLED_Clear();
		OLED_Show_float(0,0,duty);
		OLED_Show_float(60,0,freq);	
	while(keyflag==0){HAL_Delay(1);}//按下按键返回上一级
	break;
	case 5:/********检测输入频率倍频输出******/
		OLED_Clear();
		printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);
		TIM5->ARR=(int)(1000000.0/(freq*3))-1;//3倍频
		TIM5->CCR3=(int)(duty*(float)TIM5->ARR);OLED_Show_float(60,2,duty);OLED_Show_float(60,4,freq);//OLED_Show_int(60,2,TIM5->CCR3);OLED_Show_int(60,4,TIM5->ARR);
	while(keyflag==0){HAL_Delay(1);}//按下按键返回上一级
	break;
	case 6:/********测距*******/
		OLED_Clear();
		while(keyflag==0)//按下按键返回上一级
		{
			Trig();
		HAL_Delay(10);
		//printf("Duty:%.2f,freq:%.2f\r\n",duty,freq);
			OLED_Clear();
			OLED_ShowCHinese(0,0,29);OLED_ShowCHinese(16,0,30);OLED_ShowCHinese(32,0,31);
		OLED_Show_float(48,0,pulseWidth*34000/2);OLED_ShowString(80,0,"cm");
		//printf("%.2fcm\r\n",pulseWidth*34000/2);
			if(pulseWidth*34000/2>25)
			{	
				TIM4->CCR3=0;TIM1->CCR1=999;TIM4->CCR4=999;
				
//			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);//关
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);
	//		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
//			HAL_Delay(100);
//			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
//			HAL_Delay(100);
//			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
//			HAL_Delay(100);
//			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
//			HAL_Delay(100);
//			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
			HAL_Delay(200);
//			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);
				HAL_Delay(800);
			}
			if(15<pulseWidth*34000/2&&pulseWidth*34000/2<25)
			{TIM4->CCR3=999;TIM1->CCR1=0;TIM4->CCR4=999;
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);HAL_Delay(200);
		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);HAL_Delay(300);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);HAL_Delay(200);
		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);HAL_Delay(300);}
			if(pulseWidth*34000/2<15)
			{TIM4->CCR3=999;TIM1->CCR1=999;TIM4->CCR4=0;
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);HAL_Delay(100);
		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);HAL_Delay(150);
			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);HAL_Delay(100);
		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);HAL_Delay(150);}
			TIM4->CCR3=999;TIM1->CCR1=999;TIM4->CCR4=999;
		}
		break;
	case 7:/******显示文本******/
		OLED_Clear();
		OLED_ShowCHinese(0,0,0);OLED_ShowCHinese(16,0,1);OLED_ShowCHinese(32,0,2);OLED_ShowCHinese(48,0,3);OLED_ShowCHinese(64,0,4);OLED_ShowCHinese(80,0,5);OLED_ShowCHinese(96,0,6);OLED_ShowCHinese(112,0,7);OLED_ShowCHinese(0,2,8);OLED_ShowCHinese(16,2,9);
		if(taskflag1==0)
			second=0;
		taskflag1=1;
		
while(keyflag==0){
	m=second/60000;s=(second/1000)%60;//分和秒的设置
	OLED_Show_int(0,6,(int)m);OLED_ShowCHinese(16,6,27);OLED_Show_int(32,6,(int)s);OLED_ShowCHinese(48,6,28);
}//按下按键返回上一级
		break;
	case 8:/******GPIO********/
		OLED_Clear();
		while(keyflag3==0){
		TIM4->CCR3=999;TIM1->CCR1=999;/*b*/TIM4->CCR4=0;/*r*/HAL_Delay(1000);TIM4->CCR4=999;
		TIM4->CCR3=0;HAL_Delay(1000);TIM4->CCR3=999;
		TIM1->CCR1=0;HAL_Delay(1000);
			TIM4->CCR3=0;TIM4->CCR4=0;HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);
			HAL_Delay(250);HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);HAL_Delay(250);HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);HAL_Delay(250);HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);HAL_Delay(250);
			
		}
HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
		TIM4->CCR3=999;TIM1->CCR1=999;TIM4->CCR4=999;
		for(int g=0;g<3;g++){
			for(int i=999;i>0;i--)
			{TIM4->CCR3=i;
			HAL_Delay(6);}
			for(int i=0;i<999;i++)
			{TIM4->CCR3=i;
			HAL_Delay(6);}
			
		}
		
		
		
		
		break;
			
			
			
}
		//HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);

		
		OLED_Clear();//模块程序执行完毕清屏
		//OLED_ShowCHinese(0,6,24);OLED_ShowCHinese(16,6,25);OLED_ShowCHinese(32,6,26);//显示主菜单
		OLED_ShowCHinese(0,0,32);OLED_ShowCHinese(16,0,33);OLED_ShowCHinese(32,0,34);OLED_ShowCHinese(48,0,31);//显示
		keyflag=0;//使下一次按键操作可以正常通过回退键返回
keyflag2=0;
keyflag3=0;
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);//检测程序用
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 84;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)//定时器更新溢出中断回调函数
{
	if(htim==&htim4)
		{
			second++;//printf("%d\n",second/1000);
			//OLED_Show_float(0,4,second/1000.0);
		}
}
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)//定时器输入捕获中断回调函数
	{
		if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1&&htim->Instance==htim2.Instance)
		{
			freq= 84000000*1.0f/(TIM2->CCR1+1);
			duty=(float)(TIM2->CCR2+1)/(TIM2->CCR1+1);
			pulseWidth=(float)TIM2->CCR2/84000000*1.0f;
		}
	}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)//串口接收完成中断回调函数
	{ 
		if(huart == &huart1) 
		{
			HAL_UART_Transmit_IT(&huart1,RxBuffer,3);
			if(RxBuffer[0]=='1')
				HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
			HAL_UART_Receive_DMA(&huart1,RxBuffer, 50);//循环使能，才能不断接收
		} 
	}
	void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)//串口事件扩展回调函数
	{
		if(huart==&huart1)
		{
			//HAL_UART_Transmit_IT(&huart1,RxBuffer,Size);
			
			for(int i=0;i<Size;i++)
			{
				if(RxBuffer[i]==0x3E)
				{
					HAL_UART_Transmit(&huart1,&DATA[0],sizeof(DATA[0]),100);
					if(RxBuffer[i+1]==0x01)
					{	
						HAL_UART_Transmit(&huart1,&DATA[1],sizeof(DATA[1]),100);
						switch(RxBuffer[i+2])
						{
							case 0x0A:uart_task_flag1=1;break;
							case 0x0B:uart_task_flag1=2;break;
							case 0x0C:uart_task_flag1=3;break;
						};
						if(uart_task_flag1==3)
						{
							HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
							HAL_Delay(RxBuffer[i+3]*1000);
							HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8);
						}
						if(uart_task_flag1==2)
						{
							HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0);
							HAL_Delay(RxBuffer[i+3]*1000);
							HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_8);
						}
						if(uart_task_flag1==1)
						{
							HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);
							HAL_Delay(RxBuffer[i+3]*1000);
							HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_14);
						}
				//HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
					}
				}
			}
			//HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
			HAL_UARTEx_ReceiveToIdle_DMA(&huart1,RxBuffer, 50);//直接内存访问下串口接收闲时开启
			__HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT);//关闭dma传输过半中断
		}
	}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
