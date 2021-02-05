/**********************************************************************************/
/**
*  @file
*  Os.hpp - declaration of the class TOs.
*
*/
/**********************************************************************************/
#ifndef __Os_H
#define __Os_H

/**********************************************************************************/
#include "main.h"
#include "stm32l0xx_hal_def.h"
#include "stm32l0xx_hal_dma.h"
#include "stm32l0xx_hal_adc.h"
#include "stm32l0xx_hal_gpio.h"



#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "event_groups.h"
#include "timers.h"
#include "semphr.h"
#include "stream_buffer.h"
//#include "cmsis_os.h"
//#include "mpu_wrappers.h"

/**********************************************************************************/
#define OS_QUEUE_MAX_LENGHT        100
#define OS_QUEUE_MAX_SIZE_ELEMENT  32


/**********************************************************************************/
typedef enum
{
	OsResult_Ok,
	OsResult_Timeout,

	OsResult_ErrorZynqIrq,
	OsResult_ErrorZynqUart,
	OsResult_ErrorUartTransmit,
	OsResult_ErrorUartReceive,

	OsResult_ErrorCreateResource,
	OsResult_ResourceBusy,
	OsResult_QueueEmpty,
	OsResult_QueueFull,
	OsResult_WrongParameter,
      
    OsResult_AdcEndConversion,
    OsResult_AdcStartConversion,
    
    OsResult_EepromUnlockError,
    OsResult_EepromProgramError

} EOsResult;

typedef unsigned char u8;
typedef char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long u64;
typedef long s64;



/**********************************************************************************/
//==================================================================================
class TOs
{
public:
	/// variables ///

	/// constants ///

	/// functions ///
	static void Delay(u64);
	static u32 GetTimeStamp(void);
	static bool IsTimeExpired(u32);


protected:
	/// variables ///

	/// constants ///

	/// functions ///
	

private:
	/// variables ///

	/// constants ///

	/// functions ///


};
//=== end class TOs ================================================================

/**********************************************************************************/
#endif
