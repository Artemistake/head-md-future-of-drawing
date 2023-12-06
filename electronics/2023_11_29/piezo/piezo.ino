#define PIEZO 9

int freq = 10;


void setup() {
  pinMode(PIEZO, OUTPUT);
}

void loop() {

  int value = analogRead(A0);

  freq = map(value, 0, 1023, 0, 200);

  tone(PIEZO, freq, 1000);

  delay(2000);

  tone(PIEZO, freq);
  delay(1000);
  noTone(PIEZO);
  delay(1000);
}
