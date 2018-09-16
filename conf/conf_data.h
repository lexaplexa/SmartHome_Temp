/*************************************************************************
 * conf_data.h
 *
 * Created: 16.9.2018 17:09:11
 * Revised: 
 * Author: LeXa
 * BOARD:
 *
 * ABOUT:
 *
 *************************************************************************/

#ifndef CONF_DATA_H_
#define CONF_DATA_H_

/************************************************************************/
/* ENUMs                                                                */
/************************************************************************/
enum DEVICE_TYPE_enum {
    DEVICE_TYPE_BOOT_LOADER,
    DEVICE_TYPE_MASTER_CONTROLLER,
    DEVICE_TYPE_LED_CONTROLLER,
    DEVICE_TYPE_METEO_STATION,
    DEVICE_TYPE_TEMP,
};

enum ERROR_enum {
    ERROR_OK,
    ERROR_OUT_OF_RANGE,
    ERROR_OVERVOLTAGE,
    ERROR_UNDERVOLTAGE,
    ERROR_UNKNOWN_COMMAND,
    ERROR_NEXT,
    ERROR_VERIFICATION_FAILED,
};


/************************************************************************/
/* DATASET                                                              */
/************************************************************************/
union DATASET_RF {
    uint8_t reg[16];
    struct {
        uint8_t                 unRFChannel;                /* RF channel number                        */
        uint8_t                 aTransmitAddress[5];        /* Slave address                            */
        uint8_t                 unRFBaud;                   /* RF Baud rate (250kbps, 1Mbps, 2Mbps)     */
        uint32_t                unAppChecksum;              /* Application sector checksum              */
        uint8_t                 aReserved[5];               /* Reserved bytes for future use            */
    };
};

union DATASET_TEMP {
    uint8_t reg[10];
    struct {
       
    };
};    

/************************************************************************/
/* COMMANDS                                                             */
/************************************************************************/
enum RF_COMMAND_enum {
    /* Basic commands */
    RF_COMM_RESET,
    RF_COMM_STATUS,
    RF_COMM_TEMP_GET_DATASET,
    RF_COMM_TEMP_SET_DATASET,
    
    /* Error answer to command. Error code is followed */
    RF_COMM_ERROR = 255,
};

/************************************************************************/
/* RF COMUNICATION STRUCTURE                                            */
/************************************************************************/
union RF_DATA {
    uint8_t reg[32];
    struct 
    {
        /*===== COMMAND =========================================================
         * Command is always in first place
         *=======================================================================*/
        RF_COMMAND_enum eRfCommand;
        
        union 
        {
            /*===== MASTER DATA =====================================================
             * Data send by Master controller
             *=======================================================================*/
            union 
            {
                DATASET_TEMP sSetDataset;
            } Master;
            
            /*===== SLAVE DATA ======================================================
             * Data send by Slave controller
             *=======================================================================*/
            union 
            {
                ERROR_enum                  eError;
                struct STATUS_TEMP_struct {
                    DEVICE_TYPE_enum eDeviceType;
                    uint8_t unSupplyVolt;                   /* 1bit = 0,1V */
                    int16_t nTempSHT3x;                     /* 1bit = 0,01°C */
                    uint16_t unHumSHT3x;                    /* 1bit = 0,1% */
                    int16_t nTempDS18B20;                   /* 1bit = 0,01°C */
                } sStatusTemp;
            } Slave;
        };
    };
};

#endif /* CONF_DATA_H_ */