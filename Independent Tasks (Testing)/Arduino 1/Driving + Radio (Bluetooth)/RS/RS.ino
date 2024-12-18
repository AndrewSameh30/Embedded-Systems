#include <Wire.h>
#include <TEA5767.h>

int bt_data;  // variable to receive data from the serial port

TEA5767 radio = TEA5767();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  Wire.begin();
  radio.init(0);
  radio.setMuted(false);
  radio.setStereoNC(true);
  radio.setStandby(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 5 && Serial1.available() < 9) {
    bt_data = Serial1.read();  //if some date is sent, reads it and saves in state
    Serial.println(bt_data);
    radio.setStandby(false);
  }  
  if (bt_data == 6) {
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