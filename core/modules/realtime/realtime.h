/*************************************************************************
 * realtime.h
 *
 * Created: 20.12.2018 10:37:21
 * Revised:
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#ifndef REALTIME_H_
#define REALTIME_H_

#include <avr/io.h>
#include <core/core.h>

/************************************************************************/
/* CLASS                                                                */
/************************************************************************/
class REALTIME
{
    private:
        int32_t m_nCounter;
        int32_t m_nMatch = -1;
        void* m_pvTask;
        
    public:
        REALTIME();
        void StartCounter(void pvTask(), uint16_t unTimeoutS);
        void InterruptHandler();
};


#endif /* REALTIME_H_ */