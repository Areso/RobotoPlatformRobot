  #include <Servo.h> //library for servo drive
  #include <Wire.h>  //library for i2c interface
  int MotorAPinA = 9;   //pin number for DC drive
  int MotorAPinB = 10;  //pin number for DC drive
  int a = 0; //drive speed and direction
  int mySpeed = 0; //drive speed and direction
  Servo myservo; //create object myservo, class servo from Servo library
  int pos = 60; //servo drive position
  int data [4];//array of data from RPi
  int x = 0;
  bool direct = true;

void setup() {
  Serial.begin(9600);//maximum speed for i2c is 9600 bits per second                        
  Wire.begin(0x04);  //address for i2c                          
  Wire.onReceive(receiveData);               //callback for i2c. Jump to void recieveData() function when pi sends data
  pinMode(MotorAPinA, OUTPUT);
  pinMode(MotorAPinB, OUTPUT);
  myservo.attach(6); //pin number for servo output
  myservo.write(60); 
}

void loop() {
    //analogWrite(MotorAPinA, 240);
    //analogWrite(MotorAPinB, 0);
    delay(1);
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
    myservo.write(pos); 

    
}

