/**********************************************************************************/
/**
*  @file
*  Todo: Adc.cpp.
*
*/

/**********************************************************************************/
#include "Adc.hpp"


/**********************************************************************************/
extern ADC_HandleTypeDef hadc;


/**********************************************************************************/
//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TAdc::Init(void)
{
    HAL_GPIO_WritePin(VIN_CONTROL_GPIO_Port, VIN_CONTROL_Pin, GPIO_PIN_RESET);
    this->TSensorOn();
    this->Calibrate();
    this->convCounter = 0;
}
//=== end Init =====================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
EOsResult TAdc::ConversionComplete(void)
{
    u16 i;

    
    //if(this->convCounter < ADC_NUMBER_OF_CONV)
    //{
        this->convCounter++;
        
        if(this->convCounter < ADC_NUMBER_OF_CONV)
        {
            this->Start(this->resultConv[this->convCounter-1]);
            return(OsResult_AdcStartConversion);
        }
        //else
        //{
            for(i= 0; i < ADC_NUMBER_OF_CHANNEL; i++)
            {
                this->valueSensor[i]= (this->resultConv[0][i] + this->resultConv[1][i]) / 2;
            }
            
            this->convCounter = 0;
            return(OsResult_AdcEndConversion);
        //}
      
    //}
    
    
    
    
}
//=== end ConversionComplete========================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TAdc::Start(u16* bufferData)
{
    //for(u16 i = 0; i < ADC_NUMBER_OF_CHANNEL; i++) bufferData[i] = 0;
    HAL_ADC_Start_DMA(&hadc, (u32*)bufferData, ADC_NUMBER_OF_CHANNEL);
}
//=== end Start ====================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TAdc::Start(void)
{
    //for(u16 i = 0; i < ADC_NUMBER_OF_CHANNEL; i++) bufferData[i] = 0;
    HAL_ADC_Start_DMA(&hadc, (u32*)this->resultConv[0], ADC_NUMBER_OF_CHANNEL);
}
//=== end Start ====================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TAdc::Stop(void)
{
    HAL_ADC_Stop(&hadc);
}
//=== end Stop =====================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return ... .
*/
void TAdc::StopDma(void)
{
    HAL_ADC_Stop_DMA(&hadc);
}
//=== end StopDma ==================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TAdc::Calibrate(void)
{
    HAL_ADCEx_Calibration_Start(&hadc, ADC_SINGLE_ENDED);
}
//=== end Calibrate ================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadTP(u16* valueAdc)
{
    float result;
    u16 tsCal1;
    u16 tsCal2;
    float tsData;


    tsCal1 = *((u16*)ADC_ADDR_T30_CAL);
    tsCal2 = *((u16*)ADC_ADDR_T130_CAL);
    tsData = this->ReadVdda(valueAdc) / ADC_VDDA_3V_CAL * valueAdc[ADC_TP_CHANNEL];
    result = 100.0 / (tsCal2 - tsCal1) * (tsData - tsCal1) + 30;


    return (result);
}
//=== end ReadTP ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadTP(void)
{
    return (this->ReadTP(this->valueSensor));
}
//=== end ReadTP ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadVref(u16* valueAdc)
{
	return (this->ReadChannel(valueAdc, ADC_VREF_CHANNEL));
}
//=== end ReadVref =================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadVref(void)
{
	return (this->ReadVref(this->valueSensor));
}
//=== end ReadVref =================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadVdda(u16* valueAdc)
{
	return (ADC_VDDA_3V_CAL * (*((u16*)ADC_ADDR_VREF_CAL)) / valueAdc[ADC_VREF_CHANNEL]);
}
//=== end ReadVdda =================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadVdda(void)
{
	return (this->ReadVdda(this->valueSensor));
}
//=== end ReadVdda =================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadVin(u16* valueAdc)
{
    return (this->ReadChannel(valueAdc, ADC_VIN_CHANNEL) * 2.06);
}
//=== end ReadVin ==================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadVin(void)
{
    return (this->ReadVin(this->valueSensor));
}
//=== end ReadVin ==================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadT1(u16* valueAdc)
{
    return (this->ReadChannel(valueAdc, ADC_T1_CHANNEL) /* 23*/);
}
//=== end ReadT1 ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadT1(void)
{
    return (this->ReadT1(this->valueSensor));
}
//=== end ReadT1 ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadT2(u16* valueAdc)
{
    return (this->ReadChannel(valueAdc, ADC_T2_CHANNEL) /* 22.25476*/);  // 22.25476
}
//=== end ReadT2 ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadT2(void)
{
    return (this->ReadT2(this->valueSensor));
}
//=== end ReadT2 ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadT3(u16* valueAdc)
{
    return (this->ReadChannel(valueAdc, ADC_T3_CHANNEL) /* 23*/);
}
//=== end ReadT3 ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadT3(void)
{
    return (this->ReadT3(this->valueSensor));
}
//=== end ReadT3 ===================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
float TAdc::ReadChannel(u16* valueAdc, u16 channelAdc)
{
    //float result;


    //result = ADC_VDDA_3V_CAL * (u16)(*((u16*)ADC_ADDR_VREF_CAL)) * valueAdc[channelAdc];
    //result = result / ADC_FULL_SCALE_12BIT / valueAdc[ADC_VREF_CHANNEL];
    //result = this->ReadVdda(valueAdc) * valueAdc[channelAdc] / ADC_FULL_SCALE_12BIT;





    return (this->ReadVdda(valueAdc) * valueAdc[channelAdc] / ADC_FULL_SCALE_12BIT);
}
//=== end ReadChannel ==============================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TAdc::TSensorOn(void)
{
    HAL_GPIO_WritePin(CTRL_GPIO_Port, CTRL_Pin, GPIO_PIN_SET);
}
//=== end TSensorOn ================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TAdc::TSensorOff(void)
{
    HAL_GPIO_WritePin(CTRL_GPIO_Port, CTRL_Pin, GPIO_PIN_RESET);
}
//=== end TSensorOff ===============================================================

/**********************************************************************************/
