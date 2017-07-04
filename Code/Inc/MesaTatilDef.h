#include "stm32f0xx.h"                  // Device header
#include "stm32f0xx_hal.h"
#include "gpio.h"

// Pinout struct definition
typedef struct pinout
{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}pinout;

// Vector definition of output pins, must be in ascending order
pinout tablePinout[35] = 
{
{GPIOA,0} ,{GPIOA,1} ,{GPIOA,4} ,{GPIOA,6} ,{GPIOA,7} ,{GPIOA,8} ,{GPIOA,9},
{GPIOA,10},{GPIOA,11},{GPIOA,12},{GPIOA,15},{GPIOB,0} ,{GPIOB,1} ,{GPIOB,2},
{GPIOB,3} ,{GPIOB,4} ,{GPIOB,5} ,{GPIOB,6} ,{GPIOB,7} ,{GPIOB,8} ,{GPIOB,9},
{GPIOB,10},{GPIOB,11},{GPIOB,12},{GPIOB,13},{GPIOB,14},{GPIOB,15},{GPIOC,0},
{GPIOC,1} ,{GPIOC,2} ,{GPIOC,3} ,{GPIOC,4} ,{GPIOC,5} ,{GPIOC,6} ,{GPIOC,7}
};
	