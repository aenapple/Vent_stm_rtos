/**********************************************************************************/
/**
*  @file
*  TimerTick.hpp - declaration of class TTimerTick.
*
*/

/**********************************************************************************/
#ifndef __TimerTick_H
#define __TimerTick_H

/**********************************************************************************/
#include "..\..\System\Sys.h"


/**********************************************************************************/
//==================================================================================
class TTimerTick
{
public:
    ////// variables //////
    

    ////// constants //////


    ////// functions //////
    void Start(void);
    void Stop(void);
    void Delay(u16);
    u64 GetSystemCounter(void);
    void CountCounters(void);
    
  
protected:
	////// variables //////
	

	////// constants //////


	////// functions //////

  
private:
	////// variables //////
    volatile u16 delayCounter;
    volatile u64 systemCounter;


	////// constants //////


	////// functions //////



};
//=== end class TTimerTick =========================================================

/**********************************************************************************/

#endif
