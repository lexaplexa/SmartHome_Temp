/*************************************************************************
 * task_startupapp.cpp
 *
 * Created: 16.9.2018 10:37:08
 * Revised:
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#include <app/app.h>

DATASET_RF DSRf;
DATASET_RF EEDSRf EEMEM = {
    /* Default EEPROM Dataset Values ---------------------------------------*/
    125,                        /* RF channel number                        */
    0xAA,0x55,0xAA,0x55,0xAA,   /* Slave address                            */
    RF_BAUD_250kbps_gc,         /* RF Baud rate (250kbps, 1Mbps, 2Mbps)     */
    0x00000000                  /* CRC application sector checksum          */
};

uint8_t aData[2] = {0xCC,0xBE};
void repeat();


void taskStartUpApp()
{
    /* Load Datasets from EEPROM */
    eeprom_read_block(DSRf.reg, EEDSRf.reg, sizeof(DATASET_RF));
    
    /* ADC initialization */
    adc_init(ADCA,ADC_PRESCALER_DIV256_gc,ADC_RESOLUTION_12BIT_gc);
    
    /* Real Time Clock initialization */
    //CLK.RTCCTRL = (0x06<<1)|CLK_RTCEN_bm;
    //RTC.INTCTRL = RTC_OVFINTLVL_HI_gc;
    //RTC.CNT = 0;
    //while (RTC.STATUS & RTC_SYNCBUSY_bm);
    //RTC.PER = 0x7FFF;
    //while (RTC.STATUS & RTC_SYNCBUSY_bm);
    //RTC.CTRL = RTC_PRESCALER_DIV1_gc;
    //while (RTC.STATUS & RTC_SYNCBUSY_bm);
    
    /* RF initialization */
    cRf.Init();
    cRf.SetBaud((RF_BAUD_enum)DSRf.unRFBaud);
    cRf.SetChannel(DSRf.unRFChannel);
    cRf.SetTXaddress(DSRf.aTransmitAddress,5);
    cRf.SetRXaddress(DSRf.aTransmitAddress,5,0);
    cRf.WakeUp();
    
    /* Temperature sensors initialization */
    taskTemp();
    cMTask.Repeat(taskTemp, TASK_TOUT_MS(1000));
    
    /* Send message after start. Slave identifies itself */
    RFData.eRfCommand = RF_COMM_STATUS;
    cRf.m_eStatus = RF_STATUS_RECEIVE_OK;
    taskRf();
}