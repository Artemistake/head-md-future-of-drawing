#define POWER_PIN 12
#define SIGNAL_PIN A5
#define LED 13

int value = 0;  // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);    // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW);  // turn the sensor OFF
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);   // turn the sensor ON
  value = analogRead(SIGNAL_PIN);  // read the analog value from sensor

  Serial.print("Sensor value: ");
  Serial.println(value);
  if (value >= 10) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
