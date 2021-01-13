
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

// Démos :
// 1. Affichage décimale de -11000 à 11000
// 2. Affichage hexadécimale de 0x0 à 0xFFFF
// 3. Affichage fixe décimale pour démo multiplexage. Changer compteur OCR1A à 8332;
#define DEMO                       1

#if DEMO == 1
#define BASE                       DEC
#define VALEURDEBUT                -1100
#define VALEURFIN                  11000
#elif DEMO == 2
#define BASE                       HEX
#define VALEURDEBUT                0x0
#define VALEURFIN                  0xFFFF
#elif DEMO == 3
#define BASE                       DEC
#define VALEURDEBUT                1234
#define VALEURFIN                  1234
#endif

#define RALENTIR_FREQUENCE_POUR_FILMER FALSE

// Utiliser le registre à décalage ou la connexion directe
#define UTILISER_REGISTRE_DECALAGE FALSE

// Définit s'il faut utiliser l'intéruption interne (timer) ou la boucle principale.
// L'utilisation du timer1 implique qu'il ne faut plus utiliser le PWM des pins 9 et 10
#define UTILISER_TIMER1            TRUE

// Utiliser pour débuger les temps sur l'oscilloscope avec l'entrée analogique A0 configurée en sortie
#define DEBUG_TIMER                TRUE

// Nombre maximum d'événements à surveiller dans la gestion d'événements
#define MAXIMUM_EVENEMENTS         16

// Utiliser directement les registres à la place des fonctions standard d'Arduino
#define OPTIMISE_ENTREESSORTIES    TRUE

// Délai entre deux exécutions du traitement de Traitement.cpp
#define DELAI_ENTRE_EXECUTION_TRAITEMENT 100


// Configuration compteur timer1
// (16,000,000Hz / (prescaler * desired interrupt frequency) ) - 1 => compteur
// compteur doit être < 65536
// Ici, prescaler = 64 :
// (16,000,000Hz / (64 * desired interrupt frequency) ) - 1 => compteur
// 1kHz = 1000Hz (16*10^6) / (64*1000) - 1    = 249
// Pour faire apparaitre le multiplexage dans la démo filmée :
// 30Hz (16*10^6) / (64*1000) - 1 = 8332

#if !RALENTIR_FREQUENCE_POUR_FILMER
#define TIMER1_VALEUR_A_COMPARER         249
#else
#define TIMER1_VALEUR_A_COMPARER         8332
#endif
