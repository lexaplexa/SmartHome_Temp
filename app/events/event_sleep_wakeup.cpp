/*************************************************************************
 * event_sleep_wakeup.cpp
 *
 * Created: 20.12.2018 14:04:18
 * Revised: 
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#include <app/app.h>

void eventBeforeSleep()
{
    
}

void eventAfterWakeUp()
{
    /* TWI interface must be set idle after wake up */
    SHT3X_TWI.MASTER.STATUS = TWI_MASTER_BUSSTATE_IDLE_gc;
}