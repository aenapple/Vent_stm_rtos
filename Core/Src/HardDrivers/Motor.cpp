/**********************************************************************************/
/**
*  @file
*  Todo: Motor.cpp.
*
*/
/**********************************************************************************/
#include "Motor.hpp"


/**********************************************************************************/
//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TMotor::Init(void)
{
    HAL_GPIO_WritePin(MOT_EN_GPIO_Port, MOT_EN_Pin, GPIO_PIN_RESET);  // input to SLEEP  
    HAL_GPIO_WritePin(MOT_IN1_GPIO_Port, MOT_IN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOT_IN2_GPIO_Port, MOT_IN2_Pin, GPIO_PIN_RESET);
    
    this->ventOpen = false;
}
//=== end Init =====================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TMotor::Close(void)
{
    if(this->ventOpen)
    {
        HAL_GPIO_WritePin(MOT_EN_GPIO_Port, MOT_EN_Pin, GPIO_PIN_SET);    // output from SLEEP
        HAL_GPIO_WritePin(MOT_IN1_GPIO_Port, MOT_IN1_Pin, GPIO_PIN_SET);
        this->Delay(700);
        HAL_GPIO_WritePin(MOT_IN1_GPIO_Port, MOT_IN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MOT_EN_GPIO_Port, MOT_EN_Pin, GPIO_PIN_RESET);  // input to SLEEP
    
        this->ventOpen = false;
    }
}
//=== end Close ====================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TMotor::Open(void)
{
    if(!this->ventOpen)
    {
        HAL_GPIO_WritePin(MOT_EN_GPIO_Port, MOT_EN_Pin, GPIO_PIN_SET);    // output from SLEEP
        HAL_GPIO_WritePin(MOT_IN2_GPIO_Port, MOT_IN2_Pin, GPIO_PIN_SET);
        this->Delay(700);
        HAL_GPIO_WritePin(MOT_IN2_GPIO_Port, MOT_IN2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MOT_EN_GPIO_Port, MOT_EN_Pin, GPIO_PIN_RESET);  // input to SLEEP
    
        this->ventOpen = true;
    }
}
//=== end Open =====================================================================

/**********************************************************************************/
