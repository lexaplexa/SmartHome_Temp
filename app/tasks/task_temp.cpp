/*************************************************************************
 * task_temp.cpp
 *
 * Created: 16.9.2018 15:28:42
 * Revised:
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#include <app/app.h>

SHT3X cSht(&SHT3X_TWI, SHT3X_TWI_BAUD, F_CPU);
DS18B20 cDs18b20(&DS18B20_USART, &DS18B20_PORT, F_CPU);
void ds18b20_read_temp();

void taskTemp()
{
    cSht.SingleShotMeasure(SHT3X_SINGLESHOT_ACCURACY_HIGH);
    cDs18b20.MeasTemp();
    cMTask.Delay(ds18b20_read_temp, TASK_TOUT_MS(750));
}

void ds18b20_read_temp()
{
    cDs18b20.ReadTemp();
}