#include "i2c_ext.h"

//------variables for bitbang uart----------
//define gpio in genral function

void writeRegister () {

}

uint8_t getvalue =1;

#define SDA_ON          writeRegister ()//define write functions 
#define SDA_OFF         writeRegister ()
#define SDA_READ        getvalue
#define SCL_ON          writeRegister ()
#define SCL_OFF         writeRegister ()
#define SCL_READ        getvalue
#define dly()           writeRegister ()//define delay function //microsecond delay 4.5us
/////////////////////////////////////////////

//------define pin direction output/input--------
void initI2c () {

}
//////////////////////////////////////////////////
//http://www.bitbanging.space/posts/bitbang-i2c
//--------------i2c start sequence---------------
void start(){
SDA_ON;
dly();
SCL_ON;
dly();
SDA_OFF;
dly();
SCL_OFF;
dly();
}
/////////////////////////////////////////////////

//-------------------i2c stop sequence-----------
void stop(){
SDA_OFF;
dly();
SCL_ON;
dly();
SDA_ON;
dly();
}
/////////////////////////////////////////////////////

//------Transmit 8 bit data to slave-----------------
uint8_t Tx (uint8_t dat) {
for (uint8_t i = 8; i; i--) {
    
    (dat & 0x80) ? SDA_ON : SDA_OFF; //Mask for the eigth bit
    dat<<=1;  //Move 
    dly();
    SCL_ON;
    dly();
    SCL_OFF;
    dly();
}
SDA_ON;
SCL_ON;
dly();
uint8_t ack = !SDA_READ;    // Acknowledge bit
SCL_OFF;
return ack;
}

uint8_t Rx (uint8_t ack) {
uint8_t dat = 0;
SDA_ON;
for( uint8_t i =0; i<8; i++){
    dat <<= 1;
    do{
        SCL_ON;
    }while(SCL_READ == 0);  //clock stretching
    dly();
    if(SDA_READ) dat |=1;
    dly();
    SCL_OFF;
}
ack ? SDA_OFF : SDA_ON;
SCL_ON;
dly();
SCL_OFF;
SDA_ON;
return(dat);
}

/*
Start the comunication;
Write to the bus the slave address;
Tell the slave what register you want to write into;
Send the data;
Close the comunication.
*/
  
//------send data over i2c sda--------------------
void send_One_Byte_Data_i2c (uint8_t i2c_Address,uint8_t register_Address, uint8_t data,uint8_t length) {
start();
dly(); //for high freequency //check according to hardware
Tx((i2c_Address<<1)|0x00); // Transfer the slave address plus 
                    // the read write bit (write in this case)
//dly();//SMALL_DLY 
Tx(register_Address); // Register address where we want to write
//dly();//SMALL_DLY 
Tx(data); // Data to be written 
//dly();//SMALL_DLY 
stop();
}
//////////////////////////////////////////////////

//------receive data over i2c sda--------------------
uint8_t receive_One_Byte_Data_i2c (uint8_t i2c_Address,uint8_t register_Address, uint8_t data,uint8_t length) {
uint8_t receive_Data = 0;
start();
Tx((i2c_Address<<1)|0x01);
receive_Data = Rx(0); // End comunication
stop();
return receive_Data;
}
//////////////////////////////////////////////////