/**********************************************************************************/
/**
*  @file
*  Todo: TaskSys.cpp.
*
*/
/**********************************************************************************/
#include "TaskSys.hpp"
#include <stdio.h>
#include <stdarg.h>
// #include <string>


TTaskSys TaskSys;
/**********************************************************************************/
extern "C" void vApplicationTickHook(void);

void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc)
{
    TaskSys.SetEventRtcWakeUpEventFromISR();
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
    TaskSys.SetEventAdcConvCpltFromISR();
}

/**********************************************************************************/
//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
void CreateApplicationTasks(void)
{
	TaskSys.CreateTaskStatic();
}
//=== end CreateApplicationTasks ===================================================

//==================================================================================
/**
*  The function ... .
*
*  @return ... .
*/
void vApplicationTickHook(void)
{
	TaskSys.SetEventTickFromISR();
}
//=== end vApplicationTickHook =====================================================

//==================================================================================
/**
*  The function ... .
*
*  @return
*  		none.
*/
void TTaskSys::SetEventTickFromISR(void)
{
	this->systemCounter++;
}
//=== end SetEventTickFromISR ======================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return
*  		none.
*/
void TTaskSys::SetEventRtcWakeUpEventFromISR(void)
{
    this->Led.Led2_off();
    HAL_ResumeTick();
}
//=== end SetEventRtcWakeUpEventFromISR ============================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return
*  		none.
*/
void TTaskSys::SetEventAdcConvCpltFromISR(void)
{
  if(this->Adc.ConversionComplete() == OsResult_AdcEndConversion)
  {
    this->SetEventsFromISR(TASK_SYS_ADC_CONV_CPLT);
  }
}
//=== end SetEventAdcConvCpltFromISR ===============================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
void TTaskSys::Run(void)
{
	// u32 counter;
	// std::string str_counter;


	this->Init();

	while(true)
	{

		//this->Delay(1000);
		//this->Led.Led1_on();
        //this->Delay(10);
        //this->Led.Led1_off();
        //continue;
        
		
        /*if(this->EventGroup.WaitAndBits(TASK_SYS_EVENT_5SECONDS, 1000) == OsResult_Timeout)
		{
			continue;
		}*/

        //this->tmpCounter1 = this->systemCounter;
        this->Adc.TSensorOn();
		this->Adc.Start();
        if(this->EventGroup.WaitAndBits(TASK_SYS_ADC_CONV_CPLT, 10) == OsResult_Timeout)
        {
            Led.Led2_on();
            this->Delay(10);
            Led.Led2_off();
            this->Delay(500);
            continue;
        }
        this->Adc.TSensorOff();

        //this->Delay(10);
        //this->ReadAdc();
        //Led.Led1_off();

        //this->tmpCounter2 = this->systemCounter - this->tmpCounter1;
        /*this->tmpFloat[0] = this->Adc.ReadTP();
        this->tmpFloat[1] = this->Adc.ReadVdda();
        this->tmpFloat[2] = this->Adc.ReadVref();
        this->tmpFloat[3] = this->Adc.ReadVin();
        this->tmpFloat[4] = this->Adc.ReadT1();
        this->tmpFloat[5] = this->Adc.ReadT2();
        this->tmpFloat[6] = this->Adc.ReadT3();
        
        continue;*/
        
        if(this->Adc.ReadVin() < 2.8)
        {
            this->Led.Led1_on();
            this->Delay(10);
            this->Led.Led1_off();
            this->Delay(1000);
            continue;
        }
        
        float curTemperature;
        curTemperature = (this->Adc.ReadT1() + this->Adc.ReadT2() + this->Adc.ReadT3()) / 3;
        this->Eeprom.WriteLogTemperature((u8)(curTemperature * 23));
        if(curTemperature > (this->prevTemperature + 0.1))
        {
            if(this->prevTemperature < 1.0)  // ~ 23 C
            {
                this->Motor.Open();
            }
            else
            {
                this->Motor.Close();
            }
        }
                
        this->prevTemperature = curTemperature;
        
        //this->Delay(500);  // mSec
        
        
		
        //HAL_SuspendTick();
        //this->Led.Led2_on();
        //HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
		
      
      
      //this->DebugPrint("Cycles - %06d\r\n", counter);



	}  // end while(true)


}
//=== end Execute ==================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return
*  		none.
*/
/*void TTaskSys::ReadAdc(void)
{
    u16 i;

    for(i= 0; i < ADC_NUMBER_OF_CHANNEL; i++)
    {
        this->valueSensor[i]= this->resultAdc[i];
    }

}*/
//=== end ReadAdc ==================================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
EOsResult TTaskSys::DebugPrint(const char* format, ...)
{
	/*u16 size;
	char buffer[100];
	va_list args;
	EOsResult result;

	va_start(args, format);
	size = vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	result = this->UartDebug.SendData((u8*)buffer, size);

	this->Delay(100);

	return(result);*/
    return(OsResult_Ok);
}
//=== end DebugPrint ===============================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
EOsResult TTaskSys::Init(void)
{
	this->Adc.Init();
    this->Led.Init();
    this->Eeprom.Init();
    
    //this->adcConvCounter = 0;
    this->prevTemperature = 1;  // ~23 C
    this->Delay(10);


	return(OsResult_Ok);
}
//=== end Init =====================================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
EOsResult TTaskSys::CreateOsResources(void)
{
	/*EOsResult result;


	result= this->EventErrors.Create(OS_TASK_SYSTEM_MAX_NUMBER_ERRORS, OS_TASK_SYSTEM_SIZE_PARAM_ERRORS);
	if(result != OsResult_Ok) return(result);*/


	return(OsResult_Ok);
}
//=== end CreateOsResources ========================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
void TTaskSys::CreateTask(void)
{
	((TOsTask*)this)->CreateTask("SYSTEM TASK", OS_TASK_SYS_SIZE_STACK, OS_TASK_SYS_PRIORITY);
}
//=== end CreateTask ===============================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
void TTaskSys::CreateTaskStatic(void)
{
	((TOsTask*)this)->CreateTaskStatic("SYSTEM TASK", OS_TASK_SYS_SIZE_STACK, OS_TASK_SYS_PRIORITY, xStackBuffer, &xTaskBuffer);
}
//=== end CreateTaskStatic =========================================================

/**********************************************************************************/
