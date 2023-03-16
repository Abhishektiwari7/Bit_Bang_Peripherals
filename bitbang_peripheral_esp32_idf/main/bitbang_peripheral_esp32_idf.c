#include <stdio.h>
#include <esp_log.h> //esp logi
#include <freertos/FreeRTOS.h> //task
#include <freertos/task.h> //vtask

//gpio
#include "usart_ext.h"//usart bitbang done
#include "i2c_ext.h"  //i2c 
#include "spi_ext.h" //spi
//v_usb

void app_main(void) {

//uart example-----------------
char *str = "Bit Bang Usart data";
print_String (str);
print_Decimal (599);
send_One_Byte_Data (13); //carriage return
send_One_Byte_Data (10); //NL line feed,new line

/////////////////////////////////

//spi example-------------------
uint8_t transmit_data = 0;
initSpi ();
send_One_Byte_Data_spi (transmit_data);
uint8_t got_it = send_receive_One_Byte_Data_spi (transmit_data);

////////////////////////////////

//i2c example-------------------
initI2c ();
uint8_t i2c_Address = 0x01,register_Address = 0x02, data = 0x03,length = 1;
send_One_Byte_Data_i2c (i2c_Address,register_Address,data,length);
uint8_t receive_data = receive_One_Byte_Data_i2c (i2c_Address,register_Address,data,length);
////////////////////////////////

//usb example-------------------
////////////////////////////////
}
