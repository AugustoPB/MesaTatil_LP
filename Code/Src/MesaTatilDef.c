#include "MesaTatilDef.h"

long int mesaTatil_MatrixConversion(int *data)
{
	long int converted;
	for(int i=0; *data; i++)
		converted += (*data++<<i);
	return converted;
}

void mesaTatil_update(long int data)
{
	for(int i=0; tablePinout[i].GPIOx; i++)
		tablePinout[i].GPIOx->BSRR = (data&(1<<i))?(1<<tablePinout[i].GPIO_Pin):(1<<(tablePinout[i].GPIO_Pin+16));
}

void mesaTatil_WritePin(int line, int column, int state)
{
	tablePinout[((line-1)*7)+(column-1)].GPIOx->BSRR = (state<<tablePinout[((line-1)*7)+(column-1)].GPIO_Pin);
}
