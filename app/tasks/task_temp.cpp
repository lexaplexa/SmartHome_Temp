/*************************************************************************
 * task_temp.cpp
 *
 * Created: 2.12.2018 13:29:50
 * Revised: 20.12.2018
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#include <app/app.h>

DS18B20 cTempOut(&DS18B20_USART, &DS18B20_PORT, F_CPU);
SHT3X cTempHum(&SHT3X_TWI, SHT3X_TWI_BAUD, F_CPU);

void task_temp_meas()
{
    cTempOut.MeasTemp();
    cMTask.Delay(task_temp_read, TASK_TOUT_MS(750));
    cTempHum.SingleShotMeasure(SHT3X_SINGLESHOT_ACCURACY_HIGH);
    cRtc.StartCounter(task_temp_meas,10);
}

void task_temp_read()
{
    cTempOut.ReadTemp();
    cTempHum.ReadOut();
}