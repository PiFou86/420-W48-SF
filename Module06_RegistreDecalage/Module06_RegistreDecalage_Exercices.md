# Module 06 - Registre à décalage

Dans les exercices suivants, chaque led représente un bit d'un entier codé sur 8 bits.

## Exercice 1 - Préparation du premier montage

Reprenez le diagramme du cours et créez le sur Tinkercad.

### Matériel

- Une platine d'essais
- 8 DELs
- 8 résistances 500 Ohms
- 1 arduino
- 1 registre à décalage 75HC595N

### À coder

Effectuez les actions suivantes :

- Affichez la valeur 3 avec vos DELs et testez le
- Affichez la valeur 4 avec vos DELs et testez le
- Affichez la valeur 42 avec vos DELs et testez le
- Généralisez une fonction qui prend une valeur en paramètre, les bornes et qui l'affiche

<details>
<summary>Indice</summary>

Inspirez vous de l'exemple du cours du module 04 sur le codage d'une couleur RVB dans un entier. Ici, vous n'avez pas à traiter les informations par 8 bits, mais bit par bit. Le décalage et le masque seront donc relatifs à 1 bit au lieu des 8 du cours.

</details>

## Exercice 2 - Préparation du premier montage

Reprenez le diagramme du cours et créez le sur Tinkercad.

### Matériel

- Une platine d'essais
- 8 DELs
- 8 résistances 500 Ohms
- 1 arduino
- 1 registre à décalage 75HC595N

### À coder

Effectuez les actions suivantes :

- Codez la classe "RegistreDecalage" qui permet d'envoyer un byte au registre.
- Codez un sketch qui permet d'afficher un compteur de 0 à 255 et qui repart à 0 à la fin : chaque led correspond à l'affichage d'un bit

## Exercice 3 - Chenillard

Reprenez votre montage précédent et votre classe "RegistreDecalage".

### Matériel

- Une platine d'essais
- 8 DELs
- 8 résistances 500 Ohms
- 1 arduino
- 1 registre à décalage 75HC595N

### À coder

Faites une animation qui permet de simuler un point qui se déplace de la droite vers la gauche et inversement quand le point est arrivé à une extrémité.

## Exercice 4 - K2000

Reprenez votre montage précédent et votre classe "RegistreDecalage".

### Matériel

- Une platine d'essais
- 8 DELs
- 8 résistances 500 Ohms
- 1 arduino
- 1 registre à décalage 75HC595N

### À coder

Faites une animation qui permet de simuler trois points qui se déplacent de la droite vers la gauche et inversement quand le dernier point est arrivé à une extrémité.

<details>
    <summary>Indice</summary>

Vous manipulez un byte pour l'affichage. Pourquoi ne pas manipuler un int (16 bits) et n'afficher que les 8 du centre ?

GGGG UUUU UUUU DDDD :

- GGGG : dépassement à gauche
- DDDD : dépassement à droite
- UUUU UUUU : bits utiles pour l'affichage

</details>

## Exercice 5 - Horloge binaire (Optionnel)

Reprenez votre montage précédent et votre classe "RegistreDecalage".

### Matériel

- Une platine d'essais
- 8 DELs
- 8 résistances 500 Ohms
- 1 arduino
- 1 registre à décalage 75HC595N

### À coder

La lecture de l'heure et des minutes s'effectuent par la console avec le format suivant "hh:mm" où hh est le nombre d'heure et mm le nombre de minutes.

Une fois définie, l'heure s'affiche sur les 8 DELs : on alterne l'affichage des heures et des minutes. Pour les différencier, on éteint les DELs une seconde, puis on affiche les heures une seconde, puis les minutes une seconde.

Quel délai devez-vous mettre pour avoir une vrai seconde ?
