/*************************************************************************
 * conf_board.h
 *
 * Created: 11.2.2016 13:01:57
 * Revised: 15.7.2018
 * Author: LeXa
 * BOARD: LED_LIGHT_E2
 *
 * ABOUT:
 * Configuration of board
 *************************************************************************/

#ifndef CONF_BOARD_H_
#define CONF_BOARD_H_

/************************************************************************/
/* BOARD                                                                */
/************************************************************************/
#define TEMP_A                          /* Board name and version */


/************************************************************************/
/* SYSTEM CLOCK OPTIONS                                                 */
/************************************************************************/

    #define F_CPU                       CONF_SOURCE_FREQ*CONF_FREQ_MULTIPLICATION
    #define CONF_SOURCE_FREQ            32000000
    #define CONF_FREQ_MULTIPLICATION    1
    
    /* Define source for PLL if used. Uncomment the right one */
    //#define CONF_PLL_SOURCE           OSC_PLLSRC_XOSC_gc
    //#define CONF_PLL_SOURCE           OSC_PLLSRC_RC2M_gc
    //#define CONF_PLL_SOURCE           OSC_PLLSRC_RC32M_gc


/************************************************************************/
/* HARDWARE OPTIONS                                                     */
/************************************************************************/

    /*===== RF MODULE nRF24L01+ ============================================
     *======================================================================*/
    #define RF_PORT                         PORTC
    #define RF_SPI                          SPIC
    #define RF_BAUD_SPI                     1000000
    #define RF_IRQ_vect                     PORTC_INT0_vect
    #define RF_IRQ_PIN                      PIN2_bp
    #define RF_CE_PIN                       PIN3_bp
    #define ENABLE_AUTOACK                  false
    #define DYNAMIC_PAYLOAD                 true
    #define STATIC_PAYLOAD_BUFFER_LENGTH    32
    #define DATA_PIPE0_EN                   1
    
    /*===== ADC ============================================================
     *======================================================================*/
    #define SUPPLY_MUX_PIN                  ADC_CH_MUXPOS_PIN5_gc
    #define R101                            4700
    #define R102                            1000
    #define SUPPLY_RATIO                    (R101+R102)/R102
    
    /*===== SHT3X ==========================================================
     *======================================================================*/
    #define SHT3X_TWI                       TWIC
    #define SHT3X_TWI_BAUD                  400000
    
    /*===== DS18B20 ========================================================
     *======================================================================*/
    #define DS18B20_USART                   USARTD0
    #define DS18B20_PORT                    PORTD               

#endif /* CONF_BOARD_H_ */