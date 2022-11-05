/*
 * global.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "global.h"


void display7Seg(int num){
	switch(num){
	case 0:
		GPIOB->ODR = 0x0040;
		break;
	case 1:
		GPIOB->ODR = 0x0079;
		break;
	case 2:
		GPIOB->ODR = 0x00A4;
		break;
	case 3:
		GPIOB->ODR = 0x0030;
		break;
	case 4:
		GPIOB->ODR = 0x0019;
		break;
	case 5:
		GPIOB->ODR = 0x0012;
		break;
	case 6:
		GPIOB->ODR = 0x0002;
		break;
	case 7:
		GPIOB->ODR = 0x0078;
		break;
	case 8:
		GPIOB->ODR = 0x0000;
		break;
	case 9:
		GPIOB->ODR = 0x0010;
		break;
	default:
		break;

	}
}
