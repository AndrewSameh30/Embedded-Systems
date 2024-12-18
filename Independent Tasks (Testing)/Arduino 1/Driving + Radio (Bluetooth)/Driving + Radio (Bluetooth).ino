#include <Wire.h>
#include <TEA5767.h>

#define enA 10  //Enable1 L298 Pin enA
#define in1 9   //Motor1  L298 Pin in1
#define in2 8   //Motor1  L298 Pin in1
#define in3 7   //Motor2  L298 Pin in1
#define in4 6   //Motor2  L298 Pin in1
#define enB 5   //Enable2 L298 Pin enB

int bt_data;  // variable to receive data from the serial port

TEA5767 radio = TEA5767();

void setup() {

  // start serial communication at 9600bps
  Serial.begin(9600);
  Serial1.begin(9600);

  Wire.begin();
  radio.init(0);
  radio.setMuted(false);
  radio.setStereoNC(true);
  radio.setStandby(true);

  pinMode(enA, OUTPUT);  // declare as output for L298 Pin enA
  pinMode(in1, OUTPUT);  // declare as output for L298 Pin in1
  pinMode(in2, OUTPUT);  // declare as output for L298 Pin in2
  pinMode(in3, OUTPUT);  // declare as output for L298 Pin in3
  pinMode(in4, OUTPUT);  // declare as output for L298 Pin in4
  pinMode(enB, OUTPUT);  // declare as output for L298 Pin enB

  analogWrite(enA, 95);  // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed
  analogWrite(enB, 95);  // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed

  delay(500);
}

void loop() {
  //if some date is sent, reads it and saves in state
  if (Serial1.available() > 0 && Serial1.available() < 6) {
    bt_data = Serial1.read();  //if some date is sent, reads it and saves in state
    Serial.println(bt_data);
  }
  if (bt_data > 5 && bt_data < 9) {
    radio.setStandby(false);
  }
  // if the bt_data is '1' the DC motor will go forward
  if (bt_data == 1) {
    forward();
  }
  // if the bt_data is '2' the motor will Reverse
  else if (bt_data == 2) {
    backward();
  }
  // if the bt_data is '3' the motor will turn left
  else if (bt_data == 3) {
    turnLeft();
  }
  // if the bt_data is '4' the motor will turn right
  else if (bt_data == 4) {
    turnRight();
  }
  // if the bt_data '5' the motor will Stop
  else if (bt_data == 5) {
    Stop();
  } else if (bt_data == 6) {
    radio.setFrequency(90.89);
  } else if (bt_data == 7) {
    radio.setFrequency(105.30);
  } else if (bt_data == 8) {
    radio.setFrequency(105.80);
  } else if (bt_data == 9) {
    radio.setStandby(true);
  }
  delay(10);
}

void forward() {            //forward
  digitalWrite(in1, HIGH);  //Right Motor forward Pin
  digitalWrite(in2, LOW);   //Right Motor backword Pin
  digitalWrite(in3, LOW);   //Left Motor backword Pin
  digitalWrite(in4, HIGH);  //Left Motor forward Pin
}

void backward() {           //backward
  digitalWrite(in1, LOW);   //Right Motor forword Pin
  digitalWrite(in2, HIGH);  //Right Motor backword Pin
  digitalWrite(in3, HIGH);  //Left Motor backword Pin
  digitalWrite(in4, LOW);   //Left Motor forword Pin
}

void turnLeft() {           //turnLeft
  digitalWrite(in1, LOW);   //Right Motor forward Pin
  digitalWrite(in2, HIGH);  //Right Motor backword Pin
  digitalWrite(in3, LOW);   //Left Motor backword Pin
  digitalWrite(in4, HIGH);  //Left Motor forward Pin
}

void turnRight() {          //turnRight
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