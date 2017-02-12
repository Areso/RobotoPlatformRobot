import mysql.connector
import time
import smbus

bus = smbus.SMBus(1)
address = 0x04

def wait_myperiod():
    time.sleep(0.001)

def writeNumber(a,b):
    bus.write_i2c_block_data(address, a, [b])
    return -1
    
cnx = mysql.connector.connect(user='root', password='0000',
                              host='127.0.0.1',
                              database='robot')
prev_speed     = -1
prev_wheel_pos = -1
changing = False
a = 1;
try:
   while (a == 1):
      changing = False 
      cursor = cnx.cursor()
      cnx.autocommit=True
      #cnx.autocommit(True) for Python 3+
      cursor.execute("""
         select * from maintable
      """)
      result = cursor.fetchall()
      for row in result:
          speed=row[1]
          if prev_speed != speed:
              prev_speed = speed
              changing   = True
              print result
              print speed
          #print speed
          wheel_pos=row[2]
          if prev_wheel_pos != wheel_pos:
              prev_wheel_pos = wheel_pos
              changing       = True
              print result
              print wheel_pos
          #print wheel_pos
          xy_axis_cam=row[3]
          #print xy_axis_cam
          z_axis_cam=row[4]
          #print xy_axis_cam
          cam_power=row[5]
          #print cam_power
          action=row[6]
          #print action
          battery_status=row[7]
          #print battery_status
      if changing == True:
          writeNumber(speed,wheel_pos)
      wait_myperiod()
finally:
    cnx.close()    
