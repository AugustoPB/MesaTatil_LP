<<<<<<< HEAD
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
=======
#include "MesaTatilDef.h"
pinout tablePinout[35] = 
{
{GPIOA,0} ,{GPIOA,1} ,{GPIOA,4} ,{GPIOA,6} ,{GPIOA,7} ,{GPIOA,8} ,{GPIOA,9},
{GPIOA,10},{GPIOA,11},{GPIOA,12},{GPIOA,15},{GPIOB,0} ,{GPIOB,1} ,{GPIOB,2},
{GPIOB,3} ,{GPIOB,4} ,{GPIOB,5} ,{GPIOB,6} ,{GPIOB,7} ,{GPIOB,8} ,{GPIOB,9},
{GPIOB,10},{GPIOB,11},{GPIOB,12},{GPIOB,13},{GPIOB,14},{GPIOB,15},{GPIOC,0},
{GPIOC,1} ,{GPIOC,2} ,{GPIOC,3} ,{GPIOC,4} ,{GPIOC,5} ,{GPIOC,6} ,{GPIOC,7}
};

long int mesaTatil_MatrixConversion(int *data)
{
	int i;
	long int converted = 0;
	for(i=0; i < NUM_PINS ; i++){
		converted += (*data++<<i);}
	return converted;
}

void mesaTatil_update(long int data)
{
	for(int i=0; tablePinout[i].GPIOx; i++)
		tablePinout[i].GPIOx->BSRR = (data&(1<<i))?(1<<tablePinout[i].GPIO_Pin):(1<<(tablePinout[i].GPIO_Pin+16));
}

void mesaTatil_updateFromMatrix(int *data){
	long int inteiro;
	inteiro = mesaTatil_MatrixConversion(data);
	mesaTatil_update(inteiro);
}
	
void mesaTatil_WritePin(int line, int column, int state)
{
	tablePinout[((line-1)*7)+(column-1)].GPIOx->BSRR = (state<<tablePinout[((line-1)*7)+(column-1)].GPIO_Pin);
}
>>>>>>> b757ac70ac68c0dee977f6f7c73fa57caeabeca8
