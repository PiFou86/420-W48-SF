# Module 13 - Afficheur à cristaux liquides (LCD)

## Exercice 1 - Programmes de test

### Étape 1 - Utiliser la librairie LiquidCristal.h

### Matériel

- TinkerCad avec le programme [420-W48-SF Base LCD - Pub](https://www.tinkercad.com/things/5TKA2kCZLcS-/editel)

- exécutez le programme en faisant varier le potentiomètre.

### Étape 2 - Méthodes disponibles pour la librairie LiquidCristal.h

### Matériel

-  [420-W48-SF méthodes de l'objet LCD](https://www.arduino.cc/en/Reference/LiquidCrystal)

- Établissez la liste des méthodes disponibles de la librairie LiquidChristal.h, leur rôle, et leurs paramètres d'entré offrant une variété d'affichage

## Exercice 2 - Promotion dans nos boutiques

### Matériel

- TinkerCad avec le programme [420-W48-SF Base LCD - Pub](https://www.tinkercad.com/things/5TKA2kCZLcS-/editel)


### Étape 1 - Affichage vertical
 
- Sauvegardez le programme sous le nom "balayage vertical"
- Faites dérouler le texte "Bienvenue! (première ligne) aux visiteurs" (deuxième ligne) vers le haut, en faisant apparaître la promotion "Rabais:15% (première ligne) dans nos boutiques ***" (deuxième ligne). Le texte doit apparaître comme une banderolle circulaire verticale.
- Le texte clignote 4 fois pendant 500 milisecondes. Une pause de 100 milisecondes est nécessaire pour stabiliser l'affichage.

### Étape 2 - Affichage latéral

- Sauvegardez le programme sous le nom "balayage horizontal"
- Faites dérouler le texte "Bienvenue! (première ligne) aux visiteurs" (deuxième ligne) de gauche à droite. Le texte doit apparaître comme une banderolle circulaire, le début du texte réapparaissant à droite.
- Après un déroulement complet de la banderolle, le texte se déroule dans le sens inverse.

## Exercice 3 - affichage de distances

### Matériel

- TinkerCad avec le programme [420-W48-SF Base LCD - Pub](https://www.tinkercad.com/things/5TKA2kCZLcS-/editel)
- composant "capteur de distance par ultrasons"

Le capteur par ultrasons est un composant équipé d'un émetteur et d'un récepteur à ultrason. Par intermittances, un signal est émis et le temps de réponse de l'écho détermine la distance entre le capteur et un obstacle éventuel, le tout en considérant la vitesse du son. 
### Étape 1 - Affichage de distances

- Sauvegardez le programme sous le nom "AffichageDistances"
- Ajoutez un composant "capteur de distance par ultrasons"

![Capteur ultra-sonique](img/CapteurUltrason.png)

- branchez la sonde du capteur sur la borne No7 d'Arduino. Polarisez le capteur aves ses bornes + et -

- Établissez une équation permettant d'afficher la distance entre l'obstacle et la sonde. 
La vitesse du son est de 340m/s.
- Affichez la distance en cm et en pouce sur le LCD.

- Affichez la distance calculée sur l'afficheur LCD

### Étape 2 - Affichage en bascule (optionnel)

- Ajoutez un bouton poussoir. QUand le bouton n'est pas appuyé, l'affichage montre la distance en cm. Tant que le bouton est appuyé, l'affichage montre la distance en pouces.

## Exercice 4 - Caractères personnalisés (optionnel)
Dans cet exercice, vous pourrez fabriquer vos propres symboles et logos que vous afficherez sur le LCD.

### Matériel

- https://github.com/adafruit/SPI_VFD/blob/master/examples/createChar/createChar.pde

- https://omerk.github.io/lcdchargen/
