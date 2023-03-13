/*
Written by Abhishek Tiwari
*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef USART_EXT_H
#define USART_EXT_H

//--------header files of architecture-----------
#include <stdio.h>
#include <esp_log.h> //esp logi
#include <freertos/FreeRTOS.h> //task
#include <freertos/task.h> //vtask
//////////////////////////////////////////////////

//--------------functions--------------------------
void stateMachine ();
void send_One_Byte_Data (uint8_t data);
void print_String (const char *string);
void print_Decimal (uint16_t number);

#endif
#ifdef __cplusplus
}
#endif// USART_EXT