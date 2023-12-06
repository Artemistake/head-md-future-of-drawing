#define LED 13
#define BUTTON_PIN 8

float lum = 5;
boolean val = HIGH;
boolean isON = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(LED, LOW);

  Serial.begin(9600);
  Serial.println("Hello World");
}

// void loop() {
//   // put your main code here, to run repeatedly:
//   boolean buttonPressed = digitalRead(BUTTON_PIN);

//   if (buttonPressed) {
//     digitalWrite(LED, LOW);
//   } else {
//     digitalWrite(LED, HIGH);
//   }


//   int freq = 5;  //Hz
//   Serial.print(sin(TWO_PI * freq * millis() / 1000.0));
//   Serial.print("\t");
//   Serial.print(buttonPressed);

//   Serial.println();

//   delay(10);
// }

// void loop() {

//   boolean buttonPressed = digitalRead(BUTTON_PIN);

//   digitalWrite(LED, HIGH);
//   delay(lum);
//   digitalWrite(LED, LOW);
//   delay(20 - lum);
//   lum = lum + 0.5;
//   if (lum > 20) {
//     lum = 0.0;
//   }

//   if (!buttonPressed) {
//     lum = lum + 0.1;
//     if (lum > 20) {
//       lum = 0.0;
//     }
//   }
// }


void loop() {

  morse("SOS IM STARVING PLEASE HELP ME");
}


void morse(String message) {

  for (char c : message) {
    Serial.print(c);

    switch (c) {
      case 'A' : sendSymbols("._") ; break;
      case 'B' : sendSymbols("_..."); break;
      case 'C' : sendSymbols("_._."); break;
      case 'D' : sendSymbols("_.."); break;
      case 'E' : sendSymbols("."); break;
      case 'F' : sendSymbols(".._."); break;
      case 'G' : sendSymbols("__."); break;
      case 'H' : sendSymbols("...."); break;
      case 'I' : sendSymbols(".."); break;
      case 'J' : sendSymbols(".___"); break;
      case 'K' : sendSymbols("_._"); break;
      case 'L' : sendSymbols("._.."); break;
      case 'M' : sendSymbols("__"); break;
      case 'N' : sendSymbols("_."); break;
      case 'O' : sendSymbols("___"); break;
      case 'P' : sendSymbols(".__."); break;
      case 'Q' : sendSymbols("__._"); break;
      case 'R' : sendSymbols("._."); break;
      case 'S' : sendSymbols("..."); break;
      case 'T' : sendSymbols("_"); break;
      case 'U' : sendSymbols(".._"); break;
      case 'V' : sendSymbols("..._"); break;
      case 'W' : sendSymbols(".__"); break;
      case 'X' : sendSymbols("_.._"); break;
      case 'Y' : sendSymbols("_.__"); break;
      case 'Z' : sendSymbols("__.."); break;
    }


    // if (c == 'S') {
    //   ti();
    //   ti();
    //   ti();
    // }
    // if (c == 'O') {
    //   ti();
    //   ti();
    //   ti();
    // }
    // if (c == ' ') {
    //   endOfLetter();
    // }
  }
}

void sendSymbols(String symbols){
  for(char c : symbols){
    switch(c){
      case '.' : ti(); break;
      case '_' : ta(); break;
    }
  

  }
}

void ti() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}

void ta() {
  digitalWrite(LED, HIGH);
  delay(600);
  digitalWrite(LED, LOW);
  delay(200);
}

void endOfLetter() {

  delay(400);
}

void s() {
  ti();
  ti();
  ti();
}

void o() {
  ta();
  ta();
  ta();
}
