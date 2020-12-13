# Module 09 - Plateforme de développement PlatformIO

## Exercice 1 - Installations de la plateforme de développement

### Étape 1 - Installer Visual Studio Code

Si Visual Studio Code est déjà installé, rendez-vous à l'étape 2

-Accédez au site de *"VIsualStudio Code"*

-Découvrez les avantages de cet environnement de développement

- Installez VSd sur votre PC

### Étape 2 - Installer PlateformIO IDE

-Accédez au site de  *"PlatformIo"*

-Installez  *"PlatformIo IDE for VSCode"*

NOTE: pour simplifier, nous abrégeons PlateformIO par *pio*

## Exercice 2 - Développer un programme Adruino dans pio

### Étape 1 - Installer un programme Arduino dans PlateformIO


références:

https://community.platformio.org/t/make-platformio-project-compatible-with-arduino-ide/3368/9

1.Cliquez sur l'icône PlatformIO dans la liste des extension (partie gauche de l'écran VSd)

2.Éditez un projet

3.Ouvrez un nouveau projet pio

4.Remplissez les cases demandées
![Test Arduino](imp/PremierSketchArduino.png)

5.Cliquez sur Finish

La structure suivante a été générée

![Structurepio](imp/StructurePio.png)

- Cliquez sur le chemin *src*. Vous obtenez un fichier *main.cpp* qui englobera le code *arduino*.

- Remplacez tout le code du texte par le code du skecth Blink.ino situé dans l'IDE d'Arduino

<details>
    <summary>comment?</summary>

1.Ouvrez l'IDE d'Arduino

2.Déplacez-vous dans la liste des exemples jusqu'au sketch *Blink*

 ![Sketch Blink](imp/PremierPioBlink.png)

3.Recopiez intégralement le code dans *src*

</details>

### Étape 2 - Compiler un programme Arduino dans pio

- Compilez le code par le bouton *Build*

 ![Sketch Blink](imp/Build.png)

LECTURE IMPORTANTE

Dans la console, vous constaterez des erreurs de compilation. Et c'est normal à cette étape-ci!

Il faut informer *pio* de l'origine des déclarations IMPLICITES comme HIGH, LOW, OUTPUT ou INPUT.

- Ajoutez la consigne suivante:
#include <Arduino.h> au tout début du code source

- Compilez le code à nouveau

- Observez la console *pio*. Elle donne un état de cette action.

Le message « SUCCESS » doit apparaître avant de poursuivre!

 ![Success](imp/Success.png)

### Étape 3 - Téléverser le code dans Arduino

- Branchez le câble USB entre la carte et le PC

- Le bouton *Upload* est désigné pour téléverser le code binaire dans l'Arduino 

-Vous devriez pouvoir identifier le port com associé à l'Arduino
<details>
    <summary>Depannage</summary>

DANS CERTAINS CAS, *pio* ne détecte pas le pilote du câble USB de téléchargement

 ![erreurConnexionUSB](imp/ErreurPortUSB.png)

1.Assurez-vous que le câble USB est fonctionnel
2.Port non détecté

PARFOIS, pio ne réussit pas à trouver  automatiquement le pilote associé au port de la carte d'Arduino

Il faut alors passer par en mode manuel, de la façon suivante:

1.Dans le menu depio, cliquez sur le chemin platformIO.ini

2.Repérez la structure  [ env :uno]

3.Ajouter l'instruction suivante

upload_port = com [*noPort*]

4.Sauvegardez le fichier plarformIO.ini

5.Tentez le téléchargement à nouveau!

</details>

-Ouvrez un Terminal par l'onglet TERMINAL (bas de l'écran)
-Rechercher « platformio device list »

La commande est *platformio device list* abrégée (*pio device list*)
Le téléversement doit avoir réussi

 ![ConnexionUSBOK](imp/ConnexionUSbReussie.png)

-Demandez de l'aide au besoin!

À la fin, la del No 13 clignote 

Bravo!
VOUS AVEZ REUSSI à interfacer pio avec Arduino!

## Exercice 3 - Développer un programme Arduino dans pio

### Étape 1 - Feu de circulation

- Créez un nouveau projet *Feu de circulation*
 
-Importer  le programme 420_w48_sf_m02_exercice_feux_circulations.ino. situé dans le module_02 du Github

Compilez et téléversez le programme dans Arduino

### Étape 2 - Exécuter un programme avec pio 

-Branchez le circuit Feu de circulation sur votre carte Arduino pour terminer la démonstration.

## Exercice 4 - Développer un programme Arduino dans pio (2)

### Étape 1 - Potentiometre et 2 Dels

-Créez un nouveau projet *PotentiometreBase*

-Installer le programme *PotentiometreBase.ino* du Module 03, Exercice 4, étape 2: Programmation dans GitHub

<details>
    <summary>Indice</summary>

 ![PotentioMetreSolution](imp/PotentioMetreSolutionMod03Ex4.png)

</details>

Compilez et téléversez le programme dans Arduino

### Étape 2 - Exécuter un programme avec pio 

Branchez le circuit PotentiometreBase sur votre carte Arduino pour terminer la démonstration.

## Exercice 5 - Installation d'une librairie privée dans l'IDE d'Arduino

### Étape 1 - Préparer la librairie Flasher

Pour compiler un programme qui demande le code objet de Flasher, la librairie Flasher doit être installée dans l'IDO d'Arduino
Suivez les étapes décrites ici

Cette étape se fait en 2 phases

#### Phase 1 - Préparer les fichiers

Sur votre PC, créez un répertoire temporaire nommé *Flasher*
Pour cette étape, vous aurez besoin de créer 2 fichiers et un sous-répertoire:

1.Fichier Flasher.cpp
2.Fichier Flasher.h

À partir du site GitHub du cours:

-Copiez le code source
*Module04_ProgrammationC/420-W48-SF_DemoClasses/Flasher.cpp*
dans Flasher.cpp
-Copiez le code source
*Module04_ProgrammationC/420-W48-SF_DemoClasses/Flasher.cpp* dans Flasher.h

#### Phase 2 - Activer une nouvelle librairie Arduino

-Ouvrez l'application IDE d'Arduino

-Cliquez sur le chemin -->Inclure une bibliothèque-->Ajouter une bibliothèque ...

-Donnez le chemin du répertoire temporaire FLasher

-Vérifiez. Parcourrir la liste de toutes les bibliothèques

 ![InclureBibliotheque](imp/InclureBibliothequeFrasher.png)

La bibliothèque est maintenant migré dans les librairées privées.

 FIN DE L'EXERCICE
