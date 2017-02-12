  #include <Servo.h> //library for servo drive
  int MotorAPinA = 9;   //pin number for DC drive
  int MotorAPinB = 10;  //pin number for DC drive
  Servo myservo; //create object myservo, class servo from Servo library
  
void setup() {
  // put your setup code here, to run once:
  pinMode(MotorAPinA, OUTPUT);
  pinMode(MotorAPinB, OUTPUT);
  myservo.attach(6); //pin number for servo output
  myservo.write(65);
}

void loop() {
  //analogWrite(MotorAPinA, 240);
}


