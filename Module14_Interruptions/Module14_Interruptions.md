# Module 14 - Interruptions

 librairie ```WifiManager```

![PremierDemarrage](img/PremierDemarrage.png)

bornes esp32

## Objectifs

Dans ces exercices, vous allez mettre en oeuvre une routine d'interruption qui réagit à l'appui d'un bouton-poussoir.

Votre routine de base compte le nombre d'appuis du bouton et l'affiche sur la console. Par la suite, vous allez y incorporé du code pour éliminer les rebonds.
Enfin, vous allez y ajouter trois mécanismes pour augmenter la fiabilité des résultats.

Rappelons que les routines d'interruption ne sont reliés au programme en cours d'exécution que par un passage obligé avec les registres du processeur. Cette contrainte fait en sorte qu'il peut arriver une différence entre la valeur d'une variable dans  

## Exercice 1 - interruption de base

### Étape 1 - branchement de la plaquette d'expérimentation

- Branchez votre plaquette à votre ESP32 de la façon suivante

    - borne No 14 à une des trois bornes des boutons-poussoir

    - alimentation ```3,3V``` du ESP32 vers alimentation de la plaquette (VCC)
    
    - prise de terre du ESP32 vers la prise de terre de la plaquette (GND)

### Étape 2 - programmation d'une interruption

- Créez la nouvelle application platformIO ```AMOC_ESP32_Interruption```
- Ajoutez les instructions d'une routine d'interruption permettant de détecter et compter le nombre de fois que le bouton poussoir a été appuyé. Le bouton poussoir doit être correctement relié à la borne digitale No 14 du ESP32

- Le décompte des appuis doit se faire au moment du relachement du bouton

- Ajoutez les instructions pour afficher ce décompte à toutes les 2 secondes. Au passage, faire clignoter la DEL No 2 pour marquer le temps

## Exercice 2 - mécanisme sans rebond

### Étape 1 - programmation du bouton poussoir sans rebond

- Ajoutez le code pour mettre en place la robustesse sans rebond

### Étape 2 - partage de la valeur du décompte

#### Contexte

Le temps d'affichage par les instructions ```Serial.print``` et ```Serial.println``` est comparativement très long par rapport à l'exécution de l'interruption. Si une interruption survient durant l'affichage de la valeur du décompte, il n'est pas possible de savoir si la console indique la valeur avant ou après l'interruption

- Ajoutez le code pour  résoudre cette possibilité

### Étape 3 -  fiabilité de l'interruption

- Ajoutez les 3 mécanismes pour augmenter la fiabilité de la donnée 


## Exercice 4 - Contôler les arrêts/reprises d'une interruption

Il arrive souvent que l'interruption doit être désactivée dans certaines circonstances. Dans cette étape, vous allez ajouter les instructions pour désactiver et réactiver une interruption

### Étape 1 - activation d'une interruption

- Ajoutez le code pour désactiver l'interruption après 10 appuis du bouton et réactiver l'interruption après une pause de 5 secondes.

- Effectuez les tests pour démontrer les résultats

<details>
    <summary>Indice</summary>

- Utilisez l'instruction inverse de la fonction ```attachInterrupt``` pour désactiver spécifiquement l'interruption

</details>

### Étape 2 - Alertes aux radiations (optionnel)

#### Scénario

Vous habitez dans la région de la centrale nucléaire! Votre matériel est équipé d'un système de détection des radiations mettant en danger la santé de la population. Le bouton de votre matériel enverra des messages SMS aux populations si certains seuils sont atteints.

#### Montage

- Ajoutez un détecteur ultrasonique HC-SR04 à votre montage

- Utilisez les bornes 16 et 17 pour Echo et Trigger

- UTILISEZ LA TENSION 3,3 V pour alimenter le détecteur

#### Programmation

- Programmez le détecteur pour faire clignoter la DEL NO 2 lorsque les avions menacent la sécurité ( distance entre "l'avion" et vous se situe dans l'intervalle [ 0-8 ] cm) 

- Dans ces conditions, l'interruption est activée. A chaque appui du bouton, une sirène retentit

- Lorsque la menace est passée, l'interruption est désactivée pour éviter de fausse alertes à la population

