/*
 * music.c
 *
 *  Created on: Oct 28, 2023
 *      Author: 闫秀涛
 */
#include "music.h"
#include "tim.h"
#define GPIO_PORT GPIOA
#define GPIO_PIN GPIO_PIN_6
#define GPIO_PORT1 GPIOA
#define GPIO_PIN1 GPIO_PIN_6
//void led()
//{
//GPIO_InitTypeDef GPIO_InitStruct = {0};
//GPIO_InitStruct.Pin = GPIO_PIN_15;
//GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//	GPIO_InitStruct.Pull = GPIO_PULLUP;
//	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
////	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0)
////		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
////	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
//}
/*
void beepset(uint16_t x,uint16_t y){
	__HAL_TIM_SET_AUTORELOAD(&htim4,x);
	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,y);

}

const uint16_t tone[22]={0,3817,3401,3030,2865,2551,2272,2024,
						1912,1703,1517,1432,1275,1136,1012,
						956,851,758,715,637,568,506};

//---------------------------------------------------起风了------------------------------

const uint8_t music_tone1[]={7,8,9,10,3,12,10,10,0,0,7,8,9,10,2,12,10,9,10,8,9,7,8,5,0,7,8,9,10,3,12,10,10,0,0,7,8,9,10,2,12,10,9,10,8,9,7,8,5,0,5,5,6,6,6,6,10,10,5,5,6,6};
const uint8_t music_tone2[]={2,1,2,1,2,3,5,3,2,1,2,1,2,3,2,1,2,0,2,1,2,1,2,3,5,3,2,3,2,1,2,2,0,2,1,2,1,2,3,5,3,2,3,2,1,6,6,0,2,1,2,1,2,3,5,3,2,3,2,3,2
		,1,6,6,0,3,2,1,2,1,0,3,2,1,2,1,0,3,2,1,2,1,0}; //这一路上走走停停~
const uint8_t music_tone3[]={1,2,3,1,6,5,6,6,0,1,7,6,7,7,0,7,6,7,7,3,3,8,9,8,7,6,5,6,5,6,6,5,6,5,6,5,2,2,5,3,0,1,2,3,1,6,5,6,6,0,1,7,6,7,7
		,0,7,6,7,7,3,3,8,9,8,7,6,5,6,10,10,10,5,6,10,10,10,5,6,10,10,10,5,6,6,6,0};  //从前初识这时间
const uint8_t music_tone4[]={8,9,10,13,12,12,13,12,12,13,12,12,9,10,10,13,12,12,13,12,12,13,12,12,10,9,8,6,6,8,8,9,8,6,6,8,10,10,11,10,9,10,9,0,8,9,10,13,12,12,13,12,12,13,12,12,9,10,13,12,12,13,12,12,13,12,12,10,9,8,6,6,10,9,8,6,6,6
		,8,8,8,8};      //我曾难自拔与世界之大
const uint8_t music_tone_end[]={6,10,9,8,6,6,10,9,9,8,6,6,8,8,8,5,8,9,10,10,5,12,10,10,10,7,8,9,10,10,3,12,10,10,10,12,9,9,9,8,6,8,8,3,4};
const uint8_t music_time1[]={1,1,1,1,2,1,1,2,2,4,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,2,2,4,1,1,1,1,2,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t music_time2[]={3,1,3,1,2,2,2,2,3,1,3,1,1,1,1,1,2,2,3,1,3,1,2,2,2,2,3,1,2,1,1,4,4,3,1,3,1,2,2,2,2,3,1,2,1,1,2,2,1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,4,4};
const uint8_t music_time3[]={2,2,2,2,2,1,1,2,1,1,2,1,1,2,2,2,1,1,2,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,2,1,1,1,3,4,4,2,2,2,2,2,1,1,2,1,1,2,1,1,2,2,2,1,1,2,1,1,1,1,1,1,2,2,2,1,1,2,2,2,1,1,2,1,2,2,2,2};
const uint8_t music_time4[]={2,2,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,2,1,1,1,3,2,1,1,1,2,1,2,1,1,2,2,4,1,1,1,1,1,1,2,2,2,2,1,1,2,1,1,2,1,1,2,2,2,1,1,2,1,1,2,1,1,1,3,2,1,1,1,3,2,1,1,1,1,2,1,1,1};
const uint8_t music_time_end[]={1,2,2,1,1,1,2,1,1,1,2,1,3,4,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,3,2,1,1,1,1,1,1,2,4,2,2};//44
//----------------------- 两只老虎-------------------
const uint8_t two_tigers_tone[]={8,9,10,8,8,9,10,8,10,11,12,10,11,12,12,13,12,11,10,8,12,13,12,11,10,8,8,5,8,8,5,8};
const uint8_t two_tigers_time[]={4,4,4,4,4,4,4,4,4,4,8,4,4,8,2,2,2,2,4,4,2,2,2,2,4,4,4,4,8,4,4,8};
//-------------------------------夜空中最亮的星------------------------------
const uint8_t star_tone1[]={8,10,10,8,10,10,8,10,10,8,10,10,8,10,10,8,10,10,8,10,10,8,10,10,8,10,10,8,10,10};//开头，词前部分
const uint8_t star_tone2[]={10,9,10,9,10,12,12,12,5,8,9,9,8,6,6,8,8,9,10,8,8,6,8,9,10,8,8,6,9,10,10};//1,3 夜空中最亮的星~
const uint8_t star_tone3[]={0,5,10,9,10,9,10,12,12,12,5,8,9,9,8,6,6,8,8,9,10,8,8,6,8,9,10,8,8,6,12,10,11,10,11};  //2,4 o 夜空中最亮的星~
const uint8_t star_tone4[]={12,12,17,16,15,15,15,15,13,12,19,20,20,20,8,8,9,10,12,12,12,8,10,12,12,8,9,0,15,15,15,15,13,12,19,20,20,20,8,8,9,10,12,5,12,10,9,9,12,17,17,16,16,15,15,15,13,12,19,20,20,20,8,8,9,10,12,12,12,8,8,9,9,0,15,15,15,13,19,20,20,20,8,9,10,12,12,10,9,8,8};//我祈祷
const uint8_t star_time1[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const uint8_t star_time2[]={2,2,2,2,2,2,4,8,2,6,2,4,2,2,8,2,2,2,2,2,4,2,2,2,2,2,4,2,6,2,6};
const uint8_t star_time3[]={2,2,2,2,2,2,2,2,4,8,2,6,2,4,2,2,8,2,2,2,2,2,4,2,2,2,2,2,4,2,6,2,4,2,2};
const uint8_t star_time4[]={6,2,2,4,4,4,2,2,2,2,2,4,2,2,2,2,2,2,4,2,4,4,8,4,2,2,2,2,2,2,2,4,2,2,2,2,2,2,4,2,2,4,2,6,2,2,2,2,4,4,2,2,2,2,2,4,2,2,2,2,2,2,4,2,2,2,2,2,8,4,2,2,6,2,2,4,2,4,2,2,2,4,4,2,2,2,8};
//----------------------生日快乐------------------
const uint8_t birthday_tone[]={12,12,13,12,15,14,12,12,13,12,16,15,12,12,19,17,15,14,13,18,18,17,15,16,15};
const uint8_t birthday_time[]={2,2,4,4,4,4,2,2,4,4,4,4,2,2,4,4,4,4,4,2,2,4,4,4,4};
//----------------童年---------------
const uint8_t childhood_tone1[]={10,12,12,12,10,13,13,14,13,13,13,12,15,15,15,15,13,15,13,12,0};
const uint8_t childhood_tone2[]={10,12,12,0,12,10,13,13,14,13,0,13,13,12,15,15,15,13,13,15,16,0};
const uint8_t childhood_tone3[]={19,19,0,19,19,0,19,19,17,16,15,15,15,13,13,15,13,15,16,16,16,0,16,16,15,17,16,16,0};
const uint8_t childhood_tone4[]={17,17,17,17,16,16,15,15,15,16,15,13,12,12,12,12,13,12,16,17,15,0};
const uint8_t childhood_time1[]={2,2,4,2,2,2,2,2,4,2,2,2,4,2,1,2,2,2,2,4,1};
const uint8_t childhood_time2[]={2,2,4,1,2,2,2,2,2,4,1,2,2,2,4,4,1,2,2,2,2,4,1};
const uint8_t childhood_time3[]={2,2,1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,4,1};
const uint8_t childhood_time4[]={2,4,1,2,2,2,4,2,4,2,2,2,2,2,2,4,2,2,2,2,2,4,1};
void play_childhood(){
uint8_t i;
	  uint16_t j;

			  for(i=0;i<21;i++)
			  {
				  beepset(tone[childhood_tone1[i]], tone[childhood_tone1[i]]/2);
				  HAL_Delay(childhood_time1[i]*100);
				  for (j=tone[childhood_tone1[i]]/2;j>tone[childhood_tone1[i]];j--){

				    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
				    			HAL_Delay(childhood_time1[i]*50/tone[childhood_tone1[i]]);
				    		}
				  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
			  }

			  for(i=0;i<23;i++)
				  {
					  beepset(tone[childhood_tone2[i]], tone[childhood_tone2[i]]/2);
					  HAL_Delay(childhood_time2[i]*100);
					  for (j=tone[childhood_tone2[i]]/2;j>tone[childhood_tone2[i]];j--){

					    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
					    			HAL_Delay(childhood_time2[i]*50/tone[childhood_tone2[i]]);
					    		}
					  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);}

				  for(i=0;i<30;i++)
				  {
					  beepset(tone[childhood_tone3[i]], tone[childhood_tone3[i]]/2);
					  HAL_Delay(childhood_time3[i]*100);
					  for (j=tone[childhood_tone3[i]]/2;j>tone[childhood_tone3[i]];j--){

					    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
					    			HAL_Delay(childhood_time3[i]*50/tone[childhood_tone3[i]]);
					    		}
					  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);  }
			
		for(i=0;i<23;i++)
	{
		beepset(tone[childhood_tone4[i]], tone[childhood_tone4[i]]/2);
				 HAL_Delay(childhood_time4[i]*100);
				  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
				  for (j=tone[childhood_tone4[i]]/2;j>tone[childhood_tone4[i]];j--){

				    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
				    			HAL_Delay(childhood_time4[i]*50/tone[childhood_tone4[i]]);
				    		}}

__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}	
	void play_birthday()
{	uint16_t j;
uint8_t i;
	for(i=0;i<25;i++)
  	{
  		beepset(tone[birthday_tone[i]], tone[birthday_tone[i]]/2);
  		HAL_Delay(birthday_time[i]*120);
  		for (j=tone[birthday_tone[i]]/2;j>tone[birthday_tone[i]];j--){

  			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
  			HAL_Delay(birthday_time[i]*50/tone[birthday_tone[i]]);
  		}
  	}
		HAL_Delay(50);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}	
	
	
	
	
void play_1()
{
	 beepset(tone[8], tone[8]/2);
	  HAL_Delay(200);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
void play_2()
{
	 beepset(tone[9], tone[9]/2);
	  HAL_Delay(200);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
void play_3()
{
	 beepset(tone[10], tone[10]/2);
	  HAL_Delay(200);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
void play_4()
{
	 beepset(tone[11], tone[11]/2);
	  HAL_Delay(200);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
void play_5()
{
	 beepset(tone[12], tone[12]/2);
	  HAL_Delay(200);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
void play_6()
{
	 beepset(tone[13], tone[13]/2);
	  HAL_Delay(200);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
void play_7()
{
	 beepset(tone[14], tone[14]/2);
	  HAL_Delay(200);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
	
	void start(){uint8_t i;
	for(i=8;i<15;i++)
{
	  beepset(tone[i], tone[i]/2);
	  HAL_Delay(150);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
}
void play_star()
{uint8_t i;

//for(i=0;i<49;i++)
//{
//	  beepset(tone[star_tone1[i]], tone[star_tone1[i]]/2);
//	  HAL_Delay(star_time1[i]*200);
//	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
//}
for(i=0;i<35;i++)
{
	  beepset(tone[star_tone2[i]], tone[star_tone2[i]]/2);
	  HAL_Delay(star_time2[i]*150);
	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
}
for(i=0;i<40;i++)
{
	  beepset(tone[star_tone3[i]], tone[star_tone3[i]]/2);

	  HAL_Delay(star_time3[i]*150);

	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
}
for(i=0;i<87;i++)
{
	  beepset(tone[star_tone4[i]], tone[star_tone4[i]]/2);

	  HAL_Delay(star_time4[i]*150);

	  HAL_GPIO_TogglePin(GPIO_PORT, GPIO_PIN);
}

}
void play_qifengle()
{
	// int n=25;
	  uint8_t i;
	  uint16_t j;

			  for(i=0;i<62;i++)
			  {
				  beepset(tone[music_tone1[i]], tone[music_tone1[i]]/2);
				  HAL_Delay(music_time1[i]*150);
				  for (j=tone[music_tone1[i]]/2;j>tone[music_tone1[i]];j--){

				    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
				    			HAL_Delay(music_time1[i]*50/tone[music_tone1[i]]);
				    		}
				  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
			  }

			  for(i=0;i<65;i++)
				  {
					  beepset(tone[music_tone2[i]], tone[music_tone2[i]]/2);
					  HAL_Delay(music_time2[i]*180);
					  for (j=tone[music_tone2[i]]/2;j>tone[music_tone2[i]];j--){

					    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
					    			HAL_Delay(music_time2[i]*50/tone[music_tone2[i]]);
					    		}
					  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);}

				  for(i=0;i<82;i++)
				  {
					  beepset(tone[music_tone3[i]], tone[music_tone3[i]]/2);
					  HAL_Delay(music_time3[i]*200);
					  for (j=tone[music_tone3[i]]/2;j>tone[music_tone3[i]];j--){

					    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
					    			HAL_Delay(music_time3[i]*50/tone[music_tone3[i]]);
					    		}
					  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);  }
			//	n=0;
		for(i=0;i<82;i++)
	{
		beepset(tone[music_tone4[i]], tone[music_tone4[i]]/2);
				 HAL_Delay(music_time4[i]*180);
				  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
				  for (j=tone[music_tone4[i]]/2;j>tone[music_tone4[i]];j--){

				    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
				    			HAL_Delay(music_time4[i]*50/tone[music_tone4[i]]);
				    		}}
				  for(i=0;i<44;i++)
			 {
			  beepset(tone[music_tone_end[i]], tone[music_tone_end[i]]/2);
					  HAL_Delay(music_time_end[i]*200);
					  for (j=tone[music_tone_end[i]]/2;j>tone[music_tone_end[i]];j--){

					    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
					    			HAL_Delay(music_time_end[i]*50/tone[music_tone_end[i]]);
					    		}
					  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1); }
				  for(i=0;i<65;i++)
					  {
						  beepset(tone[music_tone2[i]], tone[music_tone2[i]]/2);
						  HAL_Delay(music_time2[i]*180);
						  for (j=tone[music_tone2[i]]/2;j>tone[music_tone2[i]];j--){

						    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
						    			HAL_Delay(music_time2[i]*50/tone[music_tone2[i]]);
						    		}
						  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);}
					for(i=0;i<82;i++)
				{
					beepset(tone[music_tone4[i]], tone[music_tone4[i]]/2);
							 HAL_Delay(music_time4[i]*200);
							  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
							  for (j=tone[music_tone4[i]]/2;j>tone[music_tone4[i]];j--){

							    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
							    			HAL_Delay(music_time4[i]*50/tone[music_tone4[i]]);
							    		}}
					for(i=0;i<82;i++)
				{
					beepset(tone[music_tone4[i]], tone[music_tone4[i]]/2);
							 HAL_Delay(music_time4[i]*200);
							  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
							  for (j=tone[music_tone4[i]]/2;j>tone[music_tone4[i]];j--){

							    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
							    			HAL_Delay(music_time4[i]*50/tone[music_tone4[i]]);
							    		}}
					for(i=0;i<82;i++)
				{
					beepset(tone[music_tone4[i]], tone[music_tone4[i]]/2);
							 HAL_Delay(music_time4[i]*200);
							  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
							  for (j=tone[music_tone4[i]]/2;j>tone[music_tone4[i]];j--){

							    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
							    			HAL_Delay(music_time4[i]*50/tone[music_tone4[i]]);
							    		}}
					for(i=0;i<82;i++)
				{
					beepset(tone[music_tone4[i]], tone[music_tone4[i]]/2);
							 HAL_Delay(music_time4[i]*200);
							  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1);
							  for (j=tone[music_tone4[i]]/2;j>tone[music_tone4[i]];j--){

							    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
							    			HAL_Delay(music_time4[i]*50/tone[music_tone4[i]]);
							    		}}
					for(i=0;i<44;i++)
								 {
								  beepset(tone[music_tone_end[i]], tone[music_tone_end[i]]/2);
										  HAL_Delay(music_time_end[i]*200);
										  for (j=tone[music_tone_end[i]]/2;j>tone[music_tone_end[i]];j--){

										    			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
										    			HAL_Delay(music_time_end[i]*50/tone[music_tone_end[i]]);
										    		}
										  HAL_GPIO_TogglePin(GPIO_PORT1, GPIO_PIN1); }
								 __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
void play_tigger()
{	uint16_t j;
uint8_t i;
	for(i=0;i<32;i++)
  	{
  		beepset(tone[two_tigers_tone[i]], tone[two_tigers_tone[i]]/2);
  		HAL_Delay(two_tigers_time[i]*100);
  		for (j=tone[two_tigers_tone[i]]/2;j>tone[two_tigers_tone[i]];j--){

  			__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,j);
  			HAL_Delay(two_tigers_time[i]*50/tone[two_tigers_tone[i]]);
  		}
  	}
		__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,0);
}
*/