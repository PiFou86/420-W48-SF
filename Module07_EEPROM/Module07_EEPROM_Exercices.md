# Module 7 - EEPROM

## Exercice 1 - Enregistrement du statut d'une DEL

Vous devez créer un montage et un programme qui permet de faire varier l'intensité d'un éclairage à partir d'un bouton poussoir. Si un coupure de courant survient, le montage doit retrouver ses anciennes valeurs.

- Effectuez schéma et ensuite un montage qui comprend un bouton et une DEL. La puissance de la DEL doit pouvoir varier. À chaque pression du bouton l'intensité de la DEL augment de 20%. Une fois arrivée à 100%, une pression supplémentaire fait passer l'intensité à 0%.
- Validez que votre montage et codez votre programme
- Testez votre montage et votre programme
- Modifiez votre programme afin qu'à chaque pression du bouton, vous sauvegardez l'intensité de la DEL dans l'EEPROM. Au démarrage de votre programme, l'intensité doit être lue de sorte que si une coupure de courant survient, au redémarrage de votre MCU, la DEL doit récupérer son intensité.

## Exercice 2 - Nombre de pressions

Vous devez créer une montage et un programme qui compte le nombre de pression effectuer sur 3 boutons. Chaque bouton correspond à l'appréciation des visiteurs d'une exposition : "Moment agréable mais sans plus", "J'ai passé un excellent moments" et "J'ai passé un excellent moment et je la recommande !". À l'appui d'une des boutons, une DEL clignote 2 fois afin d'indiquer à l'utilisateur que son choix a été comptabilisé. (Nous ne sommes pas loin d'une version simplifiée d'une machine à voter !). Si l'utilisateur appuie sur un des boutons plus de 3 secondes, le nombre de pressions de chaque bouton est affiché sur la console série. L'exposition devrait être visible par au plus 150 000 visiteurs au total. Une coupure de courant ne doit pas effacer les statistiques.

### Exercice 2.1 - Version non écologique

- Effectuez schéma et ensuite un montage qui comprend trois boutons et une DEL.
- Validez que votre montage et codez votre programme
- Testez votre montage et votre programme

### Exercice 2.2 - Version écologique (Optionnel)

Votre conception de programme précédent ne permet pas de réinitialiser les compteurs. Imaginez et codez une façon de résoudre ce problème et de permettre de réutiliser votre matériel pour une autre exposition.


## Exemple de diagramme de classes

Voici un exemple de modèle de diagramme de classes avec une généralisation en utilisant des génériques : on fournit une interface pour sauvegarder des données et on spécilise pour l'EEPROM. Quand vous aurez accès à un système de fichiers, vous pourrez simplement créer une nouvelle spécialisation.

![Exemple de diagramme de classes pour l'écriture de données](/images/Module07_EEPROM/wsd/exemple_cours_/EEPROM.png)
