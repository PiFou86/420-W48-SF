# Module 14 - Interruptions

## Ce qui sera vu

- Déclencher une routine d'interruption lors de l'appui d'un bouton.
- Garder la routine d'interruption courte et reporter le traitement dans la boucle principale.
- Réduire l'effet des rebonds sur le décompte des pressions.
- Partager fiablement une valeur entre la routine d'interruption et le programme principal.
- Activer et désactiver une interruption de façon contrôlée.
- Observer les limites d'une interruption dans un scénario d'intégration.

## Prérequis

- Savoir programmer et téléverser une application sur ESP32.
- Savoir brancher et lire un bouton, reconnaître ses rebonds et gérer le temps sans bloquer la boucle principale.
- Connaître la portée et la durée de vie des variables en C++.
- Comprendre qu'une donnée partagée peut changer en dehors du déroulement normal du programme.
- Disposer de l'ESP32 et de la plaquette d'expérimentation utilisées dans les modules précédents.

## Exercice 1 - Interruption de base

### Étape 1 - Branchement de la plaquette d'expérimentation

Branchez votre plaquette à votre ESP32 de la façon suivante :

- Reliez la broche 14 à l'une des trois bornes d'un bouton-poussoir.
- Reliez l'alimentation `3,3 V` de l'ESP32 à l'alimentation de la plaquette (VCC).
- Reliez la masse de l'ESP32 à celle de la plaquette (GND).

### Étape 2 - Programmation d'une interruption

- Créez l'application PlatformIO `AMOC_M014_ESP32_Interruption`.
- Ajoutez les instructions pour afficher ce décompte à toutes les 2 secondes. Au passage, faire clignoter la DEL No 2 pour marquer le temps.
- Le décompte des appuis doit se faire au moment de l'appui du bouton
- Ajoutez les instructions pour afficher ce décompte à toutes les 2 secondes. Au passage, faire clignoter la DEL No 2 pour marquer le temps.

## Exercice 2 - Mécanisme de fiabilité

### Étape 1 - Programmation du bouton poussoir sans rebond

- Ajoutez le code pour mettre en place le décompte des appuis sans rebond

### Étape 2 - Partage de la valeur du décompte

#### Contexte

Le temps d'affichage par les instructions ```Serial.print``` et ```Serial.println``` est comparativement très long par rapport à l'exécution de l'interruption. Si une interruption survient durant l'affichage de la valeur du décompte, il n'est pas possible de savoir si la console indique la valeur avant ou après l'interruption

Ajoutez les instructions pour résoudre cette possibilité.

### Étape 3 -  Fiabilité de l'interruption

Ajoutez les instructions de protection de la donnée durant l'interruption.

## Exercice 4 - Contrôler les arrêts/reprises d'une interruption

Il arrive souvent que l'interruption doive être désactivée dans certaines circonstances. Dans cette étape, vous allez ajouter les instructions pour désactiver et réactiver une interruption.

### Étape 1 - Activation/désactivation d'une interruption

- Ajoutez le code pour désactiver l'interruption après 10 appuis du bouton et réactiver l'interruption après une pause de 5 secondes.
- Effectuez les tests pour démontrer les résultats

<details>
    <summary>Indice</summary>

- Utilisez l'instruction inverse de la fonction ```attachInterrupt``` pour désactiver spécifiquement l'interruption

</details>

### Étape 2 - Alertes aux radiations (optionnel)

#### Scénario

Vous habitez dans la région d'une centrale nucléaire ! Votre mandat consiste à programmer votre équipement pour détecter des radiations mettant en danger la santé de la population.

Lorsque le niveau radiation atteint un seuil, votre équipement active l'interruption du bouton pendant la période de risque. Le bouton doit être désactivé en temps normal; ceci évite les fausses alertes.

L'équipement de détection de radiations sera simulé par votre détecteur à ultra-sons HC-SR04 qui mesure des distances.

#### Montage

- Ajoutez un détecteur ultrasonique HC-SR04 à votre montage
- Utilisez les bornes ```16``` et ```17``` pour Echo et Trigger
- ***UTILISEZ LA TENSION ```3,3 V```*** pour alimenter le détecteur

#### Programmation

- Programmez le détecteur ultra-sonique pour faire clignoter la DEL NO 2 lorsque la distance mesurée se situe dans l'intervalle [ 0-8 ] cm.
- Dans ces conditions, l'interruption est activée. A chaque appui du bouton, une sirène retentit !
- Lorsque la menace est passée (intervalle > 8 cm), l'interruption est désactivée pour éviter de fausses alertes à la population
- Votre console affiche un journal des tests
