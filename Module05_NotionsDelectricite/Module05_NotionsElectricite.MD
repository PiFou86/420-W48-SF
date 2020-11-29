# Module 05 - Notions d'Électricité

## Exercice 1 - Résistances en série

### Étape 1 - 2 Résistances en série

![2 Resistances en Série](imp/rs_220_220.png)

    2 Résistances en série

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I qui circule dans le circuit
- Calculez la tension aux bornes de chaque résistance

### Étape 2 - 3 Résistances en série

![3 Resistances en Série](imp/rs_220_440_660.png)

    3 Résistances en série

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I qui circulera dans le circuit
- Calculez la tension aux bornes de chaque résistance

### Qestions

- Quel est le rapport de tensions entre la résistance de 660 Ω et de 220 Ω?

## Exercice 2 - Résistances en parallèle

### Étape 1 - 3 Résistances en parallèle

![3 Resistances en parallèle](imp/rp_220_220_220.png)

    3 Résistances en parallèle

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I total qui allimente le circuit
- Calculez les 3 courants qui circulent dans chaque résistance

### Étape 2 - 3 Résistances en parallèle

![3 Resistances en parallèle](imp/rp_220_220_440.png)

    3 Résistances en parallèle

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente
- Calculez le courant I total qui allimente le circuit
- Calculez les 3 courants qui circulent dans chaque résistance

## Exercice 3 - Circuits combinés

### Étape 1 - 3 Résistances

![Circuit combiné 2 3](imp/rs_220_rp_440_440.png)

    Circuit combiné, 3 résistances

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente totale Ret pour le circuit complet

<details>
    <summary>indices</summary>

1. Effectuez le calcul de la résistance équivalente en parallèle Rep pour les 2 résistances en parallèle

2. La résistance Ret totale est donné par la  résistance de 220 Ω en série avec la résistance Rep

</details>

- Calculez le courant It total qui circule dans le circuit
- Calculez la tension aux bornes de la résistance de 220 Ω

- Calculez la tension aux bornes des résistances de 440 Ω en parallèle

<details>
    <summary>indices</summary>

1. la tension aux bornes de résistances en parallèle est la même. La tension peut être déduite de la tension totale et de la tension U aux bornes de la résistance de 220 Ω

2. le courant est calculé à partir de la formule U / R2 et U /R3

![Indice Circuit combiné 2 3](imp/rs_220_rp_440_440_Indice.png)

    Circuit combiné, 3 résistances

</details>

### Étape 2 - 5 Résistances (optionnel)

![Indice Circuit combiné 2 3](imp/rs_580_220_rp_440_440_1K.png)

    Circuit combiné, 5 résistances

À l'aide de l'illustration

- Effectuez le calcul de la résistance équivalente totale Ret pour le circuit complet
- Calculez le courant I total qui allimente le circuit
- Calculez le courant qui circule dans chaque résistance

## Exercice 4 - Simulation TInkerCad

### Objectif Simuler divers circuits

- Dans cet exercice, vous pourrez observer la valeur du courant et de la tension dans divers circuits série ou parallèle

### Montage du circuit

![MontageTinkerCad](imp/rs_220_440_660_A_V.png)

    Exemple de circuit de test

- Matériel
- - bloc d'alimentation

- - 2 multimètres

- - ensembles de résistances: 220 Ω, 440 Ω, 660 Ω

- Mettre en oeuvre le montale illustré dans TinkerCad
- Placez la tension du bloc d'alimentation à 6 V
- Placez le courant maximun à 1 Ampère

### Étape 1 - 3 Résistances en série

![3 Resistances en Série](imp/rs_220_440_660.png)

    3 Résistances en série

- Insérez les 3 résistances du schéma dans le circuit TinkerCad
- Placez le voltmètre aux bornes de la première résistance.
- Démarrez la simulation. Notez la valeur.
- Placez successivement le voltmètre aux bornes des autres résistances et notez les valeurs.
-La tension mesurée devrait correspondre aux valeurs que vous avez calculées dans les exercices précédents.

### Étape 2 - 3 Résistances en parallèle

![3 Resistances en Série](imp/rp_220_220_220.png)

    3 Résistances en parallèle

- Modifiez votre circuit pour représenter le schéma.
- Placez  l'ampèremètre dans  voltmètre sur chacune des résistances.
- La tension mesurée devrait correspondre aux valeurs que vous avez calculées dans les exercices précédents, sinon revoir vos calculs.

## Exercice 5 - Courbe de tension d'une del

### Objectifs 

1. Déterminer la tension de seuil
2. Déterminer la tension de claquage

Dans cet exercice, vous pourrez tracer la courbe de la fiche technique d'une del rouge, déterminer la tension de seuil et la tension de claquage sans risque!

### Montage du circuit

![CourbeDelRouge](imp/CourbeDelRouge.png)

    circuit de test pour une del

- Matériel
- - bloc d'alimentation

- - 2 multimètres

- - del de couleur rouge

- - résistance de 220 Ω

### Étape 1 - Tension de seuil

- Mettre en oeuvre le montale illustré dans TinkerCad
- Placez la tension d'alimentation à 0 V
- Placez le courant maximun à 1 A
- tournez progressivement le bouton de tension jusqu'à ce que la del s'allume. Notez la valeur de la tension de seuil.
- Pour une plus grande précision, utilisez la fenêtre de contrôle pour fixer la tension délivrée; utilisez un pas de 0,2 V entre chaque lecture.

### Étape 2 - Tension de claquage

- tournez progressivement le bouton de tension, avec un pas de 0.5 V, jusqu'à ce que TinkerCad fasse apparaître un message d'alerte.

- Notez la tension de claquage.

### Question

- Avec une résistance de charge est de 440 Ω . . .

1. la tension de seuil change-t-elle?
2. la tension de claquage change-t-elle?

- Avec une résistance de charge est de 440 Ω la tension de seuil change-t-elle?

FIN DE L'EXERCICE