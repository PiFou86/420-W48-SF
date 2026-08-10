# Module 7 - EEPROM

## Ce qui sera vu

- Conserver des compteurs en mémoire EEPROM malgré une coupure d'alimentation.
- Lire les boutons et confirmer la prise en compte d'un choix avec une DEL.
- Structurer les données persistantes et les afficher dans le moniteur série.
- Observer la limite du nombre d'écritures d'une EEPROM.
- Répartir les écritures afin de réduire l'usure prématurée de la mémoire.

## Prérequis

- Savoir lire plusieurs boutons sans rebond et commander une DEL, comme au module 06.
- Connaître les classes C++ simples et l'utilisation d'une bibliothèque PlatformIO.
- Savoir choisir un type entier adapté à une valeur maximale annoncée.
- Disposer d'une Arduino UNO, de trois boutons, d'une DEL et de la bibliothèque demandée.

<!-- 
## Exercice 1 - Enregistrement du statut d'une DEL

Vous devez créer un montage et un programme qui permettent de faire varier l'intensité d'un éclairage à partir d'un bouton-poussoir. Si une coupure de courant survient, le montage doit retrouver ses anciennes valeurs.

- Réalisez le schéma électrique, puis le montage comprenant un bouton et une DEL. À chaque pression du bouton, l'intensité de la DEL augmente de 20 %. Lorsqu'elle atteint 100 %, une pression supplémentaire la ramène à 0 %.
- Validez que votre montage et codez votre programme
- Testez votre montage et votre programme
- Modifiez votre programme afin qu'à chaque pression du bouton, vous sauvegardez l'intensité de la DEL dans l'EEPROM. Au démarrage de votre programme, l'intensité doit être lue de sorte que si une coupure de courant survient, au redémarrage de votre MCU, la DEL doit récupérer son intensité. -->

## Exercice 1 - Nombre de pressions

Vous devez créer un montage et un programme qui comptent le nombre de pressions sur trois boutons. Chaque bouton correspond à l'appréciation des visiteurs d'une exposition : « Moment agréable, mais sans plus », « J'ai passé un excellent moment » et « J'ai passé un excellent moment et je la recommande! ». Lorsqu'un bouton est pressé, une DEL clignote deux fois pour confirmer que le choix a été comptabilisé. Si l'utilisateur maintient un bouton pendant plus de trois secondes, le nombre de pressions de chaque bouton est affiché dans le moniteur série. L'exposition devrait accueillir au plus 150 000 visiteurs. Une coupure de courant ne doit pas effacer les statistiques.

### Exercice 1.1 - Version non écologique

- Dessiner votre schéma et ensuite effectuer le montage qui comprendra trois boutons et une DEL
- Utilisez la bibliothèque [UtilifyDigitalInput](https://github.com/PiFou86/UtilifyDigitalInput.git) pour gérer les boutons (voir le README de la bibliothèque pour les exemples d'utilisation)
- Validez votre montage et codez votre programme
- Testez votre montage et votre programme

### Exercice 1.2 - Version écologique

La conception précédente ne permet pas de suivre le nombre d'écritures dans l'EEPROM. Celle-ci a une durée de vie limitée, soit environ 100 000 écritures par cellule. Pour mieux répartir l'usure, enregistrez le nombre d'écritures avec les autres données et changez d'adresse de stockage lorsqu'un seuil est atteint. Créez une classe qui gère la lecture et l'écriture de ces données dans l'EEPROM.

Pour cette version plus écologique, vous devez utiliser la bibliothèque [UtilifyEEPROM](https://github.com/PiFou86/UtilifyEEPROM.git). Basez-vous sur le code exemple du fichier README pour adapter votre code.
