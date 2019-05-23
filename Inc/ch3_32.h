/*
 * ch3_32.h
 *
 *  Created on: 15 maj 2019
 *      Author: Jarosław Królik
 */

#ifndef CH3_32_H_
#define CH3_32_H_

#include "stm32f1xx_hal.h"

//	Return digital state of BCD_Pin
//	__BCD_pin_state(A,1) -> HAL_GPIO_ReadPin(BCD_A1_Pin)
#define __BCD_pin_state(letter, num) HAL_GPIO_ReadPin((BCD_ ## letter ## num ## _GPIO_Port), (BCD_ ## letter ## num ## _Pin))
//	Return digit of BCD_(letter)
//	__dec_num_letter(A) -> (BCD(A)->digit(A))
#define __dec_num_digit(letter) ((__BCD_pin_state(letter,3)<<3) + (__BCD_pin_state(letter,2)<<2) + (__BCD_pin_state(letter,1)<<1) + (__BCD_pin_state(letter,0)))

enum status{
	Status_OK,
	Status_ERROR
};

//templorary
uint8_t clear;

void ch3_32_Intit();
uint8_t ch3_32_decode(uint8_t* Buf, uint32_t *Len);
void ch3_32_tic_timer();

#endif /* CH3_32_H_ */
