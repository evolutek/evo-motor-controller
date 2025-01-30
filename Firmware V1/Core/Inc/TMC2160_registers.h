/*
 * TMC2160_registers.h
 *
 *  Created on: Jan 30, 2025
 *      Author: Dany
 */

#ifndef INC_TMC2160_REGISTERS_H_
#define INC_TMC2160_REGISTERS_H_

typedef enum TMC_registers_e { // section 5.1
	// GENERAL CONFIGURATION REGISTERS (0X00…0X0F)
	gconf = 0x00,
	gstat = 0x01,

	ioin = 0x04,

	//otp_prog = 0x06,
	//otp_read = 0x07, // using those is not recommended
	factory_conf = 0x08,
	short_conf = 0x09,

	drv_conf = 0x0A,
	global_scaler = 0x0B,
	offset_read = 0x0C,

	// VELOCITY DEPENDENT DRIVER FEATURE CONTROL REGISTER SET (0X10…0X1F)
	ihold_irun = 0x10,
	tpowerdown = 0x11,
	tstep = 0x12,
	tpwmthrs = 0x13,
	tcoolthrs = 0x14,
	thigh = 0x15,

	xdirect = 0x2D,

	vcdmin = 0x33,

	// MICROSTEPPING CONTROL REGISTER SET (0X60…0X6B)
	mslut = 0x60,
	// todo : wtf is mslut [1...7] ?
	mslutsel = 0x68,
	mslutstart = 0x69,
	mscnt = 0x6A,
	mscuract = 0x6B,
	chopconf = 0x6C,
	coolconf = 0x6D,
	dcctrl = 0x6E,
	drv_status = 0x6F,
	pwmconf = 0x70,
	pwm_scale = 0x71,
	pwm_auto = 0x72,
	lost_steps = 0x73,
} TMC_registers_t;

#endif /* INC_TMC2160_REGISTERS_H_ */
