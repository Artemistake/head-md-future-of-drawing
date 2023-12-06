#define LED 13

int lum = 15;
int blink = 20;

void setup() {
Serial.begin(9600);
pinMode(LED, OUTPUT);
}

void loop() {
  
int value = analogRead(A0);
Serial.println(value);

lum = map(value, 0, 1023, 0, 20);
blink = map(value, 0, 1023, 0, 200);

digitalWrite(LED, HIGH);
delay(15);
digitalWrite(LED, LOW);
delay(blink - 0);
}
