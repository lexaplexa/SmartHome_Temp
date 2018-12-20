/*************************************************************************
 * core.h
 *
 * Created: 24.6.2018 09:57:04
 * Revised: 20.12.2018
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/


#ifndef CORE_H_
#define CORE_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <string.h>

#include <core/multitask/multitask.h>

#include <conf/conf_board.h>
#include <conf/conf_data.h>
#include <conf/conf_multitask.h>

#include <core/drivers/adc.h>
#include <core/drivers/clock.h>
#include <core/drivers/spi.h>
#include <core/drivers/twi.h>
#include <core/drivers/usart.h>

#include <core/extensions/ds18b20.h>
#include <core/extensions/rf.h>
#include <core/extensions/sht3x.h>

#include <core/modules/realtime/realtime.h>


/************************************************************************/
/* EXTERNAL CLASSES                                                     */
/************************************************************************/
extern class MTASK cMTask;              /* core/multitask/multitask.cpp */


/************************************************************************/
/* TASK PROTOTYPES                                                      */
/*----------------------------------------------------------------------*/
/* Every task function is named void task<name of task>();              */
/* For example:                                                         */
/* void taskStartUp();                                                  */
/*                                                                      */
/* File names with source code are named task_<name of task>.cpp        */
/* For example:                                                         */
/* task_startup.cpp                                                     */
/*                                                                      */
/* Every task source code must include core.h                           */
/************************************************************************/
void taskStartUpApp();

#endif /* CORE_H_ */