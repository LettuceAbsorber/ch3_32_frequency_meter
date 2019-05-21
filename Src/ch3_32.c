/*
 * ch3_32.c
 *
 *  Created on: 15 maj 2019
 *      Author: Jarosław Królik
 */

#include "ch3_32.h"
#include "usbd_cdc_if.h"

int8_t dec_num(uint8_t number);
int  entire_num();


void ch3_32_send_digits(){
	const uint8_t length = 15;
	char digits[length];
	sprintf(digits ,"num: %0*d \n\r", 7, entire_num());
	//uint16_t len = sizeof(text)/sizeof(uint8_t);
	CDC_Transmit_FS((uint8_t*)digits,length);
}

void ch3_3d_decode(uint8_t* Buf, uint32_t *Len){
	switch(Buf[0]){
	case '1':
		TIM1_Start();
		break;
	case '2':
		TIM1_Stop();
		break;
	}

}

int8_t dec_num(uint8_t letter_number){
	int8_t number = -1;
	switch(letter_number){
		case 0: number = __dec_num_letter(A); break;
		case 1: number = __dec_num_letter(B); break;
		case 2: number = __dec_num_letter(C); break;
		case 3: number = __dec_num_letter(D); break;
		case 4: number = __dec_num_letter(E); break;
		case 5: number = __dec_num_letter(F); break;
		case 6: number = __dec_num_letter(G); break;
	}
	if(number>9)
		return -1;
	return number;
}

int entire_num(){
	int  number = 0;
	for(int8_t i=6; i>-1; i--){
		number *= 10;
		int8_t temp = dec_num(i);
		if(temp<0)
			return -1;
		number += (int)temp;
	}
	return number;
}
