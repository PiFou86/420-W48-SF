const int pinBuzzer = 9;
const int pinLed = LED_BUILTIN;
const int dureePoint = 100;

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop()
{
  afficherChaineV1("SOS");
  afficherChaineV1("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
  delay(1000);
}

void afficherChaineV1(String p_chaine) {
  Serial.println();
  Serial.print(p_chaine + " : ");
  for (int i = 0; i < p_chaine.length(); i++) {
    switch (p_chaine[i]) {
      case 'a':
      case 'A':
		lettreA();
      break;

      case 'b':
      case 'B':
		lettreB();
      break;
      
      case 'c':
      case 'C':
		lettreC();
      break;
      
      case 'd':
      case 'D':
		lettreD();
      break;
      
      case 'e':
      case 'E':
		lettreE();
      break;
      
      case 'f':
      case 'F':
		lettreF();
      break;
      
      case 'g':
      case 'G':
		lettreG();
      break;
      
      case 'h':
      case 'H':
		lettreH();
      break;
      
      case 'i':
      case 'I':
		lettreI();
      break;
      
      case 'j':
      case 'J':
		lettreJ();
      break;
      
      case 'k':
      case 'K':
		lettreK();
      break;
      
      case 'l':
      case 'L':
		lettreL();
      break;
      
      case 'm':
      case 'M':
		lettreM();
      break;
      
      case 'n':
      case 'N':
		lettreN();
      break;
      
      case 'o':
      case 'O':
		lettreO();
      break;
      
      case 'p':
      case 'P':
		lettreP();
      break;
      
      case 'q':
      case 'Q':
		lettreQ();
      break;
      
      case 'r':
      case 'R':
		lettreR();
      break;
      
      case 's':
      case 'S':
		lettreS();
      break;
      
      case 't':
      case 'T':
		lettreT();
      break;
      
      case 'u':
      case 'U':
		lettreU();
      break;
      
      case 'v':
      case 'V':
		lettreV();
      break;
      
      case 'w':
      case 'W':
		lettreW();
      break;
      
      case 'x':
      case 'X':
		lettreX();
      break;
      
      case 'y':
      case 'Y':
		lettreY();
      break;
      
      case 'z':
      case 'Z':
		lettreZ();
      break;
    }
  }
}

void lettreEspace() {
  lectureSequence("       ");
}

void lettreA() {
  lectureSequence(".- ");
}
void lettreB() {
  lectureSequence("-... ");
}
void lettreC() {
  lectureSequence("-.-. ");
}
void lettreD() {
  lectureSequence("-.. ");
}
void lettreE() {
  lectureSequence(". ");
}
void lettreF() {
  lectureSequence("..-. ");
}
void lettreG() {
  lectureSequence("--. ");
}
void lettreH() {
  lectureSequence(".... ");
}
void lettreI() {
  lectureSequence(".. ");
}
void lettreJ() {
  lectureSequence(".--- ");
}
void lettreK() {
  lectureSequence("-.- ");
}
void lettreL() {
  lectureSequence(".-.. ");
}
void lettreM() {
  lectureSequence("-- ");
}
void lettreN() {
  lectureSequence("-. ");
}
void lettreO() {
  lectureSequence("--- ");
}
void lettreP() {
  lectureSequence(".--. ");
}
void lettreQ() {
  lectureSequence("--.- ");
}
void lettreR() {
  lectureSequence(".-. ");
}
void lettreS() {
  lectureSequence("... ");
}
void lettreT() {
  lectureSequence("- ");
}
void lettreU() {
  lectureSequence("..- ");
}
void lettreV() {
  lectureSequence("...- ");
}
void lettreW() {
  lectureSequence(".-- ");
}
void lettreX() {
  lectureSequence("-..- ");
}
void lettreY() {
  lectureSequence("-.-- ");
}
void lettreZ() {
  lectureSequence("--.. ");
}

void lectureSequence(String p_sequence) {
  for (int i = 0; i < p_sequence.length(); i++) {
    switch (p_sequence[i]) {
      case '-':
        digitalWrite(pinLed, HIGH);
        tone(pinBuzzer, 440);
        delay(3 * dureePoint);
        noTone(pinBuzzer);
        digitalWrite(pinLed, LOW);
      break;
      case '.':
        digitalWrite(pinLed, HIGH);
        tone(pinBuzzer, 440);
        delay(dureePoint);
        noTone(pinBuzzer);
        digitalWrite(pinLed, LOW);
      break;
      case ' ':
        delay(2 * dureePoint);
      break;
    }
    delay(dureePoint);
  }
}
