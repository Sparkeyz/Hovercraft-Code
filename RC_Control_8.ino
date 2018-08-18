#include<Servo.h>

Servo esc1;
Servo esc2;
Servo esc3;

void setup()
{
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  pinMode(2, INPUT);
  esc1.attach(8);
  esc1.writeMicroseconds(1000);
  esc2.attach(10);
  esc3.attach(12);   
  esc2.writeMicroseconds(1000);
  esc3.writeMicroseconds(1000);
  Serial.begin(9600);
}

void loop() {
  int val;
  int rc4; 
  int rc2; 
  int rc4INT;
  int RotTrim;
  float scale = 0;
  float RightPower;
  float LeftPower; 
  float ForwardPower;
  float throttle;
  RotTrim = pulseIn(5, HIGH, 25000);
  rc2 = pulseIn(2, HIGH, 25000);
  rc4INT = pulseIn(4, HIGH, 25000);
  val = pulseIn(3, HIGH, 25000);
  throttle = map(val, 1020, 1900, 0, 700);
  RotTrim = map(RotTrim, 1000, 1900, -250, 250); 
  rc4 = rc4INT + RotTrim;

  
  if(rc2 > 1480) {//forward power
     ForwardPower = map(rc2, 1480, 1880, 1000, 2000);
  }
  else{
    ForwardPower = 0;
  }
 
  
  if(rc4 > 1500) {//right stick
    scale = map(rc4, 1500, 1870, 0, 100);
    if(scale >100) {
      scale = 100;
    }
    else {
    }
    RightPower = throttle + (throttle*3/7)*(scale/100) + 1000;
    LeftPower  = throttle - (throttle*3/7)*(scale/100) + 1000;
    Serial.print("Right stick: ");
  }

    else if(rc4 < 1420) {//left stick
    scale = map(rc4, 1040, 1420, 100, 0);
    if(scale >100) {
      scale = 100;
    }
    else {
    }
    RightPower = throttle - (throttle*300/700)*(scale/100) + 1000;
    LeftPower  = throttle + (throttle*300/700)*(scale/100) + 1000; 
    Serial.print("Left stick: "); 
  }

  else{
    RightPower = throttle + 1000;
    LeftPower  = throttle + 1000;
    Serial.print("Stick is centered: ");
  }

  if(val == 0 || scale == 373.00){
    Serial.println("Controller is off!");
    scale = 0;
    RightPower = 1020;
    LeftPower = 1020;
  }
  
  int RightPowerAct;
  int LeftPowerAct;
  int ForwardPowerAct;



  RightPowerAct = (int) RightPower;
  LeftPowerAct  = (int) LeftPower; 
  ForwardPowerAct = (int) ForwardPower;

int Test;
Test = pulseIn(6, HIGH, 25000);
  
  esc1.writeMicroseconds(RightPowerAct);
  esc2.writeMicroseconds(LeftPowerAct);
  esc3.writeMicroseconds(ForwardPowerAct);
  Serial.println(scale);
  Serial.println(throttle);
  Serial.println(RightPowerAct);
  Serial.println(LeftPowerAct);
  Serial.println(ForwardPowerAct);
  Serial.println(RotTrim);
  Serial.println(Test);
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
