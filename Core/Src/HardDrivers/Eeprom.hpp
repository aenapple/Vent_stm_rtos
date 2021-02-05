/**********************************************************************************/
/**
*  @file
*  Eeprom.hpp - declaration of class TEeprom.
*
*/

/**********************************************************************************/
#ifndef __Eeprom_H
#define __Eeprom_H

/**********************************************************************************/
#include "..\Os\Os.hpp"

/**********************************************************************************/
#define EEPROM_ADDR_START  0x08080000
#define EEPROM_ADDR_END    0x080803FF

#define EEPROM_SIZE_T_LOG        288                         // 12 (1 hour) * 24 = 288 bytes
#define EEPROM_ADDR_T_START_LOG  (EEPROM_ADDR_START)         // 2 bytes
#define EEPROM_ADDR_T_START      (EEPROM_ADDR_T_START_LOG + 2)
#define EEPROM_ADDR_T_END        (EEPROM_ADDR_T_START + EEPROM_SIZE_T_LOG)
#define EEPROM_ADDR_T_INDEX      (EEPROM_ADDR_T_END)         // 2 bytes




/**********************************************************************************/
//==================================================================================
class TEeprom
{
public:
    ////// variables //////
    

    ////// constants //////


    ////// functions //////
    EOsResult Init(void);
    EOsResult WriteLogTemperature(u8);
    void ReadLogTemperature(u8*, u16);
    u16 ReadIndexLogTemperature(void);
    
    
  
protected:
	////// variables //////
	

	////// constants //////


	////// functions //////

  
private:
	////// variables //////
    

	////// constants //////


	////// functions //////
    EOsResult FormatLogTemperature(void);
    EOsResult WriteByte_withCheck(u32, u8);
    EOsResult WriteHalfWord_withCheck(u32, u16);
    



};
//=== end class TEeprom ============================================================

/**********************************************************************************/

#endif
