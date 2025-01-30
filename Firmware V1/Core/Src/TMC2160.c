#include "TMC2160.h"
#include "TMC2160_registers.h"

#include "stm32g4xx_hal.h"

#include <stdio.h>

#define SPI_TIMEOUT HAL_MAX_DELAY

typedef struct __attribute__((packed)) tmc_write_s {
	uint8_t dir : 1; // read 0, write 1
	uint8_t addr : 7;
	uint32_t data;
} tmc_write_t;

typedef struct __attribute__((packed)) tmc_read_s {
	uint8_t unused : 4;
	uint8_t standstill : 1;
	uint8_t sg2 : 1;
	uint8_t driver_error : 1;
	uint8_t reset_flag : 1;
	uint32_t data;
} tmc_read_t;

#define DATAGRAM_SIZE 5


// ============================ Hardware Abstraction ============================ //

static inline void _unfree(TMC2160_t* tmc){
	HAL_GPIO_WritePin(tmc->NEN_Port, tmc->NEN_Pin, 0);
}

static inline void _free(TMC2160_t* tmc){
	HAL_GPIO_WritePin(tmc->NEN_Port, tmc->NEN_Pin, 1);
}

static inline void _enable(TMC2160_t* tmc){
	HAL_GPIO_WritePin(tmc->NCS_Port, tmc->NCS_Pin, 0);
}

static inline void _disable(TMC2160_t* tmc){
	HAL_GPIO_WritePin(tmc->NCS_Port, tmc->NCS_Pin, 1);
}

static uint32_t _read(TMC2160_t* tmc, TMC_registers_t reg){
	tmc_write_t w_data = {
		.dir = 0,
		.addr = (uint8_t)reg,
	};

	tmc_read_t r_data = {0};

	_enable(tmc);
	HAL_SPI_Transmit(tmc->spi_handle, (uint8_t*)(&w_data), DATAGRAM_SIZE, SPI_TIMEOUT);
	HAL_SPI_Receive(tmc->spi_handle, (uint8_t*)(&r_data), DATAGRAM_SIZE, SPI_TIMEOUT);
	_disable(tmc);

	printf("%d %d\n",sizeof(tmc_read_t),sizeof(tmc_write_t));
	printf("%ld %d %d %d %d %d\n",r_data.data, r_data.driver_error, r_data.reset_flag, r_data.sg2, r_data.standstill, r_data.unused);

	return r_data.data;
}

static void _write(TMC2160_t* tmc, TMC_registers_t reg, uint32_t val){
	tmc_write_t datagram = {
		.dir = 1,
		.addr = (uint8_t)reg,
		.data = val,
	};

	_enable(tmc);
	HAL_SPI_Transmit(tmc->spi_handle, (uint8_t*)(&datagram), DATAGRAM_SIZE, SPI_TIMEOUT);
	_disable(tmc);
}

// ============================ Low Level ============================ //


void tmcInit(TMC2160_t* tmc){
	_free(tmc);

	uint32_t val32 = _read(tmc, ioin);
	uint8_t val8[4];

	*((uint32_t*)val8) = val32;

	printf("%X %X %X %X\n",val8[3],val8[2],val8[1],val8[0]);

	_read(tmc, ioin);
}
