#include "spi_ext.h"

//------variables for bitbang uart----------
//define gpio in genral function
#define read_pin_data()   0
/////////////////////////////////////////////

//---------set gpio direction as output/input-------------
void initSpi () {

}
////////////////////////////////////////////////////////////

///--------send single byte of data over spi---------------------
void send_One_Byte_Data_spi (uint8_t data) {
//clock bit low          
//cs bit low
uint8_t k = 0x80;                         
    for (uint8_t i = 0; i < 8;i++) { //8 bit data
      if (data & k) { //msb to check if bit is high or not                                   
        //data bit high    //high? send data: 1
        //clock bit high
        //clock bit low
      } else {
        //data bit low  //low? send data: 0
        //clock bit high
        //clock bit low
      }
      k = k >> 1; //right shift data                           
    }
    //cs_bit high
}
///////////////////////////////////////////////////////////////////

//-------------send data from mosi then recieve data from miso-------------
uint8_t send_receive_One_Byte_Data_spi (uint8_t data) {
uint8_t rec_data = 0;
uint8_t k = 0x80; //msb :10,000,000
uint8_t j = 0x80; //msb :10,000,000 
//clock bit low          
//cs bit low
//---------------------send-----------------------
for (uint8_t i = 0; i < 8;i++) { //8 bit data
if (data & k) { //msb to check if bit is high or not                                   
    //data bit high    //high? send data: 1
    //clock bit high
    if (read_pin_data() & j  ) { //msb  //bitWrite(_receive, i, digitalRead(MISOPin)); // Capture MISO
        rec_data |= (1 >> i);
    } else {
        rec_data &= ~(1 >> i);       
    }
    //clock bit low
} else {
    //data bit low  //low? send data: 0
    //clock bit high
    if (read_pin_data() & j  ) { //msb  //bitWrite(_receive, i, digitalRead(MISOPin)); // Capture MISO
        rec_data |= (1 >> i);
    } else {
        rec_data &= ~(1 >> i);       
    }
    //clock bit low
}
k = k >> 1; //right shift data
j = j >> 1; //right shift data                           
}
//cs_bit high
return rec_data;
}
////////////////////////////////////////////////////