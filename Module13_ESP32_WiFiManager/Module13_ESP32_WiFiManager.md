# Module 13 - ESP32 - WiFiManager

## Objectifs

Dans ces exercices, vous allez mettre en place un gestionnaire de connexion Wifi. La librairie ```WifiManager``` simplifie la connexion de votre ESP32 à divers réseaux wifi en mémorisant les paramètres de connexion.

La librairie offre même une "voie de contournement". Si la connexion échoue, une connexion vers un portail web dirige le client pour :

- Afficher les accès Wi-Fi visibles
- Se connecter à un réseau particulier avec le "bon" mot de passe
- Sauvegarder ce nouveau profil pour les prochaines connexions

Les étapes des exercices peut donc se résumer à :

1. Faire échec à la connexion (votre ESP32 n'a pas encore le profil pour une connexion)
2. Démarrer un portail de configuration donnant la liste des réseaux WiFi disponibles
3. Choisir et s'authentifier sur un des réseaux
4. Sauvegarder le profil pour les prochaines connexions

## Exercice 1 - Configurez un objet de type ```WiFiManager``` pour la première fois

### Étape 1 - Installer la bibliothèque WiFiManager

- Utilisez les diapositives pour importer WiFiManager (***Ne passer pas par la fenêtre d'ajout de bibliothèque de Pio, mettez l'adresse du dépôt Git dans ```platformio.ini```)
- Dans votre fichier ```main.cpp```, créez un objet de type ```WiFiManager```
- Compilez votre programme pour valider que la bibliothèque est bien installée
- Codez la configuration de votre objet dans la fonction ```setup``` comme illustré dans le cours
- Codez un site web qui répond sur le port 80. Il doit répondre ```Bienvenue sur mon site Web```

### Étape 2 - Configurer un profil client avec  WiFiManager

- Au premier démarrage, la connexion est en échec. C'est normal, parce qu'aucun profil n'a été détecté par l'application

![PremierDemarrage](img/PremierDemarrage.png)

- Sur la liste des réseaux visible de votre cellulaire, recherchez le réseau nommé par votre application (exemple : ESP32_wm)
- Un portail s'ouvre automatiquement
- Si le portail ne se lance à la connexion sur le réseau Wi-Fi de l'ESP32, entrez l'adresse IP configurée (exemple : 192.168.23.1)
- "Configuration WiFi" permet de choisir le profil pour un réseau particulier

![WifiSetup](img/ConfigureWiFi.png)

- Sur la liste, choisissez un réseau Wi-Fi pour connecter votre ESP32 (exemple : "CLOCHE_123")
- Entrez les informations de mot de passe
- Sauvegardez le profil

![WifiSetup](img/Sauvegarde_2.png)

![WifiSetup](img/Sauvegarde_3.png)

- Sur la console de votre ESP32, notez l'adresse IP (normalement générée par DHCP)
- Assurez-vous que votre cellulaire peut rejoindre le réseau WiFi choisi (exemple : "CLOCHE_123")
- Ouvrez un navigateur web pour vous connecter à l'adresse IP du serveur Web
- Le message  ```Bienvenue sur mon site Web``` devrait apparaître en format texte non formatté.

## Exercice 2 -  Remise à zéro du profil dans WiFiManager

La méthode wm.erase() efface le profil enregistré. Cette méthode permet de changer de réseau à chaque démarrage du programme.

- Activez l'instruction ```wm.erase()```
- Activez l'instruction ```wm.setDebugOutput(true);``` de votre déboggeur d'application

***Cette façon de faire doit être supprimée À LA FIN DES TESTS***

- Compilez et exécutez le programme
- Le message d'invitation au portail revient

![PremierDemarrage](img/PremierDemarrage.png)

- Reprenez l'étape 2 pour un tester un nouveau profil
- NE PAS OUBLIER : placez l'instruction ```wm.erase()``` en commentaires
- NE PAS OUBLIER : placez l'instruction ```wm.setDebugOutput(true);``` en commentaires

## Exercice 3 -  Bouton de remise à zéro (optionnel)

Vous venez de démontrer comment remettre à zéro le profil du serveur web habité sur votre ESP32.

Il faut reconnaître que cette façon de faire est peu pratique, car elle exige une recompilation successive.

La façon conventionnelle de faire cette opération consiste à appuyer sur un bouton-poussoir pour remettre à zéro le profil.

- Reliez un bouton poussoir de votre plaquette d'expérimentation sur la borne GPIO 25 de votre Esp32. Ajoutez un fil de retour à la terre (GND)
- Ajoutez le code de programmation du bouton-poussoir (module précédent) qui appellera l'instruction ```wm.erase()``` et l'instruction ```ESP.reset()```lorsque vous appuyez sur le bouton
- Ajoutez un message à la console pour aviser de cette action
- Compilez et exécutez le programme
- Appuyez sur le bouton-poussoir
- Appuyez sur le bouton "reset" pour amorcer le programme depuis le début

Le programme devrait passer en mode équivalente à l'étape 2

## Exercice 4 - On coupe le fil !

Ce travail doit s'effectuer à deux avec deux ESP32.

### Exercice 4.1 - Périphérique serveur

Le premier montage comprend un ESP32 et une DEL rouge.

Le programme interne doit créer le point d'accès "IoT_M13_Ex04_<numéroMatricule>" et exposer un site sur le port 80.

L'API du site doit être comme suit :

| Ressource       | Méthode | Résultat                                              |
|-----------------|---------|-------------------------------------------------------|
| /coeur-reacteur | GET     | Renvoie l'état du coeur du réacteur - code 200        |
| /coeur-reacteur | PUT     | Permet de modifier l'état du coeur et renvoie le nouvel état - code 200|

L'objet d'état doit être au format suivant :
```json
{
    "etat": "actif"
}
OU
{
    "etat": "repos"
}
```

Quand l'état est au repos, la DEL rouge est éteinte. Quand l'état est actifi, la DEL rouge est allumée.

### Exercice 4.2 - Périphérique client

Le deuxième montage comprend un ESP32, un bouton et deux DELs (une rouge, une verte).

Ce montage doit envoyer les demandes d'allumage ou d'extinction d'un appareil. Pour ce faire ce montage va appeler l'API exposée sur le premier montage.

À l'appuie sur le bouton poussoir, une requête ```PUT``` est envoyé sur l'API :

- Si le coeur est déjà actif, envoyez une requête de mise en repos
- Si le coeur est au repos, envoyez une requêtre d'activation

Si le coeur est dans l'état actif, la DEL rouge est allumée. Si le coeur est inactif, la DEL verte est allumée. Vous devez valider l'état du coeur au moins une fois toutes les secondes.
