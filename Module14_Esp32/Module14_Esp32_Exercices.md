# Module 14 - Introduction au microcontrôleur ESP-32

## Exercice 1 - Programme de test

Ce programme fait clignoter la DELs soudée sur la carte Esp32. Cette DEL est reliée à la borne GPIO 02 (non à la NO 13 comme dans Arduino).

### Matériel

- Microcontrôleur ESP-32
- Câble micro USB
- Environnement PlateformIO fonctionnel pour ESP-32

### Étape 1 - Configuration

- Créez un nouveau projet dans PlateformIO
- Nommez le projet Esp32Blink
- Configurez le fichier platformio.ini. Ajouter la vitesse de communication série du Esp32.

<details>
    <summary>Configuration </summary>

```ini
[env:esp32doit-devkit-v1]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
monitor_speed = 115200
```

</details>

### Étape 2 Exécution

- Entrez le code du programme [Esp32Blink.ino](CorrectionPartielleEsp32/Esp32Blink.ino)
- Exécutez et déboguez votre environnement de développement

## Exercice 2 - Afficher les réseaux disponibles

Dans cet exercice, votre Esp32 affichera les réseaux SansFil à proximité.

### Matériel

- Microcontrôleur ESP-32
- Câble micro USB
- Environnement PlateformIO fonctionnel pour ESP-32

### Étape 1 - Configuration

- Créez un nouveau projet dans PlateformIO nommé "Esp32ListeSSIDs"
- Entrez le code du programme [Esp32ListeSSIDs.ino](CorrectionPartielleEsp32/Esp32ListeSSIDs.ino)
- Exécutez et déboguez votre environnement de développement

<details>
    <summary>Exemple de sortie</summary>

```
scan start
scan done
3 networks found
1: MONSERVEURINTERNET (-25)*
2: monImprimanteWifi (-30)*
3: MonVoisinEloigne (-90)*
```

</details>

## Exercice 3 - ESP-32 comme client WiFi (STA)

Dans cet exercice, votre Esp32 se connectera à un site web.

### Matériel

- Microcontrôleur ESP-32
- Câble micro USB
- Environnement PlateformIO fonctionnel pour ESP-32

### Étape 1 - Configuration

- Créez un nouveau projet dans PlateformIO
- Nommez le projet Esp32ClientWeb
- Utilisez l'exercice précédent pour ajuster votre environnement de développement
- Entrez le code du programme [Esp32ClientWifi](CorrectionPartielleEsp32/Esp32ClientWifi.ino)
- Exécutez et déboguez votre environnement de développement
- Observez les messages à la  console  du programme. Vous devriez trouver un message comme celui-ci.

<details>
    <summary>Exemple de sortie</summary>

```
Try to Connect to: MONSERVEURINTERNET
............Connected to wifi
SSID:  MONSERVEURINTERNET
IP Address: 192.168.XXX.YYY
signal strength (RSSI):-26 dBm
```

</details>

### Étape 2 - Boucle d'attente

- Ajouter un compteur dans la boucle d'attente de connexion. La boucle doit effectuer 10 tentatives avant de signaler un échec.

## Exercice 4 - ESP-32 comme serveur web

Dans cet exercice, votre ESP-32 servira de serveur web. Votre PC ou votre cellulaire pourra faire clingnoter ou non la DEL bleu de la carte.

### Matériel

- Microcontrôleur ESP-32
- Câble USB-micro
- Environnement PlateformIO fonctionnel pour ESP-32

### Étape 1 Configuration

- Créez un nouveau projet dans PlateformIO nommé Esp32_Web_server
- Utilisez l'exercice précédent pour ajuster votre environnement de développement
- Dans le répertoire, créez le fichier Credential.h qui contient la configuration de votre routeur :

```cpp
#pragma once

#define MYSSID "mon_ssid"
#define MYPSW  "Mon_mot_de_passe_hyper_securisé"
```

- Entrez le code du programme [Esp32_Web_server.ino](CorrectionPartielleEsp32/Esp32_Web_server.ino)
- Exécutez et déboguez votre environnement de développement

### Étape 2 Test de fonctionnement

- Notez l'adresse IP fournie dans la console du serveur web, à l'étape 1 (exemple 192.168.0.123)
- Ouvrez un navigateur et entrez l'adresse IP dans la fenêtre de l'URL
- Cliquez alternativement sur les boutons pour contrôler le clignotement de la DEL de l'Esp32.

<details>
    <summary>Exemple de sortie</summary>

```
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
```

</details>

Dans cet exercice, la page principale est rafraîchie à chaque fois que vous cliquez sur un lien. C'est pourquoi une reconnection est nécessaire. Ceci n'est qu'une démonstration!

### Étape 3 - Questions

- Pourquoi faut-il entrer l'adresse ip plutôt que le lien URL pour accéder au serveur?

<details>
    <summary>Indice</summary>

- Aucune configuration DNS est disponible pour ce site web.

</details>

### Étape 5 - Dépannage de connexion

Dans cet étape, vous allez vérifier l'existance du réseau :

- Ouvrez une console CMD sur votre PC. Utilisez la commande ping pour vérifier la liaision avec l'adresse IP du serveur Esp32.
- Désactivez votre pare-feux et recommencez
- Si l'adresse IP est exacte et ne répond pas, votre serveur est inaccessible
- Sur votre cellulaire, téléchargez l'application "network ping lite" (pour IPhones).  Utilisez l'application pour tester le ping avec le serveur ESP-32
- Si l'adresse IP est exacte et ne répond pas, votre serveur est inaccessible.

## Exercice 5 - WifiManager : créez votre point d'accès

WifiManage est votre gestionnaire complet pour votre projet. Il offre une très grande variété de méthodes pour administrer, gérer et programmer les services sans fil.

### Matériel

- Fichier [Installation WifiManager.pdf](CorrectionPartielleEsp32/InstallationWifiManager.pdf)
- Fichier [Esp32WifiManager.ino](CorrectionPartielleEsp32/Esp32WifiManager.ino)
Microcontrôleur Esp32
- Câble USB-micro
- Environnement PlateformIO fonctionnel pour ESP-32

### Étape 1 - Configuration

- Installez WifiManager à l'aide du fichier [InstallationWifiManager.pdf](CorrectionPartielleEsp32/InstallationWifiManager.pdf)
- Effectuez les tests de connectivité

**NOTE IMPORTANTE**

L'ESP-32 mémorise le profil d'authentification en mémoire Flash. Pour effacer temporairement le profil, utilisez la méthode Wifi.disconnect()
 
Ces quelques exercices vous permettent d'amorcer votre projet de station météo.
