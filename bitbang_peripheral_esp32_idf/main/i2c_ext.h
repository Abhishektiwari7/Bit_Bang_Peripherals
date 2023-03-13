/*
Written by Abhishek Tiwari
*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef I2C_EXT_H
#define I2C_EXT_H

//--------header files of architecture-----------
#include <stdio.h>
#include <esp_log.h> //esp logi
#include <freertos/FreeRTOS.h> //task
#include <freertos/task.h> //vtask
//////////////////////////////////////////////////

//-------------internal-functions-----------------
void initI2c ();
//////////////////////////////////////////////////

//------send data over i2c sda--------------------
void send_One_Byte_Data_i2c (uint8_t i2c_Address,uint8_t register_Address, uint8_t data,uint8_t length);
//////////////////////////////////////////////////

//------receive data over i2c sda--------------------
uint8_t receive_One_Byte_Data_i2c (uint8_t i2c_Address,uint8_t register_Address, uint8_t data,uint8_t length);
//////////////////////////////////////////////////



#endif
#ifdef __cplusplus
}
#endif// I2C_EXT