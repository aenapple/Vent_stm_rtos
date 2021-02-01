/**********************************************************************************/
/**
*  @file
*  TaskSys.hpp - declaration of class TTaskSys.
*
*  Target:  ...
*/

/**********************************************************************************/
#ifndef __TaskSys_H
#define __TaskSys_H

/**********************************************************************************/
//#include "Sys.h"
//#include "OsEventGroup.hpp"
#include "..\HardDrivers\Adc\Adc.hpp"
#include "..\HardDrivers\Led\Led.hpp"
#include "..\HardDrivers\Timer\TimerTick.hpp"

/**********************************************************************************/
#define TASK_SYS_EVENT_WAKEUP  (1<<0)  // wakeup from sleep mode
#define TASK_SYS_EVENT_ADC     (1<<1)  // complete ADC


/**********************************************************************************/
//==================================================================================
class TTaskSys
{
public:
	////// variables //////
//	TInterruptController InterruptController;


	////// constants //////

	////// functions //////
    void Run(void);
	EOsResult Init(void);
	void SetEventAdcCompleteFromISR(void);
    void SetEventTimerTickFromISR(void);
    void SetEventRtcWakeUpEventFromISR(void);
    void SysTickFromISR(void);

    void Delay(u16);

  
protected:
	////// variables //////


	////// constants //////


	////// functions //////


  
private:
	////// variables //////
//    TOsEventGroup OsEventGroup;
	TAdc Adc;
	TLed Led;
    TTimerTick TimerTick;

    u16 resultAdc[ADC_NUMBER_OF_CHANNEL];
    u16 valueSensor[ADC_NUMBER_OF_CHANNEL];
    volatile u64 sysTickCounter;
    volatile u16 delayCounter;

    // DEBUG
    float tmpFloat[10];
    u16 wakeUpCounter;
    // DEBUG


	////// constants //////


	////// functions //////
    void ReadAdc(void);

	EOsResult DebugPrint(const char* format, ...);

	//EOsResult CreateOsResources(void);


};
//=== end class TTaskSys ===========================================================

/**********************************************************************************/
#endif
