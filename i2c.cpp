#include <iostream>
#include <errno.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <unistd.h>
#include "i2cdef.h"

using namespace std;

int fd;

void cdc0read(){
    uint8_t lsb =
        wiringPiI2CReadReg8(fd, 
        DATA0_LSB );
    uint8_t msb = 
        wiringPiI2CReadReg8(fd,
        DATA0_MSB );
    cout << "Read on channel 0: " << ((msb << 8) | (lsb)) << endl;
}
void setup(){
	pinMode(INTB_PIN, INPUT);
    cout <<"Waiting to write to enable..." << endl;
    while(!, *cdc0read);TAT_RE(fd, G & 0x20)){
    }
    wiringPiI2CWriteReg8(fd, EN_REG, 
                    CH1EN);
}
int main(){
    int result;
    
    fd = wiringPiI2CSetup(I2C_DEV_LOC);
    cout << "Issue with the interrupt?" <<endl;
        wiringPiISR(INTB_PIN, INT_EDGE_RISING, *cdc0read);
    cout << "Initial result: " << fd << endl;
    setup();
    while(1){
	}
    result = 0;
    return result;
}




