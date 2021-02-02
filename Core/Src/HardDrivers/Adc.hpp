/**********************************************************************************/
/**
*  @file
*  Adc.hpp - declaration of class TAdc.
*
*/

/**********************************************************************************/
#ifndef __Adc_H
#define __Adc_H

/**********************************************************************************/
//#include "main.h"
//#include "stm32l0xx_hal_def.h"
//#include "stm32l0xx_hal_dma.h"
//#include "stm32l0xx_hal_adc.h"
#include "..\Os\Os.hpp"

/**********************************************************************************/
#define ADC_NUMBER_OF_CONV     3
#define ADC_NUMBER_OF_CHANNEL  7

#define ADC_VIN_CHANNEL   0
#define ADC_T3_CHANNEL    1
#define ADC_MOT_CHANNEL   2
#define ADC_T1_CHANNEL    3
#define ADC_T2_CHANNEL    4
#define ADC_VREF_CHANNEL  5
#define ADC_TP_CHANNEL    6

/*
 *    17.5              |  18.1         |  19.1         | 15.2          | 23.3          | 24.3
 *  TP - 20.38  |
 *  T1 - 0.895 - 19.55  | 0.912 - 19.84 | 0.927 - 20.60 | 0.851 - 17.86 | 1.016 - 22.93 | 1.039 - 23.38
 *  T2 - 0.905 -        | 0.922         | 0.937         | 0.860         | 1.028         | 1.051
 *  T3 - 0.907          | 0.925         | 0.948         | 0.865         | 1.036         | 1.062
 *
 */

/*
          19.8/22.3 | 17.6/23.06
    TP  |   22.408  |   20.45
    T1  |   0.945   |   0.899
    T2  |   0.956   |   0.909
    T3  |   0.964   |   0.914
*/

/*
Address of the calibrate temperature sensors:
0x1FF8 007A - 0x1FF8 007B - TS_CAL1 - 130 C
0x1FF8 007E - 0x1FF8 007F - TS_CAL2 - 30 C
 */
#define ADC_ADDR_T30_CAL   0x1FF8007A
#define ADC_ADDR_T130_CAL  0x1FF8007E

/*
Address of the calibrate Vref:
0x1FF8 0078 - 0x1FF8 0079
*/
#define ADC_ADDR_VREF_CAL     0x1FF80078
#define ADC_VDDA_3V_CAL       3.0
#define ADC_FULL_SCALE_12BIT  4095
#define ADC_FULL_SCALE_8BIT   255


/**********************************************************************************/
//==================================================================================
class TAdc
{
public:
    ////// variables //////
    

    ////// constants //////


    ////// functions //////
    void Init(void);
    EOsResult ConversionComplete(void);
    void Start(u16*);
    void Start(void);
    void Stop(void);
    void StopDma(void);
    void Calibrate(void);
    float ReadTP(u16*);
    float ReadTP(void);
    float ReadVref(u16*);
    float ReadVref(void);
    float ReadVdda(u16*);
    float ReadVdda(void);
    float ReadVin(u16*);
    float ReadVin(void);
    float ReadT1(u16*);
    float ReadT1(void);
    float ReadT2(u16*);
    float ReadT2(void);
    float ReadT3(u16*);
    float ReadT3(void);
    void TSensorOn(void);
    void TSensorOff(void);
    
  
protected:
	////// variables //////
	

	////// constants //////


	////// functions //////

  
private:
	////// variables //////
    volatile u8 convCounter;
    //u16 result[ADC_NUMBER_OF_CHANNEL];
    u16 resultConv[ADC_NUMBER_OF_CONV-1][ADC_NUMBER_OF_CHANNEL];
    u16 valueSensor[ADC_NUMBER_OF_CHANNEL];


	////// constants //////


	////// functions //////
    float ReadChannel(u16*, u16);
    



};
//=== end class TAdc ===============================================================

/**********************************************************************************/

#endif
