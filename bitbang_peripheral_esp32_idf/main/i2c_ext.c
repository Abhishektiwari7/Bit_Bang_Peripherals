#include "i2c_ext.h"

//------variables for bitbang uart----------
//define gpio in genral function
//#define read_pin_data()   0
/////////////////////////////////////////////

//------define pin direction output/input--------
void initI2c () {

}
//////////////////////////////////////////////////

//------send data over i2c sda--------------------
void send_One_Byte_Data_i2c (uint8_t i2c_Address,uint8_t register_Address, uint8_t data,uint8_t length) {

}
//////////////////////////////////////////////////

//------receive data over i2c sda--------------------
uint8_t receive_One_Byte_Data_i2c (uint8_t i2c_Address,uint8_t register_Address, uint8_t data,uint8_t length) {
uint8_t receive_Data = 0;

return receive_Data;
}
//////////////////////////////////////////////////