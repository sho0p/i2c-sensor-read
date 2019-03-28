#include <iostream>
#include <errno.h>
#include <stdint.h>
#include <wiringPiI2C.h>
#include "i2cdef.h"

using namespace std;

int fd;

uint16_t cdcread(uint8_t chread){
    uint8_t lsb = 
        wiringPiI2CReadReg8(fd, 
        DATAX_LSB + (chread<<1));
    uint8_t msb = 
        wiringPiI2CReadReg16(fd,
        DATAX_MSB + (chread<<1));
    return (msb << 8) | (lsb);
}

int main(){
    int result;
    
    fd = wiringPiI2CSetup(I2C_DEV_LOC);
    cout << "Initial result: " << fd << endl;
    while(1){
        cdcread(0x0);
    }
    result = 0;
    return result;
}

void setup(){
    wiringPiI2CWriteReg8(fd, EN_REG, 
                    CH1EN);
}


