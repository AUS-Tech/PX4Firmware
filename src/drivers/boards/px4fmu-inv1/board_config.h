/****************************************************************************
 *
 *   Copyright (c) 2013, 2014 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file board_config.h
 *
 * PX4FMUv2 internal definitions
 */

#pragma once

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <px4_config.h>
#include <nuttx/compiler.h>
#include <stdint.h>

__BEGIN_DECLS

/* these headers are not C++ safe */
#include <stm32.h>
#include <arch/board/board.h>

#define UDID_START		0x1FFF7A10

/****************************************************************************************************
 * Definitions
 ****************************************************************************************************/
/* Configuration ************************************************************************************/


/* PX4FMU GPIOs ***********************************************************************************/
/* LEDs */

#define GPIO_LED1		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN10)
#define GPIO_LED2		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTC|GPIO_PIN5)

//#define GPIO_EX1		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN12)
//#define GPIO_EX2		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTB|GPIO_PIN12)
//#define GPIO_EX3		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTD|GPIO_PIN11)
#define GPS_DEFAULT_UART_PORT	"/dev/ttyS0"

/* External interrupts */
//#define GPIO_EXTI_GYRO_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTB|GPIO_PIN0)
//#define GPIO_EXTI_MAG_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTB|GPIO_PIN1)
//#define GPIO_EXTI_ACCEL_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTB|GPIO_PIN4)
//#define GPIO_EXTI_MPU_DRDY	(GPIO_INPUT|GPIO_FLOAT|GPIO_EXTI|GPIO_PORTD|GPIO_PIN15)

/* Data ready pins off */
//No Data Ready Pins used
//#define GPIO_GYRO_DRDY_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTB|GPIO_PIN0)
//#define GPIO_MAG_DRDY_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTB|GPIO_PIN1)
//#define GPIO_ACCEL_DRDY_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTB|GPIO_PIN4)
//#define GPIO_EXTI_MPU_DRDY_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_EXTI|GPIO_PORTD|GPIO_PIN15)

/* SPI1 off */
#define GPIO_SPI1_SCK_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_PORTA|GPIO_PIN5)
#define GPIO_SPI1_MISO_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_PORTA|GPIO_PIN6)
#define GPIO_SPI1_MOSI_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_PORTA|GPIO_PIN7)

/* SPI2 off */
#define GPIO_SPI2_SCK_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_PORTB|GPIO_PIN13)
#define GPIO_SPI2_MISO_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_PORTB|GPIO_PIN14)
#define GPIO_SPI2_MOSI_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_PORTB|GPIO_PIN15)

/* SPI1 chip selects off */
//#define GPIO_SPI_CS_GYRO_OFF		(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTC|GPIO_PIN13)
//#define GPIO_SPI_CS_ACCEL_MAG_OFF	(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTC|GPIO_PIN15)
#define GPIO_SPI_CS_BARO_OFF		(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTE|GPIO_PIN15)
#define GPIO_SPI_CS_MPU_OFF		(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTB|GPIO_PIN12)
#define GPIO_SPI_CS_LSM9DS1_AG_OFF		(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTD|GPIO_PIN11)
//#define GPIO_SPI_CS_LSM9DS0_XM_OFF		(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTA|GPIO_PIN8)
#define GPIO_SPI_CS_BMP280_OFF		(GPIO_INPUT|GPIO_PULLDOWN|GPIO_SPEED_2MHz|GPIO_PORTE|GPIO_PIN12)

/* SPI chip selects */
//#define GPIO_SPI_CS_GYRO	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN13)
//#define GPIO_SPI_CS_ACCEL_MAG	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN15)
#define GPIO_SPI_CS_BARO	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN15)
#define GPIO_SPI_CS_FRAM	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN4)
//#define GPIO_SPI_CS_HMC		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN1)
#define GPIO_SPI_CS_MPU		(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTB|GPIO_PIN12)
//#define GPIO_SPI_CS_EXT0	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTB|GPIO_PIN12)
//#define GPIO_SPI_CS_EXT1	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN14)
//#define GPIO_SPI_CS_EXT2	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN15)
//#define GPIO_SPI_CS_EXT3	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTC|GPIO_PIN13)
//#define GPIO_SPI_CS_LIS 	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN4)
#define GPIO_SPI_CS_LSM9DS1_AG (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTD|GPIO_PIN11)
//#define GPIO_SPI_CS_LSM9DS0_XM (GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_50MHz|GPIO_OUTPUT_SET|GPIO_PORTA|GPIO_PIN8)
#define GPIO_SPI_CS_BMP280	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN12)

#define PX4_SPI_BUS_SENSORS	2
#define PX4_SPI_BUS_RAMTRON	4
//#define PX4_SPI_BUS_EXT	2
#define PX4_SPI_BUS_BARO	PX4_SPI_BUS_SENSORS
#define PX4_SPI_BUS_LSM9DS1 PX4_SPI_BUS_SENSORS
#define PX4_SPI_BUS_BMP280 PX4_SPI_BUS_SENSORS

/* Use these in place of the spi_dev_e enumeration to select a specific SPI device on SPI1 */
//#define PX4_SPIDEV_GYRO		1
//#define PX4_SPIDEV_ACCEL_MAG	2
#define PX4_SPIDEV_BARO		3
#define PX4_SPIDEV_MPU		4
#define PX4_SPIDEV_FRAM		9
#define PX4_SPIDEV_LSM9DS1_AG	10
//#define PX4_SPIDEV_LSM9DS0_XM	11
//#define PX4_SPIDEV_HMC		5
//#define PX4_SPIDEV_LIS		7
//#define	PX4_SPIDEV_BMI		8
#define PX4_SPIDEV_BMP280		8

/* External bus */
#define PX4_SPIDEV_EXT0		1
//#define PX4_SPIDEV_EXT1		2
//#define PX4_SPIDEV_EXT2		3
//#define PX4_SPIDEV_EXT3		4

/* FMUv3 SPI on external bus */
//#define PX4_SPIDEV_EXT_MPU		PX4_SPIDEV_EXT0
//#define PX4_SPIDEV_EXT_BARO		PX4_SPIDEV_EXT1
//#define PX4_SPIDEV_EXT_ACCEL_MAG	PX4_SPIDEV_EXT2
//#define PX4_SPIDEV_EXT_GYRO		PX4_SPIDEV_EXT3

//#define PX4_SPIDEV_EXT_BMI		PX4_SPIDEV_EXT_GYRO

/* I2C busses */
#define PX4_I2C_BUS_EXPANSION	1
#define PX4_I2C_BUS_ONBOARD	2
#define PX4_I2C_BUS_LED		PX4_I2C_BUS_ONBOARD

/* Devices on the onboard bus.
 *
 * Note that these are unshifted addresses.
 */
#define PX4_I2C_OBDEV_LED	0x55
#define PX4_I2C_OBDEV_HMC5883	0x1e

/*
 * ADC channels
 *
 * These are the channel numbers of the ADCs of the microcontroller that can be used by the Px4 Firmware in the adc driver
 */
#define ADC_CHANNELS (1 << 2) | (1 << 3) | (1 << 10)

// ADC defines to be used in sensors.cpp to read from a particular channel
#define ADC_BATTERY_VOLTAGE_CHANNEL	2
#define ADC_BATTERY_CURRENT_CHANNEL	3
#define ADC_5V_RAIL_SENSE		10
#define ADC_AIRSPEED_VOLTAGE_CHANNEL	10

/* User GPIOs
 *
 * GPIO0-5 are the PWM servo outputs.
 */
#define GPIO_GPIO0_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN13) // Log comm 1
#define GPIO_GPIO1_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTC|GPIO_PIN14) // Log comm 2, used as fdb
#define GPIO_GPIO2_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN4)
#define GPIO_GPIO3_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN7) // Unused, but assigned cam_fdb in schematic
#define GPIO_GPIO4_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN12)
#define GPIO_GPIO5_INPUT	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTD|GPIO_PIN3)
#define GPIO_GPIO0_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTC|GPIO_PIN13)
#define GPIO_GPIO1_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTC|GPIO_PIN14)
#define GPIO_GPIO2_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTD|GPIO_PIN4) // Cam trig
#define GPIO_GPIO3_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN7)
#define GPIO_GPIO4_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN12) // Spare GPIO; Tim4Ch1
#define GPIO_GPIO5_OUTPUT	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTD|GPIO_PIN3) // Cam pow


/* Power supply control and monitoring GPIOs */
//#define GPIO_VDD_5V_PERIPH_EN	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTA|GPIO_PIN8)
//#define GPIO_VDD_BRICK_VALID	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTB|GPIO_PIN5)
//#define GPIO_VDD_SERVO_VALID	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTB|GPIO_PIN7)
//#define GPIO_VDD_3V3_SENSORS_EN	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN3)
//#define GPIO_VDD_5V_HIPOWER_OC	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN10)
//#define GPIO_VDD_5V_PERIPH_OC	(GPIO_INPUT|GPIO_PULLUP|GPIO_PORTE|GPIO_PIN15)

/* Tone alarm output */
#define TONE_ALARM_TIMER	4	/* timer 2 */
#define TONE_ALARM_CHANNEL	4	/* channel 1 */
#define GPIO_TONE_ALARM_IDLE	(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN15)
#define GPIO_TONE_ALARM		(GPIO_ALT|GPIO_AF2|GPIO_SPEED_2MHz|GPIO_PUSHPULL|GPIO_PORTD|GPIO_PIN15)

/* PWM
 *
 * Six PWM outputs are configured.
 *
 * Pins:
 *
 * CH1 : PE14 : TIM1_CH4
 * CH2 : PE13 : TIM1_CH3
 * CH3 : PE11 : TIM1_CH2
 * CH4 : PE9  : TIM1_CH1
 * CH5 : PD13 : TIM4_CH2
 * CH6 : PD14 : TIM4_CH3
 */
#define GPIO_TIM1_CH1OUT	(GPIO_ALT|GPIO_AF1|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN9)
#define GPIO_TIM1_CH2OUT	(GPIO_ALT|GPIO_AF1|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN11)
#define GPIO_TIM1_CH3OUT	(GPIO_ALT|GPIO_AF1|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN13)
#define GPIO_TIM1_CH4OUT	(GPIO_ALT|GPIO_AF1|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTE|GPIO_PIN14)
#define GPIO_TIM3_CH1OUT	(GPIO_ALT|GPIO_AF2|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN4)
#define GPIO_TIM3_CH2OUT	(GPIO_ALT|GPIO_AF2|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN5)
#define GPIO_TIM3_CH3OUT	(GPIO_ALT|GPIO_AF2|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN0)
#define GPIO_TIM3_CH4OUT	(GPIO_ALT|GPIO_AF2|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTB|GPIO_PIN1)

//#define GPIO_TIM4_CH2OUT	(GPIO_ALT|GPIO_AF2|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTD|GPIO_PIN13)
//#define GPIO_TIM4_CH3OUT	(GPIO_ALT|GPIO_AF2|GPIO_SPEED_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PUSHPULL|GPIO_PORTD|GPIO_PIN14)
#define DIRECT_PWM_OUTPUT_CHANNELS	8

#define GPIO_TIM1_CH1IN		GPIO_TIM1_CH1IN_2
#define GPIO_TIM1_CH2IN		GPIO_TIM1_CH2IN_2
#define GPIO_TIM1_CH3IN		GPIO_TIM1_CH3IN_2
#define GPIO_TIM1_CH4IN		GPIO_TIM1_CH4IN_2
#define GPIO_TIM3_CH1IN		GPIO_TIM3_CH1IN_3
#define GPIO_TIM3_CH2IN		GPIO_TIM3_CH2IN_3
#define GPIO_TIM3_CH3IN		GPIO_TIM3_CH3IN_1
#define GPIO_TIM3_CH4IN		GPIO_TIM3_CH4IN_1

//#define GPIO_TIM4_CH2IN		GPIO_TIM4_CH2IN_2
//#define GPIO_TIM4_CH3IN		GPIO_TIM4_CH3IN_2
#define DIRECT_INPUT_TIMER_CHANNELS  8

/* USB OTG FS
 *
 * PA9  OTG_FS_VBUS VBUS sensing (also connected to the green LED)
 */
#define GPIO_OTGFS_VBUS		(GPIO_INPUT|GPIO_FLOAT|GPIO_SPEED_100MHz|GPIO_OPENDRAIN|GPIO_PORTA|GPIO_PIN9)

/* High-resolution timer */
#define HRT_TIMER		8	/* use timer8 for the HRT */
#define HRT_TIMER_CHANNEL	1	/* use capture/compare channel */

/* PWM input driver. Use FMU AUX5 pins attached to timer4 channel 2 */
#define PWMIN_TIMER		3
#define PWMIN_TIMER_CHANNEL	1
#define GPIO_PWM_IN		GPIO_TIM3_CH1IN_2

//#define GPIO_SBUS_INPUT   (GPIO_INPUT|GPIO_CNF_INFLOAT|GPIO_MODE_INPUT|GPIO_PORTD|GPIO_PIN9)
//#define GPIO_SBUS_OUTPUT  (GPIO_OUTPUT|GPIO_CNF_OUTPP|GPIO_MODE_50MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTD|GPIO_PIN8)
//#define GPIO_SBUS_OENABLE (GPIO_OUTPUT|GPIO_CNF_OUTPP|GPIO_MODE_50MHz|GPIO_OUTPUT_SET|GPIO_PORTE|GPIO_PIN7)

#define RC_SERIAL_PORT		"/dev/ttyS2"
#define GPIO_SBUS_INV			(GPIO_OUTPUT|GPIO_PUSHPULL|GPIO_SPEED_2MHz|GPIO_OUTPUT_CLEAR|GPIO_PORTE|GPIO_PIN3)
#define INVERT_RC_INPUT(_s)		stm32_gpiowrite(GPIO_SBUS_INV, _s)

#define BOARD_ADC_USB_CONNECTED (stm32_gpioread(GPIO_OTGFS_VBUS))
#define BOARD_ADC_BRICK_VALID   (0)
#define BOARD_ADC_SERVO_VALID   (1)
#define BOARD_ADC_PERIPH_5V_OC  (0)
#define BOARD_ADC_HIPOWER_5V_OC (0)

#define BOARD_HAS_PWM	DIRECT_PWM_OUTPUT_CHANNELS


#define BOARD_FMU_GPIO_TAB { \
		{GPIO_GPIO0_INPUT,       GPIO_GPIO0_OUTPUT,       0}, \
		{GPIO_GPIO1_INPUT,       GPIO_GPIO1_OUTPUT,       0}, \
		{GPIO_GPIO2_INPUT,       GPIO_GPIO2_OUTPUT,       0}, \
		{GPIO_GPIO3_INPUT,       GPIO_GPIO3_OUTPUT,       0}, \
		{GPIO_GPIO4_INPUT,       GPIO_GPIO4_OUTPUT,       0}, \
		{GPIO_GPIO5_INPUT,       GPIO_GPIO5_OUTPUT,       0}, }

/****************************************************************************************************
 * Public Types
 ****************************************************************************************************/

/****************************************************************************************************
 * Public data
 ****************************************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************************************
 * Public Functions
 ****************************************************************************************************/

/****************************************************************************************************
 * Name: stm32_spiinitialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins for the PX4FMU board.
 *
 ****************************************************************************************************/

extern void stm32_spiinitialize(void);

extern void stm32_usbinitialize(void);

/****************************************************************************
 * Name: nsh_archinitialize
 *
 * Description:
 *   Perform architecture specific initialization for NSH.
 *
 *   CONFIG_NSH_ARCHINIT=y :
 *     Called from the NSH library
 *
 *   CONFIG_BOARD_INITIALIZE=y, CONFIG_NSH_LIBRARY=y, &&
 *   CONFIG_NSH_ARCHINIT=n :
 *     Called from board_initialize().
 *
 ****************************************************************************/

#ifdef CONFIG_NSH_LIBRARY
int nsh_archinitialize(void);
#endif

#endif /* __ASSEMBLY__ */

__END_DECLS
