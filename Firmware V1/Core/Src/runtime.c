#include "runtime.h"
#include "main.h"

#include "TMC2160.h"

TMC2160_t drv = {
	.spi_handle = &hspi1,
	.NCS_Port = N_CS_GPIO_Port,
	.NCS_Pin = N_CS_Pin,

	.NEN_Port = N_EN_GPIO_Port,
	.NEN_Pin = N_EN_Pin,
};

void setup(){
	tmcInit(&drv);
}


void loop(){
	HAL_Delay(1000);
	HAL_GPIO_TogglePin(STATUS_GPIO_Port, STATUS_Pin);
}
