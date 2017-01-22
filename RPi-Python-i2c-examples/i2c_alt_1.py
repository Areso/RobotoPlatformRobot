import time
import I2C
# connect with device on address 0x23, bus 1
d=I2C.Device(0x23,1)

# function to retry the sending a <byte> to device, at most <times> times
def retry(byte,times):
        s=0
        for i in range(1,times):
                try:
                        print ' {1}'.format(byte,i),
                        # try to send the byte
                        d.writeRaw8(byte)
                        s=1
                # if there is an IOError sending the byte, wait some time
                except IOError,e:
                        time.sleep(0.5*i)
                # if writeRaw8 worked (byte was sent), do not retry
                if s==1:
                        print 'Ok'
                        break;
        if s==0:
                print 'Ko'
        return s
# loop for sending 50 bytes
for i in range(0,50):
        print 'sending {0}'.format(i),
        retry(i,10)
