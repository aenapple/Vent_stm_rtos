/**********************************************************************************/
/**
*  @file
*  Todo: TaskSys.cpp.
*
*/
/**********************************************************************************/
#include "TaskSys.hpp"
//#include <stdio.h>
//#include <stdarg.h>
// #include <string>


TTaskSys TaskSys;
/**********************************************************************************/
extern "C" void RunSystemTasks(void)
{
	TaskSys.Run();
}


/**********************************************************************************/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef * hAdc)
{
    TaskSys.SetEventAdcCompleteFromISR();
}

/*void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * hTim)
{
    TaskSys.SetEventTimerTickFromISR();
}*/

void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc)
{
    TaskSys.SetEventRtcWakeUpEventFromISR();
}

void HAL_IncTick(void)
{
    TaskSys.SysTickFromISR();
}


/**********************************************************************************/
//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
//void RunSystemTasks(void)
//{
//	TaskSys.Run();
//}
//=== end CreateApplicationTasks ===================================================

//==================================================================================
/**
*  The function ... .
*
*  @return ... .
*/
/*void vApplicationTickHook(void)
{
	TaskSys.SetEventTickFromISR();
}*/
//=== end vApplicationTickHook =====================================================

//==================================================================================
/**
*  The function ... .
*
*  @return
*  		none.
*/
//void TTaskSys::SetEventTickFromISR(void)
//{
	/*TaskSys.EventGroup.SetBitsFromISR(TASK_SYS_EVENT_TICK);

	if(this->event_5seconds > 0)
	{
		this->event_5seconds--;
	}
	else
	{
		this->event_5seconds = TASK_SYS_TICK_5SECONDS;
		TaskSys.EventGroup.SetBitsFromISR(TASK_SYS_EVENT_5SECONDS);
	}*/

//}
//=== end SetEventTickFromISR =====================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
void TTaskSys::Run(void)
{
	//bool toggleMotor;
	//u32 counter;
	// std::string str_counter;


	this->Init();

	//counter = 0;
	//toggleMotor = true;
	while(true)
	{

		/*if(this->OsEventGroup.WaitAndBits(TASK_SYS_EVENT_WAKEUP, 1000) == OsResult_Timeout)
		{
			continue;
		}*/

        Led.Led1_on();
		this->Delay(1000);
        //this->Led.Led2_off();
        this->Adc.Start(this->resultAdc);
        /*if(this->OsEventGroup.WaitAndBits(TASK_SYS_EVENT_ADC, 1000) == OsResult_Ok)
        {

            continue;
        }*/


        this->Delay(10);
        this->ReadAdc();
        Led.Led1_off();

        //this->tmpFloat[0] = this->Adc.ReadTP(this->valueSensor);
        this->tmpFloat[1] = this->Adc.ReadVdda(this->valueSensor);
        this->tmpFloat[2] = this->Adc.ReadVref(this->valueSensor);
        this->tmpFloat[3] = this->Adc.ReadVin(this->valueSensor);
        this->tmpFloat[4] = this->Adc.ReadT1(this->valueSensor);
        this->tmpFloat[5] = this->Adc.ReadT2(this->valueSensor);
        this->tmpFloat[6] = this->Adc.ReadT3(this->valueSensor);

        this->Delay(1000);

		//this->DebugPrint("Cycles - %06d\r\n", counter);

        HAL_SuspendTick();
        this->Led.Led2_on();
        HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);
        //HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
        //HAL_PWR_EnterSTANDBYMode();
        //HAL_ResumeTick();
        //this->Led.Led2_off();




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
void TTaskSys::ReadAdc(void)
{
    u16 i;

    for(i= 0; i < ADC_NUMBER_OF_CHANNEL; i++)
    {
        this->valueSensor[i]= this->resultAdc[i];
    }

}
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
*  Todo: function description.
*
*  @return
*  		none.
*/
void TTaskSys::SetEventAdcCompleteFromISR(void)
{
    this->Adc.StopDma();
    Led.Led1_off();

}
//=== end SetEventAdcCompliteFromISR ===============================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return
*  		none.
*/
void TTaskSys::SetEventTimerTickFromISR(void)
{
    this->TimerTick.CountCounters();
}
//=== end SetEventTimerTickFromISR =================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return
*  		none.
*/
void TTaskSys::SetEventRtcWakeUpEventFromISR(void)
{
    this->wakeUpCounter++;
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
void TTaskSys::SysTickFromISR(void)
{
    this->sysTickCounter++;
    if(this->delayCounter > 0)
    {
        this->delayCounter--;
    }
}
//=== end SysTickFromISR ===========================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
EOsResult TTaskSys::Init(void)
{
    this->sysTickCounter = 0;

    this->Led.Init();
    this->Adc.Init();
	//this->TimerTick.Start();
    //this->UartDebug.Init();



	return(OsResult_Ok);
}
//=== end Init =====================================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
//EOsResult TTaskSys::CreateOsResources(void)
//{
	/*EOsResult result;


	result= this->EventErrors.Create(OS_TASK_SYSTEM_MAX_NUMBER_ERRORS, OS_TASK_SYSTEM_SIZE_PARAM_ERRORS);
	if(result != OsResult_Ok) return(result);*/


//	return(OsResult_Ok);
//}
//=== end CreateOsResources ========================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
void TTaskSys::Delay(u16 mSecTime)
{
    //this->TimerTick.Delay(time);
    this->delayCounter = mSecTime;
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
//=== end CreateTask ===============================================================

//==================================================================================
/**
*  Todo: function description..
*
*  @return ... .
*/
/*void TTaskSys::CreateTaskStatic(void)
{
	((TOsTask*)this)->CreateTaskStatic("SYSTEM TASK", OS_TASK_SYS_SIZE_STACK, OS_TASK_SYS_PRIORITY, xStackBuffer, &xTaskBuffer);
}*/
//=== end CreateTaskStatic =========================================================

/**********************************************************************************/
