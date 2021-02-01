/**********************************************************************************/
/**
*  @file
*  Sys.h - .
*
*/
/**********************************************************************************/
#ifndef __Sys_H
#define __Sys_H

/**********************************************************************************/
#include "main.h"
#include "stm32l0xx_hal_def.h"
#include "stm32l0xx_hal_dma.h"
#include "stm32l0xx_hal_adc.h"
#include "stm32l0xx_hal_gpio.h"

//#include "FreeRTOS.h"
//#include "task.h"
//#include "queue.h"
//#include "event_groups.h"
//#include "timers.h"

/**********************************************************************************/
typedef uint64_t u64;
typedef int64_t s64;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint8_t u8;
typedef int8_t s8;

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
    OsResult_WrongParameter

} EOsResult;

/**********************************************************************************/
#endif
