#include<Servo.h>

Servo esc;

void setup()
{
  pinMode(3, INPUT);
  esc.attach(8);
  esc.writeMicroseconds(1000);
  Serial.begin(9600);
}

void loop() {
  int val;
  val = pulseIn(3, HIGH, 25000);
  val = map(val, 1025, 1875, 1000, 2000);
  esc.writeMicroseconds(val);
  Serial.println(val);
  delay(500);
  
    
    //int rc3 = pulseIn(3, HIGH, 25000);
  
//  pwm = map(rc3, 1025, 1875, 1000, 2000);
//  digitalWrite(in1, HIGH);

  
//  int v = pulseIn(3, HIGH, 25000);
  //Serial.printIn(v);
  //delay(500);

//  int val;
// digital 
//  val= analogRead(A0);
//  val= map(val, 0, 1023, 1000,2000);
//  esc.writeMicroseconds(val);
  // put your main code here, to run repeatedly:

}
