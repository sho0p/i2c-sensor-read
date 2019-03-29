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
    wiringPiI2CReadReg8(fd, STAT_REG); //to lock the data
    uint8_t lsb =
        wiringPiI2CReadReg8(fd, 
        DATA0_LSB );
    uint8_t msb = 
        wiringPiI2CReadReg8(fd,
        DATA0_MSB );
    cout << "Read on channel 0: " << ((msb << 8) | (lsb)) << endl;
}
void setup(){
    cout << "Starting setup..." << endl;
	pinMode(INTB_PIN, INPUT);
    cout << "Entering Config Mode..."<< endl;
    wiringPiI2CWriteReg8(fd, RESET_REG, CONFIG_MODE_ON);
    cout <<"Waiting to write to enable..." << endl;
    while( !(wiringPiI2CReadReg8(fd, STAT_REG)&& (1 << 5) ) )
    wiringPiI2CWriteReg8(fd, EN_REG, 
                    CH1EN);
    wiringPiI2CWriteReg8(fd, NP_SCAN_RATE, 0b11);
    cout << "Exiting Config Mode..." << endl;
    wiringPiI2CWriteReg8(fd, RESET_REG, CONFIG_MODE_OFF);
    cout << "Finished setup!" << endl;

}
int main(){
    int result;
    
    fd = wiringPiI2CSetup(I2C_DEV_LOC);
    cout << "Issue with the interrupt?" <<endl;
//        wiringPiISR(INTB_PIN, INT_EDGE_RISING, *cdc0read);
    cout << "Initial result: " << fd << endl;
    setup();
    cout << "Starting reads." << endl;
    while(1){
	cdc0read();
	usleep(100000);
    }
    result = 0;
    return result;
}




