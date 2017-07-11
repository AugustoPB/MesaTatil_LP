#include "MesaTatilDef.h"
pinout tablePinout[35] = 
{
{GPIOA,8} ,{GPIOB,14} ,{GPIOA,9} ,{GPIOC,7} ,{GPIOB,6} ,{GPIOB,2} ,{GPIOA,7},
{GPIOC,0},{GPIOC,3},{GPIOC,1},{GPIOC,2},{GPIOB,0} ,{GPIOB,15} ,{GPIOA,4},
{GPIOB,3} ,{GPIOB,5} ,{GPIOA,10} ,{GPIOB,4} ,{GPIOC,4} ,{GPIOB,10} ,{GPIOB,13},
{GPIOB,1},{GPIOA,1},{GPIOA,0},{GPIOA,12},{GPIOA,6},{GPIOC,5},{GPIOB,9},
{GPIOC,6} ,{GPIOB,8} ,{GPIOA,11} ,{GPIOB,12} ,{GPIOB,7} ,{GPIOB,11} ,{GPIOA,15}
};

long int mesaTatil_MatrixConversion(int *data)
{
	int i;
	long int converted = 0;
	for(i=0; i < NUM_PINS ; i++){
		converted += (*data++<<i);}
	return converted;
}

void mesaTatil_update(unsigned long int data)
{
	for(int i=0; tablePinout[i].GPIOx; i++)
		tablePinout[i].GPIOx->BSRR = (data&(1<<i))?(1<<tablePinout[i].GPIO_Pin):(1<<(tablePinout[i].GPIO_Pin+16));
}

void mesaTatil_updateFromMatrix(int *data){
	for(int i=0; tablePinout[i].GPIOx; i++)
		tablePinout[i].GPIOx->BSRR = (data[i])?(1<<tablePinout[i].GPIO_Pin):(1<<(tablePinout[i].GPIO_Pin+16));
}
	
void mesaTatil_WritePin(int line, int column, int state)
{
	tablePinout[((line-1)*7)+(column-1)].GPIOx->BSRR = (state<<tablePinout[((line-1)*7)+(column-1)].GPIO_Pin);
}
