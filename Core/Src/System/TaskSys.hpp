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
#include "OsTask.hpp"
#include "..\HardDrivers\Adc.hpp"
#include "..\HardDrivers\Led.hpp"
#include "..\HardDrivers\Motor.hpp"

/**********************************************************************************/
//#define TASK_SYS_EVENT_TICK      (1<<0)  // tick 1 mSec
#define TASK_SYS_ADC_CONV_CPLT  (1<<0)


/*
    Battery : 3000 mA/hour
    0.020 mA = 150000 hours / 6250 days
    0.300 mA = 10000 hours / 416 days

*/


/**********************************************************************************/
//==================================================================================
class TTaskSys : public TOsTask
{
public:
	////// variables //////
	


	////// constants //////

	////// functions //////
	void CreateTask(void);
	void CreateTaskStatic(void);
	void SetEventTickFromISR(void);
    void SetEventRtcWakeUpEventFromISR(void);
    void SetEventAdcConvCpltFromISR(void);
    
  
protected:
	////// variables //////


	////// constants //////


	////// functions //////


  
private:
	////// variables //////
	StaticTask_t xTaskBuffer;
	StackType_t xStackBuffer[OS_TASK_SYS_SIZE_STACK];
    
    TAdc Adc;
    TLed Led;
    TMotor Motor;
    
    volatile u64 systemCounter;
    float prevTemperature;
    //float curTemperature;
    
    
    // DEBUG
    float tmpFloat[10];
    volatile u64 tmpCounter1;
    volatile u64 tmpCounter2;
    // DEBUG

	
	////// constants //////


	////// functions //////
    
	void Run(void);
    //void ReadAdc(void);
	EOsResult DebugPrint(const char* format, ...);

    EOsResult Init(void);
	EOsResult CreateOsResources(void);


};
//=== end class TTaskSys ===========================================================

/**********************************************************************************/
#endif
