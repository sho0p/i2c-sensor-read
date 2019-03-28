import smbus

channel 0

address = 0x2A

bus = smbus.SMBus(channel)







def setup():
   bus.write_i2c_block_ 