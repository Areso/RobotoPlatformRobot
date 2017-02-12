  #include <Wire.h>     //library for i2c interface
  #include <Servo.h>    //library for servo drive
  int MotorAPinA = 6;   //pin number for DC drive
  int MotorAPinB = 5;   //pin number for DC drive
  int mySpeed = 0;      //drive speed and direction
  Servo myservo;       //create object myservo, class servo from Servo library
  int pos = 0;          //servo drive position
  int data [4];         //array of data from RPi
  int x = 0;
  bool direct = true;

void setup() {
  pinMode(MotorAPinA, OUTPUT);
  pinMode(MotorAPinB, OUTPUT);

  Serial.begin(9600);          //maximum speed for i2c is 9600 bits per second                        
  Wire.begin(0x04);            //address for i2c                          
  Wire.onReceive(receiveData); //callback for i2c. Jump to void recieveData() function when pi sends data
  
  //For servo only 10 and 9 pins of Arduino Uno R3 could use (Timer/Counter T1 16 bit, with tick counter)
  myservo.attach(9); //pin number for servo output. 
  myservo.write(90);
}

void loop() {
  
}

void receiveData(int byteCount) { 
     data[0] = Wire.read();//speed
     mySpeed = data[0];
     Serial.print("Speed is ");
     Serial.print(mySpeed);
     Serial.print("\t");
     data[1] = Wire.read();//wheel angle
     pos     = data[1];
     pos     = 180 - pos;
     Serial.print(pos);

     
     if (mySpeed <= 64) {
       mySpeed = 255-mySpeed*4;
       if (mySpeed < 0) {
         mySpeed = 0;
       }
       Serial.print("revers ");
       Serial.print(mySpeed);
       Serial.print("\t");
       analogWrite(MotorAPinA, 0);
       analogWrite(MotorAPinB, mySpeed);
     } else {
       if (mySpeed >= 128) {
         mySpeed = 2*mySpeed-256;
         if (mySpeed < 0) {
           mySpeed = 0;
         }
         Serial.print("forward ");
         Serial.print(mySpeed);
         Serial.print("\t");
         analogWrite(MotorAPinA, mySpeed);
         analogWrite(MotorAPinB, 0);
       }
     }
     
     myservo.write(pos);
     Serial.print(data[1]);
     Serial.print("\t");
     Serial.print("----");
} 
