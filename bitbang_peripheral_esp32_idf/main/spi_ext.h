/*
Written by Abhishek Tiwari
*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef SPI_EXT_H
#define SPI_EXT_H

//--------header files of architecture-----------
#include <stdio.h>
#include <esp_log.h> //esp logi
#include <freertos/FreeRTOS.h> //task
#include <freertos/task.h> //vtask
//////////////////////////////////////////////////

//--------------functions--------------------------
void initSpi ();
void send_One_Byte_Data_spi (uint8_t data);
uint8_t send_receive_One_Byte_Data_spi (uint8_t data);

#endif
#ifdef __cplusplus
}
#endif// SPI_EXT