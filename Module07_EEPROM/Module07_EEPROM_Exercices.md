# Module 7 - EEPROM

<!-- 
## Exercice 1 - Enregistrement du statut d'une DEL

Vous devez créer un montage et un programme qui permet de faire varier l'intensité d'un éclairage à partir d'un bouton poussoir. Si un coupure de courant survient, le montage doit retrouver ses anciennes valeurs.

- Effectuez schéma électrique et ensuite le montage qui comprend un bouton et une DEL. La puissance de la DEL doit pouvoir varier : à chaque pression du bouton l'intensité de la DEL augment de 20%. Une fois arrivée à 100%, une pression supplémentaire fait passer l'intensité à 0%.
- Validez que votre montage et codez votre programme
- Testez votre montage et votre programme
- Modifiez votre programme afin qu'à chaque pression du bouton, vous sauvegardez l'intensité de la DEL dans l'EEPROM. Au démarrage de votre programme, l'intensité doit être lue de sorte que si une coupure de courant survient, au redémarrage de votre MCU, la DEL doit récupérer son intensité. -->

## Exercice 1 - Nombre de pressions

Vous devez créer un montage et un programme qui comptent le nombre de pressions effectuées sur 3 boutons. Chaque bouton correspond à l'appréciation des visiteurs d'une exposition : "Moment agréable mais sans plus", "J'ai passé un excellent moments" et "J'ai passé un excellent moment et je la recommande !". À l'appui d'une des boutons, une DEL clignote 2 fois afin d'indiquer à l'utilisateur que son choix a été comptabilisé. (Nous ne sommes pas loin d'une version simplifiée d'une machine à voter !). Si l'utilisateur appuie sur un des boutons plus de 3 secondes, le nombre de pressions de chaque bouton est affiché sur la console série. L'exposition devrait être visible par au plus 150 000 visiteurs au total. Une coupure de courant ne doit pas effacer les statistiques.

### Exercice 1.1 - Version non écologique

- Effectuez schéma et ensuite un montage qui comprend trois boutons et une DEL
- Utilisez la bibliothèque [UtilifyDigitalInput](https://github.com/PiFou86/UtilifyDigitalInput.git) pour gérer les boutons (voir le README de la bibliothèque pour les exemples d'utilisation)
- Validez que votre montage et codez votre programme
- Testez votre montage et votre programme

### Exercice 1.2 - Version écologique

Votre conception de programme précédent ne permet pas de valider le nombre d'écritures dans l'EEPROM. L'EEPROM a une durée de vie limitée (environ 100 000 écritures). Pour augmenter la durée de vie de l'EEPROM, il est préférable d'enregistrer le nombre d'écriture l'adresse de départ des données. Les données doivent inclure le nombre d'écritures en plus des autres données. Une fois un nombre d'écritures atteint, il faut changer d'adresse de stockage. Il est donc préférable de créer une classe qui gère l'écriture et la lecture des données dans l'EEPROM.

Pour cette version plus écologique, vous devez utiliser la bibliothèque [UtilifyEEPROM](https://github.com/PiFou86/UtilifyEEPROM.git). Basez-vous sur le code exemple du fichier README pour adapter votre code.
