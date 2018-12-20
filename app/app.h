/*************************************************************************
 * app.h
 *
 * Created: 24.6.2018 10:34:46
 * Revised: 20.12.2018
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/


#ifndef APP_H_
#define APP_H_

#include <core/core.h>

/************************************************************************/
/* EXTERNAL CLASSES                                                     */
/************************************************************************/
extern class RF cRf;                /* app\tasks\task_rf.cpp */
extern class DS18B20 cTempOut;      /* app\tasks\task_temp.cpp */
extern class SHT3X cTempHum;        /* app\tasks\task_temp.cpp */
extern class REALTIME cRtc;         /* app\tasks\task_real_time.cpp */
extern union DATASET_RF DSRf;       /* app\tasks\task_startupapp.cpp */

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
void task_rf();
void task_temp_meas();
void task_temp_read();
void eventBeforeSleep();
void eventAfterWakeUp();

#endif /* APP_H_ */