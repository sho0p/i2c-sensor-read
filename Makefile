all:
	g++ i2c.cpp -o i2c.bin -lwiringPi -lrt -pthread -I/usr/local/include -L/usr/local/lib -lcrypt
