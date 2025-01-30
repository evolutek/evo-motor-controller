#ifndef INC_TMC2160_H_
#define INC_TMC2160_H_

#include "stm32g4xx_hal.h"

typedef struct TMC2160_s {
	SPI_HandleTypeDef* spi_handle;

	GPIO_TypeDef *NCS_Port;
	uint16_t NCS_Pin;

	GPIO_TypeDef *NEN_Port;
	uint16_t NEN_Pin;
} TMC2160_t;


void tmcInit(TMC2160_t* tmc);

#endif /* INC_TMC2160_H_ */
