#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define SENSOR 7

int step_number = 0;
void setup() {
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);

  Serial.begin(9600);
  pinMode(SENSOR, OUTPUT);
}
void loop() {

  int analogValue = analogRead(A0);
  digitalWrite(SENSOR, HIGH);

  Serial.print("Analog reading:");
  Serial.print(analogValue);


  if (analogValue < 10) {
    Serial.println("Dark");

    digitalWrite(STEPPER_PIN_1, HIGH);
    digitalWrite(STEPPER_PIN_1, LOW);

    delay(2);
  } else if (analogValue < 200) {
    Serial.println("Light");
    digitalWrite(STEPPER_PIN_1, HIGH);
    digitalWrite(STEPPER_PIN_1, LOW);
    delay(2);
  }
}
