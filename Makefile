all:
	g++ i2c.cpp -o i2c.bin -lwiringPi -lrt -pthread
