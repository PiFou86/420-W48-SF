# Module 14 - Introduction au microcontrôleur Esp32

## Exercice 1 - Programme de test

Ce programme fait clignoter la DELs soudée sur la carte Esp32. Cette DEL est reliée à la borne GPIO 02 (non à la NO 13 comme dans Arduino).

### Matériel

- Microcontrôleur Esp32
- câble USB-micro

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO

- nommez le projet Esp32Blink

-configurez le fichier platformio.ini. Ajouter la vitesse de communication série du Esp32.

<details>
    <summary>Configuration </summary>

[env:esp32doit-devkit-v1]

platform = espressif32

board = esp32doit-devkit-v1

framework = arduino

monitor_speed = 115200

</details>

### Étape 2 Exécution

- Entrez le code du programme Esp32Blink.ino

- Exécutez et déboggez votre environnement de développement

## Exercice 2 - Afficher les réseaux disponibles
 
Dans cet exercice, votre Esp32 affichera les réseaux SansFil à proximité.
 
### Matériel

- Microcontrôleur Esp32
- câble USB-micro
- environnement PlateformIO fonctionnel pour Esp32

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO nommé Esp32ListeSSIDs

- Entrez le code du programme Esp32ListeSSIDs.ino

- Exécutez et déboggez votre environnement de développement

<details>
    <summary>Connexion </summary>
  
3 networks found

1: MONSERVEURINTERNET (-25)*

2: monImprimanteWifi (-30)*

3: MonVoisinEloigne (-90)*

</details>

## Exercice 3 - Esp32 comme client Web
 
Dans cet exercice, votre Esp32 se connectera à un site web.

### Matériel

- Microcontrôleur Esp32
- câble USB-micro
- environnement PlateformIO fonctionnel pour Esp32

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO

- Nommez le projet Esp32ClientWeb

- Utilisez l'exercice précédent pour ajuster votre environnement de développement

- Entrez le code du programme esp32_client_web

- Exécutez et déboggez votre environnement de développement

- Observez les message à la  console  du programme. Vous devriez trouver un message comme celui-ci.

<details>
    <summary>Connexion </summary>

Try to Connect to: MONSERVEURINTERNET

............Connected to wifi

SSID:  MONSERVEURINTERNET

IP Address: 192.168.XXX.YYY

signal strength (RSSI):-26 dBm

</details>

### Étape 2 Boucle d'attente

- Ajouter un compteur dans la boucle d'attente de connexion. La boucle doit effectuer 10 tentatives avant de signaler un échec. 

## Exercice 4 - Esp32 comme serveur Web
 
Dans cet exercice, votre Esp32 servira de serveur web. Votre PC ou votre cellulaire pourra faire clingoter ou non la DEL bleu de la carte.

### Matériel

- Microcontrôleur Esp32
- câble USB-micro
- environnement PlateformIO fonctionnel pour Esp32

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO nommé Esp32_Web_server

- Utilisez l'exercice précédent pour ajuster votre environnement de développement

- Dans le répertoire, créez le fichier Credential.h qui contient la configuration de votre routeur 

- Entrez le code du programme Esp32_Web_server.ino

- Exécutez et déboggez votre environnement de développement

### Étape 2 Test de fonctionnement

- Notez l'adresse IP fournie dans la console du serveur web, à l'étape 1 (exemple 192.168.0.123)

- Ouvrez un navigateur et entrez l'adresse IP dans la fenêtre de l'URL

- Cliquez alternativement sur les boutons pour contrôler le clignotement de la DEL de l'Esp32.

<details>
    <summary>Affichage Console </summary>

New Client.

GET /L HTTP/1.1

Host: 192.168.0.195

User-Agent: Mozilla/5.0 (Windows NT 10.0; 
Win64; x64; rv:85.0) Gecko/20100101 Firefox/85.0

Accept: text/html,application/xhtml+xml,

application/xml;q=0.9,image/webp,*/*;q=0.8

Accept-Language: fr,fr-FR;q=0.8,en-US;q=0.5,en;

q=0.3

Accept-Encoding: gzip, deflate

Connection: keep-alive

Referer: http://192.168.0.XXX/H

Upgrade-Insecure-Requests: 1

</details>

### Interprétation du message

Dans cet exercice, la page principale est rafraichie à chaque fois que vous cliquez sur un lien. C'est pourquoi une reconnection est nécessaire. Ceci n'est qu'une démonstration!

### Étape 3 Questions

- Pourquoi faut-il entrer l'adresse ip plutôt que le lien URL pour accéder au serveur?

<details>
    <summary>Indice</summary>

- Aucune configuration DNS est disponible pour ce site web.

</details>

### Étape 5 Dépannage de connexion

Dans cet étape, vous allez vérifier l'existance du réseau.

### Étape 5.1 Dépannage sur PC et sur cellulaire

- Ouvrez une console CMD sur votre PC. Utilisez la commande ping pour vérifier la liaision avec l'adresse IP du serveur Esp32.

- Désactivez votre pare-feux et recommencez

- Si l'adresse IP est exacte et ne répond pas, votre serveur est inaxcessible

- Sur votre cellulaire, téléchargez l'application "network ping lite" (pour Iphones).  Utilisez l'application pour tester le ping avec le serveur Esp32

- Si l'adresse IP est exacte et ne répond pas, votre serveur est inaxcessible.

## Exercice 5 - WifiManager dans Esp32
 
WifiManage est votre gestionnaire complet pour votre projet. Il offre une très grande variété de méthodes pour administrer, gérer et programmer les services SansFil,

### Matériel

- Fichier Installation WifiManager.pdf

- Fichier WifiManager.ino
Microcontrôleur Esp32
- câble USB-micro
- environnement PlateformIO fonctionnel pour Esp32

### Étape 1 Configuration

- Installez WifiManager à l'aide du fichier InstallationWifiManager.pdf 

- Effectuez les tests de connectivité 

- NOTE IMPORTANTE

Le Esp32 mémorise le profil d'authentification en mémoire Flash. Pour effacer temporairement le profil, utilisez la méthode Wifi.disconnect()
 
 Ces quesques exerices vous permettent d'amorcer votre projet de station météo.