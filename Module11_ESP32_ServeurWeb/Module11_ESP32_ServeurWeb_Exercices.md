# Module 11 - ESP32 - Serveur web

## Objectis

Dans ces exercices, vous aurez à utiliser les fonctionnalités des fichier .css et .js pour adapter des pages web selon les besoins décrits ici.
À l'aide de votre cellulaire, vous pourrez alors allumer ou éteindre des DELs.
Il ne faut PAS utiliser les fichiers .css et .js à partir de sites web comme bootstrap.min.css ou w3.css.
Les caractéristiques seront entreposés dans la mémoire Flash du ESP32. CECI LE REND AUTONOME

Vous aurez à modifier les classes Program.cpp, Webserveur.cpp et index.html pour répondre à ces exercices.

## Exercice 1 - Installation du serveur Web ESP32

### étape 1 - installation d'un serveur web

Dans cette étape, votre serveur web ESP32 affichera un court message html sur un client web. Ce client web peut être un cellulaire ou un navigateur web de votre PC.
- Créez une nouvelle application platformIO ```AMOC_Module11_Hello```. Utilisez le fichier . . ./AMOC_Module11_ServeurWebPrepCours/src/hello.cpp  dans Github

- Paramétrez l'identification au routeur.
    - ajoutez le fichier  ```Credential.h``` dans le répertoire include. Ajoutez-y les deux variables d'authentification   ```WIFI_SSID``` et  ```hWIFI_SSID```:

<details>
    <summary>Identifiant</summary>
 
    #define WIFI_SSID "VOTRE ROUTEUR INTERNET "
    #define WIFI_PASSWORD "MOT DE PASS DU ROUTEUR"

</details>
 
    - Ajoutez la déclaration de Credential.h à votre programe principal.
- Compiler et exécutez le programme
- Notez l'adresse IP du serveur Web généré par le DHCP

<details>
    <summary>Identifiant</summary>
 
    Connecté au réseau WiFi, adresse IP : 192.168.0.XXX

</details>

### étape 2 - affichage d'une page web sur un client web

- Ouvrez un navigateur web; entrez l'adresse du serveur web
- Le programme fonctionne si le texte "hello from esp32!" apparaît

## Exercice 2 - Initialisation du servuer web ESP32

### étape 1 - installation du système de fichiers SPIFSS pour ESP32

Dans cette étape, vous allez tester la mise en place des fichiers ```.css ``` , ```.js ``` et  ```html``` dans le système SPIFSS de votre serveur web.

- Créez une nouvelle application platformIO ```AMOC_Module11_ServeurWeb```. Créez une nouvelle structure ```data``` de votre application au niveau égal  à src.

![structure_SPIFSS](img/structure_SPIFSS.png)

- Copiez la structure ```data``` se trouvant dans le gitHub  ... /AMOC_Module11_ServeurWebPrepCours/data/. RESPECTEZ le nom des répertoires et fichiers

![MAJ_SPIFSS](img/miseAJourSPIFSS.png)

- construisez le système Filesystem image par les boutons Build Filesystemimage et Upload Filesystemimage . Le résultat devrait donner:

![MAJ_SPIFSS](img/BuildSPIFSS.png)

### étape 2 - Tester le système de fichiers SPIFSS pour ESP32

- Utilisez la partie en commentaires du fichier AMOC_Module11_ServeurWebPrepCours/src/main.cpp peut vous servir à tester l'installation. Pour cela, désactiver l'appel Programm et activer temporairement le code mis en commentaires. Compilez et exéctuez le test. Vous obtiendrez:

![MAJ_SPIFSS](img/JournalSPIFSS.png)

## Exercice 3 - Controler uen DEL à distance

Pour réaliser cet exercice , vous aurez besoin des classes main.cpp, Program.cpp, ServeurWeb.cpp dans votre application.

-Mettre en place le code. Compilez et exécutez le programme. Le résutat donne:

![MAJ_SPIFSS](img/consoleWebServeur.png)

-Notez l'adresse IP du serveur Web.

-À l'aide de votre cellulaire ou de votre PC, ouvrez un navigateur web. Entrez l'adresse IP du serveur web. Vous pourrez alors allumer ou éteindre  la DEL No2 sur la carte ESP32. Les boutons Allumer et Éteindre sont déjà programmés et fonctionnels.

## Exercice 4 - Afficher un état à distance

Dans cet exercice, vous allez ajouter un troisième bouton "État" au fichier html du client. Quand le client appuie sur ce bouton, il reçoit un message ```DEL allumée```ou ```DEL éteinte``` indiquant l'état de la borne reliée à la DEL.

## Exercice 5 - Paramétrer l'application

Dans cet exercices, vous allez effectuer les modifications pour remplacer la valeur "2" ("codée en dur") de la DEL soudée sur la carte pour une variable fournie au constructeur. Cette valeur peut prrendre les valeurs d'une borne GPIO du ESP32.

- Utilisez votre plaquette d'expérimentation pour vérifier votre application