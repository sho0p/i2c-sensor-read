#define I2C_DEV_LOC     (0x2a)

#include <iostream>
#include <errno.h>
#include <wiringPiI2C.h>

using namespace std;




int main(){
    int fd, result;
    
    fd = wiringPiI2CSetup(I2C_DEV_LOC);
    cout << "Initial result: " << fd << endl;
    return 0;
}