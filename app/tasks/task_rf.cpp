/*************************************************************************
 * task_rf.cpp
 *
 * Created: 16.9.2018 14:21:56
 * Revised:
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#include <app/app.h>

RF cRf;
RF_DATA RFData;

void taskRf()
{
    uint8_t unRfMsgSize;
    
    if (cRf.m_eStatus == RF_STATUS_RECEIVE_OK) {memcpy(RFData.reg, cRf.m_sPayload.punBuffer, cRf.m_sPayload.unCounter);}
    else {return;}
    
    /* Send answer to Master */
    switch (RFData.eRfCommand)
    {
        case RF_COMM_RESET:
            CCP = CCP_IOREG_gc; RST.CTRL = RST_SWRST_bm;
            break;
        
        case RF_COMM_STATUS:
            int16_t nAdcRes;
            float fVolt;
            
            RFData.Slave.sStatusTemp.eDeviceType = DEVICE_TYPE_LED_CONTROLLER;
            /* Read supply voltage */
            adc_read(ADCA,SUPPLY_MUX_PIN,nAdcRes);
            fVolt = ADC_TO_VOLT((float)nAdcRes*SUPPLY_RATIO*10);
            RFData.Slave.sStatusTemp.unSupplyVolt = (uint8_t)fVolt;
            /* Read Temperature and Humidity */
            RFData.Slave.sStatusTemp.nTempSHT3x = (int16_t)(cSht.GetTempC()*100);
            RFData.Slave.sStatusTemp.unHumSHT3x = (uint16_t)(cSht.GetHum()*10);
            RFData.Slave.sStatusTemp.nTempDS18B20 = (int16_t)(cDs18b20.GetTempC()*100);
            
            unRfMsgSize = 1+sizeof(RFData.Slave.sStatusTemp);
            break;
            
        default:
            RFData.eRfCommand = RF_COMM_ERROR;
            RFData.Slave.eError = ERROR_UNKNOWN_COMMAND;
            unRfMsgSize = 2;
            break;
    }
    cRf.SendMsg(RFData.reg,unRfMsgSize);
}


/************************************************************************/
/* INTERRUPT HANDLER                                                    */
/************************************************************************/
SIGNAL(RF_IRQ_vect)
{
    cRf.InterruptHandler();
    if (DSRf.unRFBaud == (RF_BAUD_enum)RF_BAUD_250kbps_gc)      {cMTask.Delay(taskRf,TASK_TOUT_MS(10));}
    else if (DSRf.unRFBaud == (RF_BAUD_enum)RF_BAUD_1Mbps_gc)   {cMTask.Delay(taskRf,TASK_TOUT_MS(5));}
    else                                                        {cMTask.Delay(taskRf,TASK_TOUT_MS(1));}
    //cMTask.Delay(taskSleep,TASK_TOUT_MS(100));
}