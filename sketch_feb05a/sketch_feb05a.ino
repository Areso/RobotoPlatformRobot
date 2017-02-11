  #include <Servo.h> //library for servo drive
  #include <Wire.h>  //library for i2c interface
  int MotorAPinA = 9;   //pin number for DC drive
  int MotorAPinB = 10;  //pin number for DC drive
  int a = 0; //drive speed and direction
  int mySpeed = 0; //drive speed and direction
  Servo myservo; //create object myservo, class servo from Servo library
  int pos = 0; //servo drive position
  int data [4];//array of data from RPi
  int x = 0;
  
void setup() {
  Serial.begin(9600);//maximum speed for i2c is 9600 bits per second                        
  Wire.begin(0x04);  //address for i2c                          
  Wire.onReceive(receiveData);               //callback for i2c. Jump to void recieveData() function when pi sends data
  pinMode(MotorAPinA, OUTPUT);
  pinMode(MotorAPinB, OUTPUT);
  myservo.attach(6); //pin number for servo output
}

void loop() {
  // put your main code here, to run repeatedly:

}

void receiveData(int byteCount) { 
     data[0] = Wire.read();//speed
     mySpeed = data[0];
     data[1] = Wire.read();//wheel angle
     pos     = data[1];
     if (mySpeed <= 64) {
       mySpeed = 255-mySpeed*4;
       if (mySpeed < 0) {
         mySpeed = 0;
       }
       analogWrite(MotorAPinA, 0);
       analogWrite(MotorAPinB, mySpeed);
     }
     
     if (mySpeed >= 128) {
       mySpeed = 2*mySpeed-256;
       if (mySpeed < 0) {
         mySpeed = 0;
       }
       analogWrite(MotorAPinA, mySpeed);
       analogWrite(MotorAPinB, 0);
     }
     myservo.write(pos);
     //Serial.print(data[0]);
     //Serial.print("\t");
     //Serial.print(data[1]);
     //Serial.print("\t");
     //Serial.print(data[2]);
     //Serial.print("\t");
     //Serial.println(data[3]);
     //Serial.print("----");
  


   ///while(Wire.available()) {               //Wire.available() returns the number of bytes available for retrieval with Wire.read(). Or it returns TRUE for values >0.
      // data[x]=Wire.read();
      // x++;
      // if (x > 4) {
      //   x=0;
      // }
    // }
     //Serial.println("----");
} 
