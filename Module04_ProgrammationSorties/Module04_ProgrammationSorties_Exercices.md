# Module 02 - Programmation des sorties

## Exercice 1 - Platine d'expérimentation

### Objectif

Valider votre compréhension de la platine d'expérimentation

### Environnement et matériel

- Une platine d’essais
- Un multimètre, avec les sondes et les câbles à pinces crocodile à double extrémité
- Deux fils dupont mâle-mâle

### Tests à effectuer

- Connectez correctement vos sondes au multimètre
- Connectez chaque cable à pinces crocodile sur une sonde
- Connectez l'autre extrémité des pinces crocodile à un fils dupont
- Mettez le multimètre en position ohmmètre (Symbole Ω)
- Sondez différent endroit de la platine d'expérimentation afin de valider la conductivité et par la même votre compréhension des chemins électriques

## Exercice 2 - Résistance en série - On est tous solidaires !

**L'exercice se passe sans Arduino, ni DELs, ni alimentation**

### Objectif

Observer le comportement de deux résistances branchées en série. [Lire la définition](https://fr.wikibooks.org/wiki/Électricité/Les_circuits_série_et_parallèles#Les_circuits_série_et_parallèle)

### Environnement et matériel

- Une platine d’essais
- 2 résistances de même valeur
- Un multimètre

### Instructions

- Sur papier, dessinez le circuit de deux résistances de même valeur en série
- Effectez le montage sur la plaquette d'expérimentations, non alimenté
- Mesurez la résistance globale avec un multimètre

<details>
    <summary>Solution</summary>

Vous devriez mesurer une résistance totale d'environ du double de la valeur de chaque résistance (Ex. : avec deux 220 Ω, vous aurez 440 Ω)

</details>

## Exercice 3 - Résistance en parallèle - On résiste de manière individuelle !

**L'exercice se passe sans Arduino, ni DELs, ni alimentation**

### Objectif

Observer le comportement de deux résistances branchées en parallèle. [Lire la définition](https://fr.wikibooks.org/wiki/Électricité/Les_circuits_série_et_parallèles#Les_circuits_série_et_parallèle)

### Environnement et matériel

- Une platine d’essais
- 2 résistances de même valeur
- Un multimètre

### Instructions

- Sur papier, dessinez le circuit de deux résistances de même valeur en série
- Effectez le montage sur la plaquette d'expérimentations, non alimenté
- Mesurez la résistance globale avec un multimètre

<details>
    <summary>Solution</summary>

Vous devriez mesurer une résistance totale d'environ 1/2 de la valeur des résistances (Ex. : avec deux 220 Ω, vous aurez 110 Ω)

</details>

## Exercice 4 - Allumer une LED

### Objectifs

- Valider l'utilisation de votre prototype.
- Allumer une DEL

### Environnement et matériel

- Arduino UNO
- Choix 1 :
  - Une platine d’essais
  - Une LED rouge
  - 1 résistance supérieure à 220 Ohms
- OU Choix 2 :
  - Le prototype que vous avez soudé
- Coffret de pièces et outils

### À coder

- Démarrez un nouveau projet PIO. Nommez-le "AMOC_Module04_DELsClignotes"
- Écrivez la fonction setup qui :
  - Configure une des bornes en sorties
- Écrivez la fonction loop qui :
  - Met la borne choisie à HIGH
  - Attend 500ms
  - Met la borne choisie à LOW
  - Attend 500ms
- Compilez et téléversez le programme sur votre platine Arduino

## Exercice 5 - Observation du LMI

### Objectif

Observer le LMI à l'oscilloscope.

### Environnement et matériel

- Arduino UNO
- Coffret de pièces et outils
- Oscilloscope

### Observations

- Sur votre Arduino, repérez les 6 bornes digitales qui permettent le LMI (Elles sont identifiées avec un ~)
- Démarrez un nouveau projet PIO. Nommez-le "AMOC_Module04_Observation LMI"
- Écrivez un programme qui :
  - Configure ces 6 bornes en sorties
  - Envoi un signal carré avec un rapport cyclique de 50% sur chacune des bornes
- Compilez et téléversez le programme sur votre platine Arduino
- À l'aide de deux fils dupont male-male, un pour la borne GND et l'autre pour une des 6 bornes :
  - Calculez le temps en deux fronts montants et déduisez-en la fréquence
  - Validez que le rapport cyclique est bien de 50%
- Modifiez votre programme pour avoir un rapport cyclique de 75% et validez ce qui a changé à l'affichage dans l'oscilloscope

## Exercice 6 - Contrôle de l'intensité de DELs

Les entrées numériques peuvent simuler une entrée analogique grâce à la technologie LMI.

![Duty cycle](img/DutyCycle.png)

### Objectif

Contrôler la luminosité d'une DEL avec la LMI.

### Environnement et matériel

- Arduino UNO
- Choix 1 :
  - Une platine d’essais
  - Une LED rouge
  - 1 résistance supérieure à 220 Ohms
- OU Choix 2 :
  - Le prototype que vous avez soudé
- Coffret de pièces et outils

### Directives

**Toujours étaler les articles sur le tapis de protection avant de débuter.**

### Sketch AMOC_Module04_VariationMLI

#### Montage du circuit si fait sur la platine d'essais

Représentation physique :

![Représentation physique](img/MLIPysique.png)

Représentation schématique :

![Représentation schématique](img/FadeSchema.PNG)

- **AVANT d'alimenter votre circuite** :
  - Validez vos connections
  - Validez la valeur de votre résistance
  - Validez le sens de connexion de la DEL
  - Validez qu'il n'y a rien de conducteur / métallique qui pourrait créer un court-circuit dans votre montage

- Démarrez un nouveau projet PIO. Nommez-le "AMOC_Module04_VariationMLI"
- Programmez le sketch pour faire varier l'intensité de 0 à 255 avec un pas de 5 toute les 500ms
- Compilez le programme, corrigez les erreurs si nécessaire
- Connectez votre plaquette de développement à votre ordinateur par le cable USB et compilez et téléverser le programme
- ***Si le sketch ne fonctionne pas, débranchez le câble USB***

<details>
    <summary>Dépannage circuit</summary>

1. Avez-vous polarisé la DEL dans le bon sens?
2. La valeur des résistances est-elle suppérieure à 220 Ohms?
3. Le fil noir est-il branché sur la borne GND (mise à la terre)?
    - par convention, le fil noir se branche à la terre
    le fil rouge à l'alimentation

Vérifiez votre circuit attentivement avec les points cités au-dessus.

</details>

#### Questions de réflexion

- Quelle est la valeur de la période du cycle pour evolutionPas = 5 ?  
- Quelle doit être la valeur de evolutionPas pour une période de cycle de 75 % ?
- Quel effet se produit-il si la période de cycle est de 75 % ?
- Changez la résistance du circuit pour 560 Ohms. Qu'observez-vous ?

## Exercice 7 - Mesure du temps de l'exécution

### Objectif

Observer le temps d'execution d'un code.

### Environnement et matériel

- Arduino UNO
- Coffret de pièces et outils
- Oscilloscope

### Observations

- Démarrez un nouveau projet PIO. Nommez-le "AMOC_Module04_Temps d'execution"
- Tapez le code suivant dans la méthode loop :

```cpp
int valeurIncrement = 0;
const int pinMesureTemps = 2;

void setup() {
    pinMode(pinMesureTemps, OUTPUT);
}

void loop() {
    digitalWrite(pinMesureTemps, LOW);

    valeurIncrement++;
    valeurIncrement = valeurIncrement % 8;

    digitalWrite(pinMesureTemps, HIGH);
}
```

- Téléverser le programme sur votre arduino et mesure le temps d'exécution d'un "tour de boucle" (i.e. d'appel de la fonction loop)
- Modifiez la fonction loop pour :

```cpp
void loop() {
    digitalWrite(pinMesureTemps, LOW);

    valeurIncrement++;
    if (valeurIncrement > 8)
    {
        valeurIncrement -= 8;
    }

    digitalWrite(pinMesureTemps, HIGH);
}
```

- Téléverser le programme sur votre arduino et mesure le temps d'exécution d'un "tour de boucle" (i.e. d'appel de la fonction loop)
- Qu'observez-vous ?

## Exercice 8 - Feux de circulation (Optionnel)

L’exercice présenté ici représente un carrefour urbain simple contrôlé par un système de signalisation: Rouge, Jaune, Verte.

Le système passe périodiquement de Rouge au vert avec une transition préalable au jaune. Les durées sont différentes. Selon le tableau suivant,

### Objectif

Contrôler plusieurs DELs avec des durées variables.

### Environnement et matériel

- Arduino UNO
- Une platine d’essais
- Une DEL rouge, une jaune et une verte
- 3 résistances de 220 Ohms
- Coffret de pièces et outils

### Directives

**Toujours étaler les articles sur le tapis de protection avant de débuter.**

### Sketch FeuDeCirculation.ino

L’image suivante donne la séquence d’éclairage des feux de circulation. Votre tâche consiste à programmer l’Arduino pour reproduire cette séquence en respectant les durées suivantes.
 ![feu de circulation](img/FeuCirculation.png)

|Séquence  |Image|Durées|Rouge   |Jaune   |Vert    |
|:--------:|-----|------|--------|--------|--------|
|startup() |1    |5 sec.|allumé  |éteinte |éteinte |
|loop()	   |2	 |1 sec.|allumé  |allumé  |éteinte |
|          |3    |3 sec.|éteinte |éteinte |allumé  |
|          |4    |1 sec.|éteinte |allumé  |éteinte |
|          |1    |3 sec.|allumé	 |éteinte |éteinte |
|          |...  |...   |...     |...     |...     |

### Montage du circuit

**TOUJOURS débrancher la carte Arduino lorsque vous modifiez votre circuit**

- Branchez le circuit de la façon suivante :

![Représentation physique](img/FeuxCirculationBase.png)

Représentation schématique:

![Représentation schématique](img/SchemaFeuCirculationBase.png)

- Ce sont les bornes 12, 11 et 10 sont utilisées.
- Vérifiez SANS brancher
- Démarrez une nouvelle application Arduino. Nommez-la "FeuDeCirculation.ino"
- Programmez FeuDeCirculation.ino selon les délais prescrits dans le tableau plus haut et envoyé votre programme sur la carte.
- Si le sketch ne fonctionne pas, débranchez le câble USB.

<details>
    <summary>Dépannage circuit</summary>

Vérifiez votre circuit attentivement avec les points cités au-dessus.

</details>

### Tests par partie

Utilisez la technique suivante :

- Remplacez le programme de l'exercice 1 du module 1
- Changez LED_BUILTIN par la valeur 12. Téléversez le sketch.
- La DEL rouge doit clignoter, sinon dépannez cette partie du circuit.
- Faites de même pour les bornes 11 et 10.

## Exercice 9 - Code Morse (Optionnel)

### Objectif

Transmettre une chaîne de caractère en Morse

### Environnement et matériel

- Arduino UNO
- Une platine d’essais
- Une ampoule DEL rouge
- 1 résistance suppérieure à 220 Ohms
- Coffret de pièces et outils

### Directives

**Toujours étaler les articles sur le tapis de protection avant de débuter.**

### Instructions

- Démarrez une nouvelle application Arduino. Nommez-la "CodeMorse.ino"

Le sketch doit faire clignoter le texte d'une chaîne de caractères : Considérez que vous avez simplement les caractères de a à z en majuscule ou minuscule et l'espace. Exemple : "bonjour a tous". La chaine de caractère doit pouvoir être modifiée sans avoir à réécrire tout le programme.

Pour manipuler des chaînes de caractères, n'utilisez pas la bibliothèques standard de C++, utilisez la classe "String" (notez le "S" majuscule !) définie par la bibliothèque fournie avec Arduino IDE.

La fonction loop() appelle la fonction afficherChaine qui reçoit la chaîne de caractère au complet comme argument comme celle-ci :

```cpp
void loop()
{
    String chaine = "bonjour a tous";
    afficherChaine(chaine);
    delay(1000);
}
```

Le code morse à coder est [le code international que vous trouverez sur l'image der wikipédia](https://fr.wikipedia.org/wiki/Code_Morse_international).

Un "-" correspond à la durée de 3 ".". Le changement de lettre (ici, représenté par un espace " ") correspond à un temps équivalent à 3 points. Un espace est équivalent à 7 points.

- Utilisez un texte qui couvre l'ensemble des lettres de l'alphabet, majuscules et minuscules.
- Testez différents code comme le mot "SOS"

<details>
    <summary>Dépannage circuit</summary>

Vérifiez votre circuit attentivement avec les points cités au-dessus.

</details>

### Allez plus loin ?

Regardez dans votre kit Arduino, vous avez un buzzer. Prenez le buzzer actif et branchez le à la place de votre led. Attention à la polarité !
