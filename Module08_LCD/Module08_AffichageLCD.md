# Module 08 - Programmation de l'afficheur à Cristaux liquides (LCD)

OBJECTIFS:
- installer une librairie dans platformIO
- configurer ou vérifier l'adressage I2C d'un composant
- programmer un afficheur LCD pour effectuer divers effets visuels, tels que clignotement, déplacement latéral ou vertical

Pour l'ensemble de ces exercices, vous allez utiliser :

- Visual studio code avec PlatformIO
- Votre plaquette de développement Arduino UNO
- Votre plaquette d'expérimentation
- Votre afficheur LCD, modèle AAAA
- Fils de branchement
- Autres accessoires nécessaires
- De la patience ;)

### Préparation des fils

POur ces exercices, vous aurez besoin de 4 fils Dupont femelle-femelle.

de votre ensemble est composé de 10 brins de fils de couleurs variées, débutant par noir et se terminant par brun. Séparez l'ensemble d'une natte en gardant collées les 2 premiers brins (noir et blanc) de l'ensemble ou les 2 derniers brins (rouge et brun).


![BranchementAfficheurLCD](img/branchementLCDI2C.png)

## Exercice 1 -  Afficheur LCD avec le protocole I2C

Le module 1602A est un afficheur à cristaux liquides (LCD) de format 16 caractèrs sur 2 rangées.
Son branchement et sa programmation sont facilités par l'usage du protocole I2C. Grâce à ce protoocole, 4 fils suffisent: 2 pour l'alimentation ( ```Vcc``` et  ```GND```) et 2 pour le transfert de données (```SCL``` et ```SDA``` )

### Étape 1 - branchement
Branchez les fils en respectant la convention:
rouge pour alimentation 5 V (couleur peut varié selon la disponibilité)
noir pour retour du courant (GND) (couleur peut varié selon la disponibilité)
couleurX pour SCL (pour moi, il s'agit d'orange)
couleurY pour SDA (pour moi, il s'agit de vert)
![circuitPhysiqueLCDI2C](img/circuitPhysiqueLCDI2C.png)

![circuitelectriniqueI2C](img/SchemaLCDI2C.png)

### Étape 2 - identification de l'écran LCD_I2C

Créez une nouvelle application PlatformIO ```IdentificationLCD```. Un modèle de programme est disponible dans le répertoire LCD_PreparationCours.
Compilez  et exécutez le programme.
Vous trouverez l'adresse I2C en sortie dans l'écran de la console
- Combien de bits contient l'adresse du protocole I2C de votre afficheur?
- Le programme recherche des adresses entre 8 et 127. Pouvez-vous expliquer pourquoi la recherche se limite à cet intervalle?
<details>
    <summary>Indice</summary>

Le protocole I2C a une plage d'adresse sur 7 bits. La limite supérieure est donc 127. les 3 premières bits sont réservées pour des commandes spécifiques du protocole. Elles ne peuvent donc pas servir pour identifier un périphérique.

</details>

 VOUS NE POUVEZ PAS POURSUIVRE si vous ne connaissez pas l'adresse I2C de votre périphérique.

## Exercice 2 -  Programmes de test

### Étape 1 - Installation d'une librairie LiquidCrystal_I2C
- Créez le  projet  ```LCDI2C_Base``` dans PlateformIO
- Installez les librairies suivantes dans platformio.ini selon les directives suivantes
-https://platformio.org/lib/show/576/LiquidCrystal_I2C/installation

<details>
    <summary>Indice</summary>

L'onglet Installation donne la liste des dépendances à ajouter dans le fichier de configuration platformIO.ini de l'application ino
L'onglet Headers donne l'entête #include de la librairie (ou plusieurs si c'est le cas) à ajouter dans le programme man.cpp

</details>

### Étape 2 - Programme LCDI2C_Base

Créez une nouvelle application PlatformIO ```LCDI2C_Base```. Un modèle de programme est disponible dans le répertoire LCD_PreparationCours.
AVANT DE COMPILER, vous devez vérifier, et peut-être ajuster, l'adresse I2C du modèle dans votre programme. Une ligne d'instruction est prévue pour cela.
Compilez  et exécutez le programme.
 Deux lignes de  messsages se déroulent dans l'écran LCD.

### Matériel
- https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/

- Un lien vers ```Read the documentation``` offre de  l'aide sur les méthodes disponibles de la librairie pour contrôler le curseur, l'affichage et le fond d'écran.

Quelle méthode efface les caractères et positionne le curseur en position (0,0) de l'écran?

<details>
    <summary>Indice</summary>

 objet.clear() 

</details>

Quelle méthode positionne le curseur dans une position (x,y) de l'écran?

<details>
    <summary>Indice</summary>

 objet.setCursor(colonne, rangee) 

</details>

## Exercice 3 - Promotion dans nos boutiques

Votre prochaine tache consiste à afficher des annonces publicitaires dans le centre d'achat.

### Étape 1 - Affichage vertical
- Créez le  projet  ```ClignotementVertical ``` dans plateformIO

Le but du programme est de faire clignoter le texte suivant . . .

 ```Rabais 15% dans```

 ```  nos boutiques ```

. . . quatre fois pendant 500 milisecondes puis de faire une pause de 100 milisecondes d'affichage.

### Étape 2 - Affichage latéral
- Créez le  projet ```BalayageHorizontal ``` dans plateformIO

Le but du programme est de faire dérouler le texte suivant de gauche à droite. Le texte doit apparaître comme une banderolle circulaire, le texte réapparaissant à gauche sans arrêt.


 ```Bienvenue    ``` 

 ```aux visiteurs``` 

## Exercice 4 -  Etat des routes

Votre prochaine tache consiste à afficher un message sur un panneau d'information sur les autoroutes.

### Étape 1 - Affichage en séquence
- Le but du programme est d'afficher un message d'information parmi une liste de 6 messages entreposés dans la mémoire EEPROM.

- Créez le  projet  ```EtatDesRoutes ``` dans plateformIO

- A toutes les 30 secondes, un nouveau message,choisi au hasard, apparaît dans l'écran.

On convient que la longueur d'un message est de 32 octets maximum. Le premier message est gardé dans la mémoire EEPROM à partir de l'adresse 16. Les autres messages suivent selon un positionnement équivalent.
- L'adresse 0 de l'EEPROM est réservée pour garder le numéro d'index du message présenté sur l'autoroute. Au redémarrage, cette information permet de revenir sur le dernier message affiché.

<details>
    <summary>Indice</summary>

Consultez le site d'Arduino pour tirer un nombre au hasard

</details>
