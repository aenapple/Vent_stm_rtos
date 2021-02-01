/**********************************************************************************/
/**
*  @file
*  Todo: TimerTick.cpp.
*
*/

/**********************************************************************************/
#include "TimerTick.hpp"


/**********************************************************************************/
//extern TIM_HandleTypeDef htim21;


/**********************************************************************************/
//==================================================================================
/**
*  Todo: function description
*
*  @return void .
*/
void TTimerTick::Start(void)
{
    //HAL_TIM_Base_Init(&htim21);
    //HAL_TIM_Base_Start_IT(&htim21);
    //HAL_TIM_Base_Start(&htim21);
    this->delayCounter = 0;
    this->systemCounter = 0;
}
//=== end Start ====================================================================

//==================================================================================
/**
*  Todo: function description
*
*  @return void .
*/
void TTimerTick::Stop(void)
{
    //HAL_TIM_Base_Stop(&htim21);
    //HAL_TIM_Base_Stop_IT(&htim21);
}
//=== end Stop =====================================================================

//==================================================================================
/**
*  Todo: function description
*
*  @return void .
*/
void TTimerTick::Delay(u16 mSecCounter)
{
    this->delayCounter = mSecCounter;
    while (true)
    {
        if(this->delayCounter > 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
}
//=== end Delay ====================================================================

//==================================================================================
/**
*  Todo: function description
*
*  @return void .
*/
void TTimerTick::CountCounters(void)
{
    this->systemCounter++;

    if(this->delayCounter > 0)
    {
        this->delayCounter--;
    }

}
//=== end WorkCounter ==============================================================

/**********************************************************************************/
