/*
 * ch3_32.c
 *
 *  Created on: 15 maj 2019
 *      Author: Jarosław Królik
 */

#include "ch3_32.h"
#include "usbd_cdc_if.h"

#include <stdlib.h>	/* strtol */
#include <ctype.h>	/*tolower*/


//control function
uint8_t ch3_32_set_mode(uint32_t *mode);
uint8_t ch3_32_change_parametr(uint8_t *parameter, uint32_t *value);

//ch3_32 command
int8_t dec_num(uint8_t number);
int ch3_32_read_digits();
void ch3_32_clear_digits();

//USB command
uint32_t *read_parameter(uint8_t* Buf, uint32_t *Len, uint32_t *parameter);
void ch3_32_send_digits_USB(int digits, uint8_t clear_digits_after_send);

//timer funcion
void timer_start(void);
void timer_stop(void);
uint8_t timer_change_time(uint32_t *time);


TIM_HandleTypeDef *p_htim1;
int last_read_digits;
uint8_t ch3_32_mode;
uint8_t ch3_32_send_if_mesure_zero;
uint8_t ch3_32_clear_digits_after_send;

void ch3_32_Intit(TIM_HandleTypeDef *htim1){
	uint32_t set_mode = 4;
	ch3_32_set_mode(&set_mode);
	ch3_32_send_if_mesure_zero = 0;
	ch3_32_clear_digits_after_send = 0;
	last_read_digits = ch3_32_read_digits();

	p_htim1 = htim1;
	timer_start();
	//TIM1_Init();
}

uint8_t ch3_32_decode(uint8_t* Buf, uint32_t *Len){
	if (*Len < 4 || *Len > 13)
		return Status_ERROR;

	//convert command to lowercase
	char *temp = (char*)Buf;
	for(uint8_t i; i<4; i++){
		*temp = tolower(*temp);
		temp += 1;
	}

	static char command[5]; // 4 character + null-terminated string
	strncpy (command, (char*)Buf, 5);

	if( memcmp(command,"read",4) == 0 ){
		ch3_32_send_digits_USB( ch3_32_read_digits(), ch3_32_clear_digits_after_send );
		return Status_OK;
	}

	if( memcmp(command,"clear",5) == 0 ){
		ch3_32_clear_digits();
		return Status_OK;
	}

	//command with parameter
	uint32_t parameter;
	if( memcmp(command,"mode",4) == 0 ){
		return ch3_32_set_mode( read_parameter(Buf, Len, &parameter) );
	}

	if( memcmp(command,"time",4) == 0 ){
		return timer_change_time( read_parameter(Buf, Len, &parameter) );
	}

	if( memcmp(command,"reset",5) == 0 ){
		return ch3_32_change_parametr(&ch3_32_clear_digits_after_send, read_parameter(Buf, Len, &parameter) );
	}

	if( memcmp(command,"zero",4) == 0 ){
		return ch3_32_change_parametr(&ch3_32_send_if_mesure_zero, read_parameter(Buf, Len, &parameter) );
	}


	/*//find any of "\O\n\r", replace by '\O' and return poitner;
	strtok(parameter_start, "\n\r ");
	char* parameter_end = (char*) memchr (Buf, '\0', (uint32_t)Len);

	static char parametr_str[9];
	strncpy (parametr_str, parameter_start, parameter_end - parameter_start);*/

	/*if (*Len < 4)
		return;
	if( memcmp(command,"mode",4) == 0 ){

		return;
	}
	if( memcmp(command,"time",4) == 0 ){

		return;
	}*/

	//remove
	/*char *pch;
	pch=strchr(str,'s');
	else if (*Len == 4)
		TIM1_Start();
	else
		TIM1_Start();
	switch(Buf[0]){
	case 'c'*100 :
		TIM1_Start();
		break;
	case '2':
		TIM1_Stop();
		break;
	}*/
	return Status_ERROR;
}

void ch3_32_tic_timer(){
	uint32_t read_digits;
	switch(ch3_32_mode){
		case 1:
			return;
		case 2:
			ch3_32_send_digits_USB( ch3_32_read_digits(),ch3_32_clear_digits_after_send );
			return;
		case 3:
			read_digits = ch3_32_read_digits();
			if (last_read_digits == read_digits){
				ch3_32_send_digits_USB( read_digits, ch3_32_clear_digits_after_send );
			}
			else
				last_read_digits = read_digits;
			return;
		case 4:
			read_digits = ch3_32_read_digits();
			if (last_read_digits < read_digits)
				last_read_digits = read_digits;
			else if (last_read_digits == read_digits){
				if(ch3_32_clear_digits_after_send)
					ch3_32_clear_digits();
			}
			else if(last_read_digits > read_digits){
				ch3_32_send_digits_USB( last_read_digits, 0);
				last_read_digits = 0;
			}
	}
}

int8_t dec_num(uint8_t letter_number){
	int8_t number = -1;
	switch(letter_number){
		case 0: number = __dec_num_digit(A); break;
		case 1: number = __dec_num_digit(B); break;
		case 2: number = __dec_num_digit(C); break;
		case 3: number = __dec_num_digit(D); break;
		case 4: number = __dec_num_digit(E); break;
		case 5: number = __dec_num_digit(F); break;
		case 6: number = __dec_num_digit(G); break;
	}
	if(number>9)
		return -1;
	return number;
}

int ch3_32_read_digits(){
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

uint8_t ch3_32_set_mode(uint32_t *mode){
	if (*mode <1 || *mode >6)
		return Status_ERROR;
	ch3_32_mode = *mode;
	return Status_OK;
}

uint8_t ch3_32_change_parametr(uint8_t *parameter, uint32_t *value){
	if( *value == 0)
		*parameter = 0;
	else if( *value == 1)
		*parameter = 1;
	else
		return Status_ERROR;
	return Status_OK;
}

void ch3_32_send_digits_USB(int digits, uint8_t clear_digits_after_send){
	if(ch3_32_send_if_mesure_zero || digits){
		const uint8_t length = 15;
		char digits_str[length];
		sprintf(digits_str ,"num: %0*d \n\r", 7, digits);
		CDC_Transmit_FS((uint8_t*)digits_str,length);
		if(clear_digits_after_send)
			ch3_32_clear_digits();
	}
}

void ch3_32_clear_digits(){
	clear = 1;
}

uint32_t *read_parameter(uint8_t* Buf, uint32_t *Len, uint32_t *parameter){
	//find space
	char *parameter_start = (char*) memchr (Buf, ' ', (uint32_t)Len);
	if (parameter_start == NULL)
		return 0;
	parameter_start += 1;
	*parameter = (uint32_t)strtol(parameter_start,NULL,10);
	return parameter;
}

inline void timer_start(void){
	HAL_TIM_Base_Start_IT(p_htim1);
}
inline void timer_stop(void){
	HAL_TIM_Base_Stop_IT(p_htim1);
}

uint8_t timer_change_time(uint32_t *time){
	timer_stop();
	p_htim1->Instance->ARR = *time -1;
	timer_start();
	return Status_OK;
}
