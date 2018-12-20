/*************************************************************************
 * task_real_time.cpp
 *
 * Created: 20.12.2018 12:34:08
 * Revised: 
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#include <app/app.h>

REALTIME cRtc;

SIGNAL(RTC_OVF_vect)
{
    cRtc.InterruptHandler();
}