# Module 12 - Afficheur 4Digits

## Exercice 1 - Programme de test

### Matériel

- TinkerCad avec le programme [420-W48-SF Base 4 digits - Pub](https://www.tinkercad.com/things/7Ha0tayTvkk).

### Étape 1 - Analyser le code

- Adaptez le progamme pour ajouter des commentaires au programme qui servira de test pour les montages de l'afficheur 4 X 7-segments.

### Étape 2 - Affichage de nombres

- Ajoutez la fonction AfficherNombre() pour afficher les chiffres, de "0" à "F" sur les 4 digits, à tour de rôle, de gauche à droite. Prévoir une durée de 200 msecondes entre chaque affichage.
- Ajoutez une séquence,  en affichant les chiffres de "F" à "0", de droite à gauche avec le point décimal allumé durant cette séquence.

## Exercice 2 - Affichage de nombre sur 4 digits

### Matériel

- TinkerCad avec le programme [420-W48-SF Base 4 digits - Pub](https://www.tinkercad.com/things/7Ha0tayTvkk)

### Étape 1 - Affichage de nombres

- Adaptez le progamme pour affichez le nombre 1234. Faire clignoter chaque chiffre à tour de rôle pendant 1/2 seconde , en débutant par le "1" puis par le "4".
- Affichez les nombres de 0 à 9999.

### Étape 2 - Choix d'un nombre à afficher

- Saisissez un nombre à la console et affichez-le. Affichez la barre basse (segment C) lorsque le nombre est plus petit que zéro et la barre haute (lettre "A") lorsque le nombre excède 9999.

<details>
<summary>Indice</summary>

```cpp
const int longChaine = 4;
char  chiffre[longChaine + 1] ;
void setup() {
  Serial.begin(9600);
  Serial.println("Quel nombre voulez-vous afficher?");

  while (!Serial.available()) {};

  int n = Serial.readBytesUntil('\n', chiffre, longChaine);

  chiffre[n]= '\0';
  Serial.println(chiffre); 

  while (true) {;};
}

void loop() {
  ;
}
```

</details>

## Exercice 3 - Le Multimètre

### Matériel

- Circuit TinkerCad avec potentiomètre et afficheur 4X 7Digits

![2 MultimetreArduino](img/AffichagePotentiometre.PNG)

- Affichez la valeur de résistance'un potentiomètre, entre 0000 et 1023, à différentes positions.  

## Exercice 4 - Le Cadran (optionnel)

### Matériel

- Circuit TinkerCad avec afficheur 4X 7Digits

- Programmez un cadran (horloge numérique). Proposez une méthode pour programmer l'heure et les minutes.
