# Module 09 - 4 Digits

## Ce qui sera vu

- Brancher et piloter un afficheur quatre chiffres fondé sur le contrôleur TM1637.
- Afficher des valeurs binaires et décimales avec une classe d'affichage.
- Extraire des bits à l'aide des opérateurs de décalage et des opérateurs bit à bit.
- Compter les pressions d'un bouton et présenter le résultat sur l'afficheur.
- Réaliser, en extension optionnelle, un chronomètre.

## Prérequis

- Savoir compiler et téléverser un projet PlatformIO sur Arduino UNO.
- Connaître les classes C++ simples et l'installation d'une bibliothèque.
- Savoir utiliser les opérateurs de décalage et les représentations binaire et décimale; consulter la mise à niveau mathématique au besoin.
- Savoir lire un bouton sans rebond comme au module 06.
- Disposer de l'afficheur TM1637, de quatre fils et d'une Arduino UNO.

## Exercice 1 - Afficher un nombre sur 4 digits

### Matériel

- Arduino Uno
- Afficheur 4 digits avec le TM1637
- 4 fils mâle-femelle

### Brancher le matériel

Effectuez les branchements suivants :

![Montage 4 digits](img/montage_base.png)

### Programme

Le but de ce programme est de pouvoir compter et afficher un compteur qui s'incrémente. Le compteur peut être affiché en binaire et en décimal.

#### Étape 1 - Première implantation - Affichage de base

- Créez le projet PlatformIO `Module09_4Digits_Entiers`.
- Ajoutez la bibliothèque `https://github.com/avishorp/TM1637`.
- Implantez les classes suivantes :

![Diagramme de classes de base](img/diagramme_classes_LCD.png)

- Avec les classes que vous venez de créer, affichez la valeur `1010` et vérifiez le résultat.

#### Étape 2 - Compteur binaire

- Dans la classe "Affichage4Digits", ajoutez la méthode publique "valeurSegment" qui prend une valeur comprise entre 0 et 1 et qui renvoie la représentation du caractère affichable directement avec votre fonction afficher.
- Écrivez la méthode "afficherBinaire" qui prend un entier et qui affiche ce nombre sur le 4 digits (c'est le moment de revisiter vos décalages et vos opérateurs bit à bit : comment extraire un bit ?)
- Écrivez un programme principal qui compte en binaire de "0000" (0 en décimal) à "1111" (15 en décimal) et qui affiche le résultat sur le 4 digits (attendre 1 seconde entre chaque incrément)

#### Étape 3 - Compteur décimal

- Dans la classe "Affichage4Digits", complétez la méthode publique "valeurSegment" pour qu'elle puisse maintenant prendre une valeur entre 0 et 9.
- Écrivez la méthode "afficherEntier" qui prend un entier et qui affiche ce nombre sur le 4 digits (comment décomposer un nombre ?)
- Écrivez un programme principal qui compte en binaire de "0000" à "9999" et qui affiche le résultat sur le 4 digits (attendre 100 millisecondes entre chaque incrément)

<details>
<summary>Indice</summary>

Cherchez à décaler votre entier vers la droite et à appliquer un filtre qui permet d'isoler le bit de poids faible avec un "&"

</details>

## Exercice 2 - Compteur de pressions

### Matériel

- Arduino Uno
- Afficheur 4 digits avec le TM1637
- 4 fils mâle-femelle
- Votre circuit imprimé d'expérimentation : vous aurez besoin de la partie des boutons

### Brancher le matériel

Effectuez le montage de votre afficheur quatre chiffres. Connectez aussi un bouton-poussoir à la broche 4.

### Programme

- Créez le projet Platformio "Module09_4Digits_Compteur"
- Le programme doit fonctionner comme suit :
  - À chaque pression d'un bouton un compteur doit être incrémenté
  - Le compteur doit être affiché et mis à jour après chaque pression
  - (Optionnel) Après 10 secondes d'inactivité, l'afficheur doit s'éteindre afin d'économiser de l'énergie.
  - (optionnel) À chaque pression, le nombre de pression est sauvegardé dans l'EEPROM. Au démarrage de votre montage, la valeur de départ du compteur est prise dans l'EEPROM.

## Exercice 3 - Le chronomètre (optionnel)

### Matériel

- Arduino Uno
- Afficheur 4 digits avec le TM1637
- 4 fils mâle-femelle
- Votre circuit imprimé d'expérimentation : vous aurez besoin de la partie des boutons

### Brancher le matériel

Effectuez le montage de votre afficheur quatre chiffres. Connectez aussi deux boutons-poussoirs : un à la broche 4 et l'autre à la broche 5.

### Programme

- Créez le projet Platformio "Module09_4Digits_Chronometre"
- Ajoutez la bibliothèque `https://github.com/avishorp/TM1637`.
- Ajoutez les classes pour l'afficheur quatre chiffres que vous avez développées dans les exercices précédents.
- Implantez l'affichage d'un chronomètre qui mesure 60 minutes maximum :
  - Le chronomètre démarre ou s'arrête après la pression d'un des boutons.
  - Le chronomètre se réinitialise à la pression d'un autre bouton
  - Le chronomètre affiche en permanence le temps mesuré
