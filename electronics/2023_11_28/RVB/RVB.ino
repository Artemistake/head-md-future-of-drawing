#define LEDR 13
#define LEDV 12
#define LEDB 11



void setup() {

  pinMode(LEDR, OUTPUT);
  pinMode(LEDV, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop() {

digitalWrite(LEDR, HIGH);
delay(300);
digitalWrite(LEDR, LOW);
digitalWrite(LEDV, HIGH);
delay(300);
digitalWrite(LEDV, LOW);
digitalWrite(LEDB, HIGH);
delay(300);
digitalWrite(LEDB, LOW);

}
