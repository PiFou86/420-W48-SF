# Déboguer un programme en C++ à l'aide de macros

## Public

Ce tutoriel s'adresse à tout programmeur qui souhaite tester ses programmes avec une technique simple. Il est approprié pour tester un algorithme, développer une application simple ou simplement pour explorer l'usage de macros dans le code du programmes.

Pour des situations complexes, il existe des solutions évoluées. Par contre, pour atteindre la pleine versatilité de ces solutions, il faut parfois déployer des modules complémentaires ("plugin") et des modules matériels adaptés (e.g. JTAG). Par conséquent, il faut de l'apprentissage, de l'argent et du temps.

## Table des matières

- [Partie 1 - Utiliser des macros pour tracer un programme](debug_partie1.md)
- [Partie 2 - Déboguer des variables et des fonctions](debug_partie2.md)
- [Partie 3 - Suivre l'adresse de variables et les pointeurs](debug_partie3.md) (à venir)
- [Partie 4 - Déboguer une structure complexe](debug_partie4.md) (à venir)
- [Bibliothèque et configuration pour déboguer (et bien plus)]([debug_lib.md](https://github.com/PiFou86/420-W48-SF-Utilitaires-Demo))

La partie 1 expose les bases de l'usage de macros et leur application pour tester des programmes. La partie 2 montre quelques exemples de macros pour tester certaines expressions ou algorithmes.

## Environnement de développement

Ce tutoriel utilise l'environnement PlatformIO pour développer une application dans le domaine des microcontrôleurs.

### Prérequis

L'environnement de démonstration est:

- PlateformeIO dans Visual Studio Code ; (ici https://PlatformIO.org/PlatformIO-ide)
- Connaissance du langage C ou C++
- Microcontrôleur Arduino, ESP32 ou équivalent

Les exemples peuvent être adaptés à d'autres environnements avec quelques changements.

## Comment fonctionne ce débogueur?

Ce débogueur est mis en œuvre par l'usage de macros. Ces macros sont inscrites par le développeur à l'intérieur du code source pour fin de tests. À l'exécution, ces macros produisent des messages qui sont relayés vers une fenêtre de console associée au programme à tester. Ces macros utilisent donc l'instruction "print()" du langage C++ des microcontrôleurs de type "Arduino".

Lorsque les tests sont terminés, il est important de supprimer ces `traces` avant une mise en service du programme. Certains risques sont importants :

- Difficulté à supprimer ***uniquement*** ces traces
- Oublie de certaines traces, rendant le programme moins performant

Le tutoriel permet:

- D'afficher le numéro de ligne lors de l'exécution
- D'afficher la valeur des variables ou expressions du langage
- D'activer ou masquer rapidement les traces facilement durant les tests
- D'aider à identifier les traces ajouter pour les supprimer à la fin des tests.

### Et la suite?

- [Partie 1](./debug_partie1.md) Utiliser des macros pour tracer un programme

### Références et définitions

- [Macro, comment ça marche](https://www.programiz.com/c-programming/c-preprocessor-macros)
