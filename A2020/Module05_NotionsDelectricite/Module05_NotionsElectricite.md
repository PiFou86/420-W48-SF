# Module 05 - Notions d'Électricité

## Exercice 1 - Résistances en série

### Étape 1 - 2 Résistances en série

![2 Resistances en Série](img/rs_220_220.png)

    2 Résistances en série

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I qui circule dans le circuit
- Calculez la tension aux bornes de chaque résistance

<details>
    <summary>Solution</summary>

Rt = 220 + 220 = 440 &#8486;  
U1 = 220 * 13,43 = 3 V  
U2 = 220 * 13,43 = 3 V  
It = 6 / 440 = 13,6 mA

![2 Resistances en Série - Solution](img/rs_220_220_solution.png)

</details>

### Étape 2 - 3 Résistances en série

![3 Résistances en Série](img/rs_220_440_660.png)

    3 Résistances en série

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I qui circulera dans le circuit
- Calculez la tension aux bornes de chaque résistance

<details>
    <summary>Solution</summary>

Rt = 220 + 440 + 660 = 1320 &#8486;  
U1 = 4,6 * 220 = 1 V  
U2 = 4,6 * 440 = 2 V  
U3 = 4,6 * 660 = 3 V  
It = 6 / 1320 = 4,6 mA

![3 Résistances en Série - Solution](img/rs_220_440_660_solution.png)

</details>

### Qestions

- Quel est le rapport de tensions entre la résistance de 660 Ω et de 220 Ω?

## Exercice 2 - Résistances en parallèle

### Exercice 2.1 - 3 Résistances en parallèle

![3 Résistances en parallèle](img/rp_220_220_220.png)

    3 Résistances en parallèle

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I total qui alimente le circuit
- Calculez les 3 courants qui circulent dans chaque résistance

<details>
    <summary>Solution</summary>

1 / Rt = 1 / 220 + 1 / 220 + 1 / 220 = 3 / 220 => Rt = 73,3 &#8486;  
U1 = U2 = U3 = 6 V  
It = 6 / 73,3 = 81,9 mA  
I1 = I2 = I3 = 27,3 mA  

![3 Résistances en parallèle - Solution](img/rp_220_220_220_solution.png)

</details>

### Exercice 2.2 - 3 Résistances en parallèle

![3 Resistances en parallèle](img/rp_220_220_440.png)

    3 Résistances en parallèle

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I total qui alimente le circuit
- Calculez les 3 courants qui circulent dans chaque résistance

<details>
    <summary>Solution</summary>

1 / Rt = 1 / 220 + 1 / 220 + 1 / 440 = 5 / 440 => Rt = 88 &#8486;  
U1 = U2 = U3 = 6 V  
It = 6 / 88 = 68,2 mA  
I1 = 27,3 mA  
I2 = 27,3 mA  
I3 = 13,6 mA

![3 Résistances en parallèle - Solution](img/rp_220_220_440_solution.png)

</details>

## Exercice 3 - Circuits combinés (Optionnel)

### Exercice 3.1 - 3 Résistances

![Circuit combiné 2 3](img/rs_220_rp_440_440.png)

    Circuit combiné, 3 résistances

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente totale Ret pour le circuit complet

<details>
    <summary>Indices 1 / 2</summary>

1. Effectuez le calcul de la résistance équivalente en parallèle Rep pour les 2 résistances en parallèle

2. La résistance Ret totale est donné par la  résistance de 220 Ω en série avec la résistance Rep

</details>

- Calculez le courant It total qui circule dans le circuit
- Calculez la tension aux bornes de la résistance de 220 Ω

- Calculez la tension aux bornes des résistances de 440 Ω en parallèle

<details>
    <summary>Indices 2 / 2</summary>

1. la tension aux bornes de résistances en parallèle est la même. La tension peut être déduite de la tension totale et de la tension U aux bornes de la résistance de 220 Ω

2. le courant est calculé à partir de la formule U / R2 et U /R3

![Indice Circuit combiné 2 3](img/rs_220_rp_440_440_Indice.png)

    Circuit combiné, 3 résistances

</details>

<details>
    <summary>Solution</summary>

1 / Re1 = 1 / 440 + 1 / 440 = 1 / 220 => Re1 = 220 &#8486;  
Rt = 440 &#8486;  
It = 6 / 440 = 13,6 mA  
U1 = 220 * 0.0136 = 3V  
U2 = U3 = 220 * 0.0136 = 3V  
I2 = 3 / 440 = 6,8 mA   
I3 = 3 / 440 = 6,8 mA

![Solution Circuit combiné 2 3](img/rs_220_rp_440_440_solution.png)

</details>

### Exercice 3.2 - 5 Résistances

![Indice Circuit combiné 2 3](img/rs_580_220_rp_440_440_1K.png)

    Circuit combiné, 5 résistances

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente totale Ret pour le circuit complet
- Calculez le courant I total qui alimente le circuit
- Calculez le courant qui circule dans chaque résistance

<details>
    <summary>Solution</summary>

Re1 = 180.33 &#8486;  
Rt = 580 + 220 + 180.33 = 980.33  
It = 6 / 980.33 = 6.1 mA  
U1 = 580 * 0.0061 = 3,54 V  
U2 = 220 * 0.0061 = 1.34 V V  
Ue1 = U3 = U4 = U5 = 180.33 * 0.0061 = 1.1 V  
I3 = I4 = 1.1 / 440 = 2.5mA  
I5 = 1.1/1000 = 1.1 mA 

![Circuit combiné 2 3](img/rs_580_220_rp_440_440_1K_solution.png)

</details>

## Exercice 4 - Simulation TInkerCad

### Objectif Simuler divers circuits

- Dans cet exercice, vous pourrez observer la valeur du courant et de la tension dans divers circuits série ou parallèle

### Montage du circuit

![MontageTinkerCad](img/rs_220_440_660_A_V.png)

    Exemple de circuit de test

- Matériel
  - bloc d'alimentation
  - 2 multimètres
  - ensembles de résistances: 220 Ω, 440 Ω, 660 Ω

- Mettre en oeuvre le montage illustré dans TinkerCad
- Placez la tension du bloc d'alimentation à 6 V
- Placez le courant maximum à 1 Ampère

### Étape 1 - 3 Résistances en série

![3 Resistances en Série](img/rs_220_440_660.png)

    3 Résistances en série

- Insérez les 3 résistances du schéma dans le circuit TinkerCad
- Placez le voltmètre aux bornes de la première résistance.
- Démarrez la simulation. Notez la valeur.
- Placez successivement le voltmètre aux bornes des autres résistances et notez les valeurs.
- La tension mesurée devrait correspondre aux valeurs que vous avez calculées dans les exercices précédents.

### Étape 2 - 3 Résistances en parallèle

![3 Resistances en Série](img/rp_220_220_220.png)

    3 Résistances en parallèle

- Modifiez votre circuit pour représenter le schéma.
- Placez  l'ampèremètre dans  voltmètre sur chacune des résistances.
- La tension mesurée devrait correspondre aux valeurs que vous avez calculées dans les exercices précédents, sinon revoir vos calculs.

<details>
    <summary>Solution</summary>

![3 résistances en parallèle sous Tinkercad](img/rp_220_220_220_tinkercad_solution.png)

</details>

## Exercice 5 - Courbe de tension d'une del

### Objectifs

1. Déterminer la tension de seuil
2. Déterminer la tension de claquage

Dans cet exercice, vous pourrez tracer la courbe de la fiche technique d'une del rouge, déterminer la tension de seuil et la tension de claquage sans risque!

### Montage du circuit

![CourbeDelRouge](img/CourbeDelRouge.png)

    circuit de test pour une del

- Matériel
  - Bloc d'alimentation
  - 2 multimètres
  - DEL de couleur rouge
  - Résistance de 220 Ω

### Étape 1 - Tension de seuil

- Mettre en oeuvre le montage illustré dans TinkerCad
- Placez la tension d'alimentation à 0 V
- Placez le courant maximum à 1 A
- Tournez progressivement le bouton de tension jusqu'à ce que la del s'allume. Notez la valeur de la tension de seuil.
- Pour une plus grande précision, utilisez la fenêtre de contrôle pour fixer la tension délivrée; utilisez un pas de 0,2 V entre chaque lecture.

### Étape 2 - Tension de claquage

- Tournez progressivement le bouton de tension, avec un pas de 0.5 V, jusqu'à ce que TinkerCad fasse apparaître un message d'alerte

- Notez la tension de claquage

### Question

- Avec une résistance de charge de 440 Ω :

1. La tension de seuil change-t-elle ?
2. La tension de claquage change-t-elle ?

- Avec une résistance de charge  de 440 Ω la tension de seuil change-t-elle ?

<details>
    <summary>Solution</summary>

Non les tensions de seuil et de claquage dépendent uniquement de la fabrication du matériau.
</details>
