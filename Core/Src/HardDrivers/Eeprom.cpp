/**********************************************************************************/
/**
*  @file
*  Todo: Eeprom.cpp.
*
*/

/**********************************************************************************/
#include "Eeprom.hpp"


/**********************************************************************************/
//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
EOsResult TEeprom::Init(void)
{
    u16 tmpHalfWord;
        
    
    if((*(u8*)(EEPROM_ADDR_T_START_LOG) == 0x55) && (*(u8*)(EEPROM_ADDR_T_START_LOG + 1) == 0xAA))
    {
        tmpHalfWord = *((u16*)EEPROM_ADDR_T_INDEX);
        
        if(tmpHalfWord >= EEPROM_SIZE_T_LOG)
        {
            return(this->FormatLogTemperature());
        }
        
    }
    else
    {
        return(this->FormatLogTemperature());
    }

    
    return(OsResult_Ok);
}
//=== end Init =====================================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
EOsResult TEeprom::WriteLogTemperature(u8 temperature)
{
    u16 index;
  
    
    if(HAL_FLASHEx_DATAEEPROM_Unlock() == HAL_ERROR)
    {
        return(OsResult_EepromUnlockError);
    }
    
    index = *((u16*)(EEPROM_ADDR_T_INDEX));
    
    if(this->WriteByte_withCheck(EEPROM_ADDR_T_START + index, temperature) != OsResult_Ok)
    {
        HAL_FLASHEx_DATAEEPROM_Lock();  
        return(OsResult_EepromProgramError);
    }
    
    index++;
    if(index >= EEPROM_SIZE_T_LOG)
    {
      index = 0;
    }
    
    if(this->WriteHalfWord_withCheck(EEPROM_ADDR_T_INDEX, index) != OsResult_Ok)
    {
        HAL_FLASHEx_DATAEEPROM_Lock();  
        return(OsResult_EepromProgramError);
    }
    
    HAL_FLASHEx_DATAEEPROM_Lock();
    
    
    return(OsResult_Ok);
}
//=== end WriteLogTemperature ======================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
void TEeprom::ReadLogTemperature(u8* buffer, u16 length)
{
    for(u16 i = 0; i < length; i++)
    {
        buffer[i] = *((u8*)(EEPROM_ADDR_T_START + i));
    }
    
}
//=== end ReadLogTemperature =======================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
u16 TEeprom::ReadIndexLogTemperature(void)
{
    return(*((u16*)EEPROM_ADDR_T_INDEX));
}
//=== end ReadLogTemperature =======================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
EOsResult TEeprom::WriteByte_withCheck(u32 address, u8 byte)
{
    u8 readByte;
    u8 writeByte;
    
    
    writeByte = byte;
    if(HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_BYTE, address, writeByte) == HAL_OK)
    {
        readByte = *((u8*)address);
      
        if(writeByte == readByte)
        {
            return(OsResult_Ok);
        }
      
    }
    
    return(OsResult_EepromProgramError);
}
//=== end WriteByte_withCheck ======================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
EOsResult TEeprom::WriteHalfWord_withCheck(u32 address, u16 halfWord)
{
    u16 readHalfWord;
    u16 writeHalfWord;
    
    
    writeHalfWord = halfWord;
    if(HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_HALFWORD, address, halfWord) == HAL_OK)
    {
        readHalfWord = *((u16*)address);
      
        if(writeHalfWord == readHalfWord)
        {
            return(OsResult_Ok);
        }
      
    }
    
    return(OsResult_EepromProgramError);
}
//=== end WriteHalfWord_withCheck ==================================================

//==================================================================================
/**
*  Todo: function description.
*
*  @return void .
*/
EOsResult TEeprom::FormatLogTemperature(void)
{
    if(HAL_FLASHEx_DATAEEPROM_Unlock() == HAL_ERROR)
    {
        return(OsResult_EepromUnlockError);
    }
        
    if(this->WriteByte_withCheck(EEPROM_ADDR_T_START_LOG, 0x55) != OsResult_Ok)
    {
        HAL_FLASHEx_DATAEEPROM_Lock();  
        return(OsResult_EepromProgramError);
    }
    
    if(this->WriteByte_withCheck(EEPROM_ADDR_T_START_LOG + 1, 0xAA) != OsResult_Ok)
    {
        HAL_FLASHEx_DATAEEPROM_Lock();  
        return(OsResult_EepromProgramError);
    }
    
    if(WriteHalfWord_withCheck(EEPROM_ADDR_T_INDEX, 0) != OsResult_Ok)
    {
        HAL_FLASHEx_DATAEEPROM_Lock();  
        return(OsResult_EepromProgramError);
    }
        
    HAL_FLASHEx_DATAEEPROM_Lock();
        
        
    return(OsResult_Ok);
}
//=== end FormatLogTemperature =====================================================

/**********************************************************************************/
