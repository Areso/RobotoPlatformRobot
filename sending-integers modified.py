import smbus
import time

bus = smbus.SMBus(1)
address = 0x04

def writeNumber(a,b):
    bus.write_i2c_block_data(address, a, [b])
    return -1


while True:
    try:   
        writeNumber(12,22)
        time.sleep(1)                    #delay one second

    except KeyboardInterrupt:
        quit()
