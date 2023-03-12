#include <stdio.h>
#include <esp_log.h> //esp logi
#include <freertos/FreeRTOS.h> //task
#include <freertos/task.h> //vtask
//gpio
//usart bitbang done
//i2c 
//spi
//v_usb
//------variables for bitbang uart----------
static volatile uint8_t data_bit = 0;
static volatile uint8_t whichbitOut = 10; // start bit: high-low, 8 bit data, 10 th stop bit

////////////////////////////////////////////

//---------------timer isr state machine at baudrate specific------
void stateMachine () { //call me isr
switch (whichbitOut) {
    case 1:
    //clearpin: &= ~(1); go low at start
    whichbitOut = 2; //start to send data
    break;
    
    case 2 ... 9:
    if (data_bit & 0x01) { //check lsb of data is it high(1)?
    //set pin state: |= 1;
    } else { //if lsb low(0)
        //clearpin: &= ~(1);
    }
    data_bit >>= 1; //right shift of given data, to check previous bit of data: 10101 >> 1 = 01010
    whichbitOut++;
    break;
    
    case 10:
    //set pin state: |= 1; , set bit high as normal state
    whichbitOut = 0; //reset state machine, no data left to shift
    break;
}
}
///////////////////////////////////////////////////////////////////
///--------send single byte of data over usart---------------------
void send_One_Byte_Data (uint8_t data) {
data_bit = data;
whichbitOut = 1; //to start state machine
while (whichbitOut) { //wait until previous data being sent 
vTaskDelay(1); 
}
}
///////////////////////////////////////////////////////////////////

//---------------send string of data over serial------------------
void print_String (const char *string) {
while (*string != 0x00) { //send until null character appear in string
send_One_Byte_Data (*string++);
}
}
//////////////////////////////////////////////////////////////////

//----------------send Decimal Digit over usart------------------
void print_Decimal (uint16_t number) {
uint16_t divider = 10000; //5 digit number : 99,999
uint8_t zero = 0;
for (uint8_t g = 0; g < 5; g++) {
    if (number >= divider) {
        zero = 1; //always print zero after printing 1st digit
        send_One_Byte_Data ( ( number / divider ) + 48); //first digit then convert to ascii
        number %= divider; //get reminder and save to number for next digit
    } else if(zero) {
        send_One_Byte_Data ('0'); //send zero
    }
divider /= 10; //next divider for next digit
} 
}
/////////////////////////////////////////////////////////////////
void app_main(void) {
char *str = "Bit Bang Usart data";
print_String (str);
print_Decimal (599);
send_One_Byte_Data (13); //carriage return
send_One_Byte_Data (10); //NL line feed,new line
}
