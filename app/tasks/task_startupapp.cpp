/*************************************************************************
 * task_startupapp.cpp
 *
 * Created: 16.9.2018 10:37:08
 * Revised: 20.12.2018
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

void taskStartUpApp()
{
    /* Load Datasets from EEPROM */
    eeprom_read_block(DSRf.reg, EEDSRf.reg, sizeof(DATASET_RF));
    
    /* ADC initialization */
    adc_init(ADCA,ADC_PRESCALER_DIV256_gc,ADC_RESOLUTION_12BIT_gc);

    /* RF initialization */
    cRf.Init();
    cRf.SetBaud((RF_BAUD_enum)DSRf.unRFBaud);
    cRf.SetChannel(DSRf.unRFChannel);
    cRf.SetTXaddress(DSRf.aTransmitAddress,5);
    cRf.SetRXaddress(DSRf.aTransmitAddress,5,0);
    cRf.WakeUp();
    
    /* First temperature measure after start */
    task_temp_meas();
}