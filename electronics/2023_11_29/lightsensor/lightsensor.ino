#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {

  int analogValue = analogRead(A0);
  Serial.print("Analog reading:");
  Serial.print(analogValue);

  if (analogValue < 10) {
    Serial.println("Dark");

    digitalWrite(LED, HIGH);
  } else if (analogValue < 200) {
    Serial.println("Light");

    digitalWrite(LED, LOW);
  }
}
