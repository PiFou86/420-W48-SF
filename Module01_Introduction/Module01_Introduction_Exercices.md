# Module 01 - Introduction

---
Avant chaque manipulation de votre Arduino, touchez une pièce de métal avec votre doigt **MAIS SURTOUT PAS LE MÉTAL** de la carte.

Pour chaque montage électronique, **TOUJOURS** placer **UNIQUEMENT** la carte Arduino et les pièces nécessaires à un montage. Disposez les pièces de façon à les aligner et bien les identifier avant un montage.

Ces précautions protégeront vos montages, faciliteront vos vérifications en cas d’erreur et un service plus rapide des animateurs pour vous dépanner au besoin.

---

Les objectifs des activités suivantes sont :

- Installer les outils nécessaire à la programmation de votre carte arduino sur votre poste de travail
- Valider que le programme fonctionne
- Valider que le programme peut communiquer avec la carte arduino
- Avoir une première approche des langages C/C++
- Découvrir quelques fonctionnalités de la carte arduino et des bibliothèques de base

## Préalable - Installation Arduino

Le logiciel Arduino IDE (Integradted Development Environment) est une interface graphique permettant de configurer, programmer et tester vos sketchs et montages Arduino. Assurez-vous d’avoir entre vos mains la clef USB dans votre boîte individuelle ou votre ordinateur portable.

Les instructions suivantes s'appliquent à un poste Windows 10. Elles peuvent être adaptées pour un poste macOS ou Linux.

### Installation d'Arduino studio

- Ouvrez votre navigateur web et allez sur le site informationnel d'Arduino https://www.arduino.cc
- Sur ce site vous pourrez télécharger le logiciel "Arduino studio" :
  - Rendez-vous dans la section "software/Downloads"
  - Téléchargez la version adaptée à notre environnement :
    - Si vous avez un ordinateur portable, choisissez la version "Win 7 and newer"
    - Si vous n'avez pas d'ordinateur portable et que vous allez utiliser une clef USB, choisissez la version archive "ZIP"
  - Choisissez "Just download" dans l'écran suivant
- Suivant votre choix précédent, installez ou décompressez l'application

## Exercice 1 - Connexion de l'Arduino et premier programme

- Ouvrez l'application "Arduino studio" que vous venez d'installer
- Créez un nouveau
- Reprenez le code du cours suivant

```c++
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  allumerLedInterne(500);
  eteindreLedInterne(500);
}

void allumerLedInterne(int p_delay) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(p_delay);  
}

void eteindreLedInterne(int p_delay) {
  digitalWrite(LED_BUILTIN, LOW);
  delay(p_delay);  
}
```

- Touchez une surface métallique autre que vos composants électronique, l'idéal étant que la surface soit reliée à la terre
- Reliez votre poste de travail et la carte Arduino avec le cable USB fourni avec votre kit
- Téléversez le montage sur votre carte Arduino
- Validez que le tout fonctionne

<details>
    <summary>Débogage - Erreur de code</summary>

Recherchez des indices dans le message d'erreur. Minimalement, vous allez avoir le numéro de la ligne avec une description sommaire. Comme toujours, validez les accolades, parenthèses, points virgules, déclaration de variables, etc.

</details>

<details>
    <summary>Débogage - Erreur de communication</summary>

- Validez que vous avez bien branché votre carte Arduino à votre poste avec le cable USB fourni dans votre kit
- Validez vos paramètres de communication :
  - Type de carte : "Arduino Uno"
  - Port : validez que la carte est bien détectée et sélectionnez le port correspondant à votre carte

Si la carte n'est pas affichée dans la section "Outils/Port", essayez d'installer le pilote fourni avec "Arduino Studio" en suivant les étapes suivantes :

- Ouvrez l’explorateur Windows. Recherchez "C:\Program Files(X86)\Arduino\drivers"
- Recherchez le programme "dpinst-amd64.exe"
- Lancez-le et suivez les instructions pour installer le pilote

</details>

## Exercice 2 - Variation de motifs

Faites différentes version de votre programme pour que :

- La del s'allume 1 seconde et s'éteigne 0.5 seconde
- La del s'allume 0,5 seconde et s'éteigne 1 seconde, s'allume 1 seconde et s'éteigne 0,5s.

## Exercice 3 - Persistance rétinienne

Créez un nouveau programme qui allume et éteigne la del à une fréquence suffisante pour que vos yeux ne constatent pas les changements d'états à cause de l'effet de la persistance rétinienne. Notez cette valeur.

## Exercice 4 - SOS en morse

Créez un nouveau programme qui se sert de la del afin d'afficher la séquence "SOS" qui en morse se traduit par "... --- ...". Un "-" correspond à la durée de 3 ".". Le changement de lettre (ici, représenté par un espace " ") correspond à un temps équivalent à 3 points.

## Exercice 5 - D’où viennent les valeurs LED_BUILTIN, HIGH, LOW, etc.

La compilation de votre programme C/C++ passe par une phase préalable appelée précompilation qui va exécuter des instructions présentent dans le code. Ces instructions sont préfixées par le symbole "#". Nous reviendrons plus en détails dans les futurs modules.

Pour l'exercice, sachez que le pré-compilateur retrouve les valeurs des constantes "LED_BUILTIN", "HIGH", "LOW" dans une librairie IMPLICITE. Au besoin, il remplace le nom de la constante par sa valeur avant de compiler le code en binaire.

**!!!EXPLOREZ sans sauvegarder!!!**

Sur votre PC (ou clé USB ou disque SSD), placez-vous à la base du répertoire contenant le programme Arduino IDE. Sous Windows, par défaut, le répertoire est "C:\Program Files(x86)\Arduino".

Utilisez un éditeur de texte afin d'afficher le contenu du fichier "hardware\arduino\avr\cores\arduino\Arduino.h". Il est conseillé d'utiliser un éditeur de texte de type "Visual Studio Code" :

- Observez le contenu du fichier **sans le modifier**.
- Notez les valeurs des constantes suivantes :
  - HIGH
  - LOW
  - LED_BUILTIN
- Lisez la déclaration de la macro "sq", notez ses paramètres et son algorithme

NOTE : les constantes implicites sont représentées en majuscules pour en faciliter le repérage dans les sketchs.
