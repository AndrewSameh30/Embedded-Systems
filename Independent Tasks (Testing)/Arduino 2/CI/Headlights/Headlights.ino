const int ldrPin = A15;
const int ledPin1 = 39;
const int ledPin2 = 38;

int ldrValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);
  if (ldrValue > 600 && ldrValue < 750) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  } else if (ldrValue > 750) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  delay(100);
}