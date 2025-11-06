int pirPin = 3;     // PIR sensor output pin
int ledPin = 13;    // LED pin

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(ledPin, HIGH);   // Turn on LED when motion is detected
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW);    // Turn off LED when no motion
    Serial.println("No motion");
  }

  delay(500);
}