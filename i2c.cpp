#include <iostream>
#include <errno.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "i2cdef.h"

using namespace std;

int fd;

uint16_t cdcread(uint8_t chread){
        wiringPiI2CReadReg8(fd, 
        DATAX_LSB + (chread<<1));
    uint8_t msb = 
        wiringPiI2CReadReg8(fd,
        DATAX_MSB + (chread<<1));
    return (msb << 8) | (lsb);
}
void setup(){
    cout <<"Waiting to write to enable..." << endl;
    while(!WiringPiI2CReadReg8(fd, STAT_REG & 0x20)){
    }
    wiringPiI2CWriteReg8(fd, EN_REG, 
                    CH1EN);
}
int main(){
    int result;
    
    fd = wiringPiI2CSetup(I2C_DEV_LOC);
    wiringPiISR(INTB_PIN, INT_EDGE_RISING, *cdcread);
    cout << "Initial result: " << fd << endl;
    setup();
    while(1){
        cout << "Read on channel 0: " << cdcread(0x0)<< endl;
    }
    result = 0;
    return result;
}




