<<<<<<< HEAD
#ifndef MESATATILDEF_H
#define MESATATILDEF_H 
#include "stm32f0xx.h"                  // Device header
#include "stm32f0xx_hal.h"
#include "gpio.h"
#define NUM_PINS 35

// Pinout struct definition
typedef struct pinout
{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}pinout;

// Vector definition of output pins, must be in ascending order


void mesaTatil_update(unsigned long int data);
void mesaTatil_updateFromMatrix(int *data);
long int mesaTatil_MatrixConversion(int *data);
void mesaTatil_WritePin(int line, int column, int state);

#endif
=======
#ifndef MESATATILDEF_H
#define MESATATILDEF_H 
#include "stm32f0xx.h"                  // Device header
#include "stm32f0xx_hal.h"
#include "gpio.h"
#define NUM_PINS 35

// Pinout struct definition
typedef struct pinout
{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}pinout;

// Vector definition of output pins, must be in ascending order


void mesaTatil_update(long int data);
void mesaTatil_updateFromMatrix(int *data);
long int mesaTatil_MatrixConversion(int *data);
void mesaTatil_WritePin(int line, int column, int state);

#endif
>>>>>>> b757ac70ac68c0dee977f6f7c73fa57caeabeca8
