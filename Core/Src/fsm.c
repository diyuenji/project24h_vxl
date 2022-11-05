/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "fsm.h"
int counter=0;
int status=0;

void fsm_buttons_run(){
	if(isButtonRESPressed()){
		counter=0;
		setTimer1(900);
	}
	if(isButtonDECPressed()){
			counter--;
			setTimer1(900);
	}
	if(isButtonINCPressed()){
		counter++;
		setTimer1(900);
	}
	if(counter>=10) counter=0;
	if(counter<0) counter=9;
	display7Seg(counter);
}

void fsm(){
	switch(status){
		case normal:
			if(timer1_flag==1){
				counter--;
				setTimer1(100);
			}
			if(isButtonRESPressed()){
				counter=0;
				setTimer1(900);
				status=setting;
			}
			if(isButtonDECPressed()){
				counter--;
				setTimer1(900);
				status=setting;
			}
			if(isButtonINCPressed()){
				counter++;
				setTimer1(900);
				status=setting;
			}
			display7Seg(counter);
			break;

		case setting:
			fsm_buttons_run();
			if(timer1_flag==1){
				status=normal;
				setTimer1(100);
			}

			break;
		default:
			break;
	}




}
