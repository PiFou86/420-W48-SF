# Module 09 - Plateformes de développement, partie 2

## Exercice 1 - Modélisation d'une application

### Étape 1 - Installer l'environnement de simulation Fritzing 

- Installez le logiciel de simulation à partir du site *"Fritzing.org"*

### Étape 2 - Se familliariser avec le simulateur

- Ouvrez la simulation TemperaturSensorLM35.fzz à partir du chemin Fichier> Ouvrir un exemple
- Modifiez la valeurs des résistances. La nouvelle valeur sera 470 Ohms

<details>
    <summary>Indice</summary>

 1. Cliquez sur la résistance de l'extrême droite.
 2. Cliquez sur le menu Fenêtre> Inspecteur
 3. Modifiez la valeur pour 470 Ω pour les 6 DELs
 4. Vérifiez que les bandes de couleur représentent bien la valeur
 6. Refermez la fenêtre d'édition

</details>

- Cliquez sur l'onglet Vue Schématique
- Vérifiez les valeurs de résistance
- Modifiez les noms des résistances pour représenterles positions de R0 à R7, de droite à gauche
- Sauvegardez la simulation sur votre disque personnel

### Étape 3 Affichage de la température en oC ou en oF

- Ajoutez un bouton poussoir qui permet l'affichage à la console de la température en oC ou en oF.
Lorsque le bouton est appuyé, l'affichage montre la température en oF.
Lorsque le bouton est relâché, l'affichage montre la température en oC.

### Étape 4 (optionnel) Mise en service du détecteur de température

- Branchez le circuit  *"TemperaturSensorLM35.fzz*" sur votre matériel Breadbord et votre Arduino
- Compilez et téléversez le programme dans Arduino.
- Testez le programme. Quelle température fait-il?

### Questions (optionnel) 

- Cherchez la "fiche technique" (data sheet)du détecteur LM35. Ce détecteur peut-il servir à mesurer la température corporelle?
- Faites-vous de la température? Quel est votre état de santé?

## Exercice 2 - Modélisation d'une application

### Étape 1 - Branchement du circuit

- Reproduire le circuit Potentiomètre de l'exercice 05 du module 03 en référance à Github du cours