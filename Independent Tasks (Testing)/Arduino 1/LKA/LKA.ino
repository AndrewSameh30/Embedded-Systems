#define enA 10  //Enable1 L298 Pin enA
#define in1 9   //Motor1  L298 Pin in1
#define in2 8   //Motor1  L298 Pin in1
#define in3 7   //Motor2  L298 Pin in1
#define in4 6   //Motor2  L298 Pin in1
#define enB 5   //Enable2 L298 Pin enB
#define red 22  //Red LED Pin 22

#define R_S A0  //ir sensor Right
#define L_S A1  //ir sensor Left

void setup() {  // put your setup code here, to run once

  // start serial communication at 9600bps
  Serial.begin(9600);

  pinMode(R_S, INPUT);  // declare ir sensor as input
  pinMode(L_S, INPUT);  // declare ir sensor as input

  pinMode(enA, OUTPUT);  // declare as output for L298 Pin enA
  pinMode(in1, OUTPUT);  // declare as output for L298 Pin in1
  pinMode(in2, OUTPUT);  // declare as output for L298 Pin in2
  pinMode(in3, OUTPUT);  // declare as output for L298 Pin in3
  pinMode(in4, OUTPUT);  // declare as output for L298 Pin in4
  pinMode(enB, OUTPUT);  // declare as output for L298 Pin enB

  pinMode(red, OUTPUT);  // declare as output for Red LED Pin 22

  analogWrite(enA, 95);  // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed
  analogWrite(enB, 95);  // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed

  delay(500);
}

void loop() {
  //if Right Sensor and Left Sensor are at White color then it will call forward function and will turn off LED
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) {
    //Stop();
    forward();
    digitalWrite(red, LOW);
  }
  //if Right Sensor is Black and Left Sensor is White then it will call turn Right function and will turn on LED
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) {
    turnRight();
    digitalWrite(red, HIGH);
  }
  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function and will turn on LED
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) {
    turnLeft();
    digitalWrite(red, HIGH);
  }
  //if Right Sensor and Left Sensor are at Black color then it will call Stop function and will turn off LED
  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)) {
    Stop();
    digitalWrite(red, LOW);
  }
  delay(10);
}

void forward() {            //forward
  digitalWrite(in1, HIGH);  //Right Motor forward Pin
  digitalWrite(in2, LOW);   //Right Motor backword Pin
  digitalWrite(in3, LOW);   //Left Motor backword Pin
  digitalWrite(in4, HIGH);  //Left Motor forward Pin
}

void turnRight() {          //turnRight
  digitalWrite(in1, LOW);   //Right Motor forward Pin
  digitalWrite(in2, HIGH);  //Right Motor backword Pin
  digitalWrite(in3, LOW);   //Left Motor backword Pin
  digitalWrite(in4, HIGH);  //Left Motor forward Pin
}

void turnLeft() {           //turnLeft
  digitalWrite(in1, HIGH);  //Right Motor forward Pin
  digitalWrite(in2, LOW);   //Right Motor backword Pin
  digitalWrite(in3, HIGH);  //Left Motor backword Pin
  digitalWrite(in4, LOW);   //Left Motor forward Pin
}

void Stop() {              //stop
  digitalWrite(in1, LOW);  //Right Motor forward Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, LOW);  //Left Motor backword Pin
  digitalWrite(in4, LOW);  //Left Motor forward Pin
}