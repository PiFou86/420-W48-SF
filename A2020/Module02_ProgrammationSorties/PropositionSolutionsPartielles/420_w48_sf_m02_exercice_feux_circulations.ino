
const int led_rouge = 12;
const int led_orange = 11;
const int led_verte = 10;

void setup()
{
  pinMode(led_rouge, OUTPUT);
  pinMode(led_orange, OUTPUT);
  pinMode(led_verte, OUTPUT);
}

void loop()
{
  int tempsRouge = 5000;
  int tempsOrangeRouge = 1000;
  int tempsVert = 3000;
  int tempsOrange = 1000;
  
  etatRouge(tempsRouge);
  etatOrangeRouge(tempsOrangeRouge);
  etatVert(tempsVert);
  etatOrange(tempsOrange);
}

void etatRouge(int p_delai) {
  digitalWrite(led_rouge, HIGH);
  digitalWrite(led_orange, LOW);
  digitalWrite(led_verte, LOW);

  delay(p_delai);
}

void etatOrangeRouge(int p_delai) {
  digitalWrite(led_rouge, HIGH);
  digitalWrite(led_orange, HIGH);
  digitalWrite(led_verte, LOW);

  delay(p_delai);
}

void etatVert(int p_delai) {
  digitalWrite(led_rouge, LOW);
  digitalWrite(led_orange, LOW);
  digitalWrite(led_verte, HIGH);

  delay(p_delai);
}

void etatOrange(int p_delai) {
  digitalWrite(led_rouge, LOW);
  digitalWrite(led_orange, HIGH);
  digitalWrite(led_verte, LOW);

  delay(p_delai);
}

