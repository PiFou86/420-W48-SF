# Module 02 - Introduction au C++

Pour l'ensemble de ces exercices, vous allez utiliser :

- Visual studio code avec PlatformIO
- Votre plaquette de développement Arduino UNO
- Son cable USB
- Un café ou thé
- De la patience ;)

## Exercice 1 - Création de vos premières fonctions et manipulation de la structure du projet

### Exercice 1.1 - Séparation des déclarations et définitions

Dans cet exercice, nous allons reprendre le code de votre premier programme Arduino et nous allons l'intégrer dans la structure de base d'un projet PIO en utilisant les bases du langage C++. 

![Premier programme](img/premiercode.png)

Nous allons chercher à séparer correctement les déclarations des fonctions "allumerDELInterne" et "eteindreDELInterne" en déclarations et en définitions. Nous allons ensuite utiliser ce code dans la fonction "main" qui se situe dans le fichier "main.cpp".

Dans PIO, tous vos fichiers d'en-tête (ou de déclarations) doivent se situer dans le répertoire "include". Ils seront accessibles grace aux instructions de précompilation ```#include "Nom du fichier"```. Les fichiers d'en-tête du système ou des bibliothèques que vous utiliserez plus tard sont accessibles grace aux instruction de prépomcpilation ```#include <Nom du fichier>``` comme par exemple la bibliothèque "Arduino" avec les instructions ```#include <Arduino.h>```.

***Version courte :***

- Créez les fichiers "GestionDELInterne.h" et "GestionDELInterne.cpp" en les plaçant respectivement dans les répertoires "include" et "src".
- Répartissez les déclarations et définitions des fonctions (allumer/eteindre)DELInterne dans les deux fichiers précédemment créés.
- Dans le fichier "main.cpp", incluez le fichier d'en-tête et appeler les fonctions (allumer/eteindre)DELInterne afin d'avoir un fonctionnement équivalent au code de votre premier programme Arduino.

***Version longue :***

- Ajoutez le fichier d'en-tête "GestionDELInterne.h" dans le répertoire "include"
  - Dans ce fichier, ajoutez les déclarations des fonctions "allumerDELInterne" et "eteindreDELInterne" (N'oubliez pas d'ajouter la directive d'inclusion unique à la première ligne de votre fichier d'en-tête)
- Ajoutez le fichier de définitions "GestionDELInterne.cpp" dans le répertoire "src"
  - Grâce à la directive de précompilation, incluez le fichier d'en-tête précédemment créé
  - Déclarez vos deux fonctions
- Ouvrez le fichier "main.cpp"
  - Grâce à la directive de précompilation, incluez le fichier d'en-tête précédemment créé
  - Placez vous dans la fonction "loop" et appelez les fonctions "allumerDELInterne" et "eteindreDELInterne" comme dans votre premier programme Arduino

Dans toutes les versions, corrigez les erreurs de compilation, connectez la carte Arduino sur votre station de développement, téléversez et testez votre programme.

### Exercice 1.2 - Un peu de constance dans ce monde de brutes

Si vous avez suivi les étapes fournies, votre programme principal contient des "valeurs magiques" qui sont utilisées comme paramètres des appelles aux fonctions (allumer/eteindre)DELInterne.

Nous allons modifier le code afin de supprimer les deux valeurs numériques "500". Ces deux valeurs représentent respectivement la durée de l'éclairage de la DEL et la durée d'instinction de la DEL.

On utilise principalement deux façons en C/C++ pour déclarer des constantes :

- En utilisant des directives de pré-compilation : les "constantes" sont remplacées avant le processus de compilation. En fait, on définit une macro qui sera exécuté durant la phase de pré-compilation
- En utilisant le mot clef "const" : la variable déclarée est constante donc son contenu est immuable

#### Exercice 1.2.1 - Déclaration de macro

Pour déclarer une macro, il suffit d'écrire le nom de la macro suivi de caractères de type espace/tabulation suivi de la macro. Vous avez vu des exemples de telles déclarations dans le fichier "Arduino.h".

Pour déclarer une macro sans paramètre, utilisez la syntaxe suivante ```#define MA_CONSTANTE 1234```.

- Dans votre projet, créez le fichier "Configuration.h"
- Dans ce fichier, déclarez les macros/constantes "DUREE_DEL_ALLUMEE" et "DUREE_DEL_ETEINTE"
- Dans votre programme principal, remplacez les valeurs magiques par les macros/constantes

#### Exercice 1.2.2 - Déclaration de constantes

Pour déclarer une constante, il vous suffit de la déclarer et de la définir dans un fichier d'en-tête. Pour cela vous pouvez utiliser la syntaxe suivante : ```const int MaConstante = 1234```.

- Dans le fichier "Configuration.h", déclarez les constantes "dureeDELAllumee" et "dureeDELEteinte"
- Dans votre programme principal, remplacez les appels de macro par les constantes

#### Exercice 1.2.3 - Déclaration d'une macro avec paramètres

Pour déclarer une macro de précompilation avec des paramètres, la syntaxe est très similaire à la syntaxe des fonctions : ajoutez simplement des paramètres après le nom de la macro. Les parenthèse contiennent les noms des paramètres séparés par une virgule. Les paramètres des macros n'ont pas de type.

Exemple extrait du fichier "Arduino.h" : ```#define sq(x) ((x)*(x))```

Dans cet exemple l'utilisation du paramètre ```x``` est encadrée par des parenthèses car ```x``` pourrait contenir une expression complexe du type ```3 + 4```.

- Créez le fichier d'en-tête "MesMacros.h"
- En vous basant sur cet exemple, écrivez les macros "calculerMinimum" et "calculerMaximum" qui prennent chacune deux paramètres qui renvoient respectivement la plus petit et la plus grande valeur.
- Ouvrez le fichier "Arduino.h" et validez que vos macros sont comparables aux macros "min" et "max".

### Exercice 1.3 - S.O.S.

- En suivant les mêmes principes qu'énoncés précédemment, créez les fonctions :
  - AfficherSEnMorse et AfficherOEnMorse : qui affichent respectivement le signal lumineux du "S" et du "O" sur la DEL interne
  - AfficherSOSEnMorse : qui affiche le mot "SOS"
- Modifiez votre programme principal afin qu'il affiche le mot "SOS" suivi d'un délai d'une seconde en boucle.

## Exercice 2 - Tu tires ou tu pointes ?

Dans cet exercice, vous allez jouer avec les références et les pointeurs afin de mieux comprendre de quoi il en retourne.

### Exercice 2.1 - Préambule - Affichage d'information sur le moniteur série

Afin d'afficher de l'information, nous allons écrire du texte sur le port série simulé par votre Arduino. Avant de pouvoir écrire sur votre port série, vous devez configurer la vitesse de connexion du port série. Pour cela, dans la fonction "setup", appelez la méthode "begin" de l'objet accessible à partir de la variable globale "Serial". Pour cela, ajoutez l'instruction suivante ```Serial.begin(9600)```.

À partir du moment où le port est initialisé, vous pouvez utiliser les méthodes "print" et "println" accessible à partir de la variable globale "Serial".

Exemple :

![Démo écriture sur le port série](img/moniteur_serie_exemple_code.png)

- Créez le projet "AMOC_Module02_EssaisPortSerie"
- Tapez le code de l'exemple, corrigez les erruers et téléversez le programme compilé dans votre Arduino
- Allez visionner le résultat sur la console du port série. Pour cela cliquez sur l'icône en forme de prise qui se situe à côté du bouton de téléversement du code ([1]). Cela va ouvrir une console où les textes vont s'afficher ([2]) :

![Console série](img/moniteur_serie.png)

- Vous devriez obtenir un résultat proche de l'image suivante :

![Résultat console](img/moniteur_serie_exemple_resultat.png)

- À partir de votre résultat, en vous concentrant sur les deux derniers entiers qui sont affichés, validez la taille d'un entier.

<details>
    <summary>Indice #1</summary>

Faites la soustraction des deux adresses correspondantes aux entiers.

</details>

### Exercice 2.2 - Observations

- Ajoutez la fonction suivante en répartissant la déclaration et la définition dans les fichiers "passageParametres.(cpp/h)"

![Objservation des passages de paramètres](img/sortes_passage_parametres_code.png)

- Modifiez le code de l'exercice précédent afin d'y intégrer l'appel à votre nouvelle fonction

![Appel de passageDeParametres](img/sortes_passage_parametres_code_appel.png)

- Vous devriez avoir un affichage similaire au suivant :

![Affichage des adresses suivant l'affichage](img/sortes_passage_parametres_resultat.png)

- Dessinez la mémoire et surtout ici la pile en vous basant sur les adresses affichées

- Qu'observez-vous pour :
  - La variable passée par copie
  - La variable passée par référence
  - La variable passée par copie de pointeur

### Exercice 2.3 - À vous !

- Écrivez la fonction "passageDeParametres2" qui prend en paramètres :
  - Une référence de pointeur et qui modifie le pointeur en créant un nouvel entier sur le tas
  - Un pointeur de pointeur et modifie le pointeur pointé en créant un nouvel entier sur le tas
- Écrivez un appel à cette fonction :
  - Affichez les valeurs avant l'appel
  - Durant l'appel
  - Après l'appel

## Exercice 3 - On programme avec classe, c'est l'objet de l'exercice !


Classe SOS avec pin en ctor

Héritage - prendre exemple sos avec fonction virtuelle pour affichage trait et point => un pour del un pour port série

Exercice sur * et &