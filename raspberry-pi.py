import mysql.connector
import time

def wait_minute():
    time.sleep(2)
    
cnx = mysql.connector.connect(user='root', password='0000',
                              host='127.0.0.1',
                              database='robot')

try:
   a = 1;
   while (a == 1): 
      cursor = cnx.cursor()
      cursor.execute("""
         select * from maintable
      """)
      result = cursor.fetchall()
      #print result
      for row in result:
          speed=row[1]
          print speed
          wheel_pos=row[2]
          print wheel_pos
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
      wait_minute()
finally:
    cnx.close()
