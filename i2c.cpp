#include <iostream>
#include <errno.h>
#include <stdint.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include "i2cdef.h"

using namespace std;

int fd;

void cdcread(){
    uint8_t lsb =
        wiringPiI2CReadReg8(fd, 
        DATA0_LSB );
    uint8_t msb = 
        wiringPiI2CReadReg8(fd,
        DATA0_MSB );
    cout << "Read on channel 0: " << ((msb << 8) | (lsb));
}
void setup(){
    cout <<"Waiting to write to enable..." << endl;
    while(!wiringPiI2CReadReg8(fd, STAT_REG & 0x20)){
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
    while(1);
    result = 0;
    return result;
}




