/**********************************************************************************/
/**
*  @file
*  OsQueue.hpp - declaration of the class TOsQueue.
*
*/
/**********************************************************************************/
#ifndef __OsQueue_H
#define __OsQueue_H

/**********************************************************************************/
#include "Os.hpp"

/**********************************************************************************/
//==================================================================================
/**
*
*/
class TOsQueue : public TOs
{
public:
	/// variables ///

	/// constants ///

	/// functions ///
	TOsQueue(void);
	EOsResult Create(u8, u8);
	void Reset(void);
	QueueHandle_t GetHandle(void);
	EOsResult Receive(void*, TickType_t);
	EOsResult Send(void*, TickType_t);
	void SendFromISR(void*);


protected:
	/// variables ///

	/// constants ///

	/// functions ///


private:
	/// variables ///
	QueueHandle_t QueueHandle;

	/// constants ///

	/// functions ///


};
//=== end class CQueue =============================================================

/**********************************************************************************/
#endif
