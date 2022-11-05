/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#include "button.h"
int Key1Reg0=NORMAL_STATE;
int Key1Reg1=NORMAL_STATE;
int Key1Reg2=NORMAL_STATE;
int Key1Reg3=NORMAL_STATE;

int Key2Reg0=NORMAL_STATE;
int Key2Reg1=NORMAL_STATE;
int Key2Reg2=NORMAL_STATE;
int Key2Reg3=NORMAL_STATE;

int Key3Reg0=NORMAL_STATE;
int Key3Reg1=NORMAL_STATE;
int Key3Reg2=NORMAL_STATE;
int Key3Reg3=NORMAL_STATE;


int TimeOutForKey1Press= 300;
int TimeOutForKey2Press= 300;
int TimeOutForKey3Press= 300;

int lock2=0;
int lock3=0;

int button1_flag=0;
int button2_flag=0;
int button3_flag=0;

int isButtonRESPressed(){
	if(button1_flag==1){
		button1_flag=0;
		return 1;
	}
	return 0;
}
void subKeyProcces1(){
	button1_flag=1;
}

void getKeyInput1(){
	Key1Reg0=Key1Reg1;
	Key1Reg1=Key1Reg2;
	Key1Reg2=HAL_GPIO_ReadPin(BUT_RESET_GPIO_Port,BUT_RESET_Pin);
	if((Key1Reg0==Key1Reg1)&&(Key1Reg1==Key1Reg2)){
		if(Key1Reg2!=Key1Reg3){
			Key1Reg3=Key1Reg2;

			if(Key1Reg2==PRESSED_STATE){
				TimeOutForKey1Press=100;
				subKeyProcces1();
			}
		}
		else{
			TimeOutForKey1Press--;
			if(TimeOutForKey1Press==0){
				Key1Reg3=NORMAL_STATE;
			}
		}
	}

}
int isButtonINCPressed(){
	if(button2_flag==1){
		button2_flag=0;
		return 1;
	}
	return 0;
}
void subKeyProcces2(){
	button2_flag=1;
}

void getKeyInput2(){
	Key2Reg0=Key2Reg1;
	Key2Reg1=Key2Reg2;
	Key2Reg2=HAL_GPIO_ReadPin(BUT_INC_GPIO_Port, BUT_INC_Pin);
	if((Key2Reg0==Key2Reg1)&&(Key2Reg1==Key2Reg2)){
		if(Key2Reg2!=Key2Reg3){
			Key2Reg3=Key2Reg2;

			if(Key2Reg2==PRESSED_STATE){
				TimeOutForKey2Press=300;
				subKeyProcces2();
			}
		}
		else{
			TimeOutForKey2Press--;
			if(TimeOutForKey2Press==0){
				if(!HAL_GPIO_ReadPin(BUT_INC_GPIO_Port, BUT_INC_Pin)){
					TimeOutForKey2Press=100;
					subKeyProcces2();
				}
				else{
				Key2Reg3=NORMAL_STATE;
				}
			}
		}
	}

}
int isButtonDECPressed(){
	if(button3_flag==1){
		button3_flag=0;
		return 1;
	}
	return 0;
}
void subKeyProcces3(){
	button3_flag=1;
}

void getKeyInput3(){
	Key3Reg0=Key3Reg1;
	Key3Reg1=Key3Reg2;
	Key3Reg2=HAL_GPIO_ReadPin(BUT_DEC_GPIO_Port, BUT_DEC_Pin);
	if((Key3Reg0==Key3Reg1)&&(Key3Reg1==Key3Reg2)){
		if(Key3Reg2!=Key3Reg3){
			Key3Reg3=Key3Reg2;

			if(Key3Reg2==PRESSED_STATE){
				TimeOutForKey3Press=300;
				subKeyProcces3();
			}
		}
		else{
			TimeOutForKey3Press--;
			if(TimeOutForKey3Press==0){
				if(!HAL_GPIO_ReadPin(BUT_DEC_GPIO_Port, BUT_DEC_Pin)){
					TimeOutForKey3Press=100;
					subKeyProcces3();
				}
				else{
					Key3Reg3=NORMAL_STATE;
				}
			}
		}
	}

}
