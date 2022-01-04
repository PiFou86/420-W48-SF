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

Le but de cet exercice est de créer deux applications différentes. La première simule un réacteur nucléaire qui peut être contrôlé à distance par une API REST. Le second simule le contrôle à distance du réacteur.

Pour chaque équipe, un étudiant effectue l'exercice 4.1, l'autre l'exercice 4.2. La remise est individuelle : chacun remet sa partie.

Ce travail doit s'effectuer à deux avec deux ESP32. C'est un exercice récapitulatif des modules précédents sur l'ESP32 et ses possibilités réseau. Il est préparatoire aux prochains travaux pratiques.

Pour cet exercice, vous n'avez pas besoin de "WiFiManager".

Afin de vous facilité le travail à la maison qui sera individuel, nous vous proposons une application .Net MVC qui vous permet de simuler aussi bien le client que le serveur. La solution "M13_CoeurReacteurCSharp" se trouve à la racine de ce dossier. Pour la faire fonctionner, il faut avoir [.Net 6.0](https://dotnet.microsoft.com/en-us/download/dotnet/6.0).

### Exercice 4.1 - Réacteur nucléaire - Périphérique serveur

Le premier montage comprend un ESP32 et une DEL rouge. Quand l'état du réacteur est "repos", la DEL rouge est éteinte. Quand l'état est "actif", la DEL rouge est allumée.

#### Exercice 4.1.1 - Connection à votre réseau domestique ou création d'un point d'accès en cas d'échec

Le programme interne doit essayer de se connecter sur votre réseau domestique. S'il n'y arrive pas, il doit créer le point d'accès "IoT_M13_Ex04_<numéroMatricule>".

#### Exercice 4.1.2 - Création de l'API REST

Votre programme interne doit exposer une application web sur le port 80. L'application web comprend une API REST qui permet de piloter le coeur du réacteur.

L'API est définie comme suit :

| Ressource       | Méthode | Résultat                                              |
|-----------------|---------|-------------------------------------------------------|
| /coeur-reacteur | GET     | Renvoie l'état du coeur du réacteur - code 200        |
| /coeur-reacteur | PUT     | Permet de modifier l'état du coeur et renvoie le nouvel état - code 200 |
| *               | OPTIONS | Permet de fournir les options de communication pour la ressource - code 204 : le code de cette route est donnée plus bas |

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

#### Exercice 4.1.3 - Prise en charge de CORS - Route OPTIONS

Afin de pouvoir faire des tests avec un navigateur web, il est nécessaire de permettre l'accès à l'API. Pour cela, il faut répondre aux requêtes OPTIONS du navigateur. Cela permet de préciser les méthodes HTTP autorisées pour une ressource. Cela permet également de préciser les headers autorisés. Dans notre cas, nous autorisons toutes les méthodes HTTP et tous les headers.

Pour la route "*" avec la méthode "OPTIONS", le serveur doit renvoyer une liste des méthodes supportées par la ressource :

```cpp
#include <uri/UriRegex.h>

// ...
// Ici je suppose que vous définissez la classe ServeurWeb
// et que vous avez une donnée membre "m_webServer" de type WebServer.
// Si ce n'est pas le cas, adaptez le code suivant
ServeurWeb::ServeurWeb(/* ... */) {
  // ...
  this->m_webServer->on(Uri("/coeur-reacteur"), HTTPMethod::HTTP_GET,
                        [this]() { /* ... */ });
  this->m_webServer->on(Uri("/coeur-reacteur"), HTTPMethod::HTTP_PUT,
                        [this]() { /* ... */ });
                        });
  this->m_webServer->on(UriRegex(".*"), HTTPMethod::HTTP_OPTIONS,
                        [this]() {
                          this->optionsCors();
                        });  
  this->m_webServer->onNotFound(
      [this]() { this->ressourceNonTrouvee(this->m_webServer->uri()); });

  this->m_webServer->begin();
  // ...
}

// ...

void ServeurWeb::optionsCors() const {
  this->m_webServer->sendHeader("Access-Control-Allow-Origin", "*");
  this->m_webServer->sendHeader("Access-Control-Max-Age", "600");
  this->m_webServer->sendHeader("Access-Control-Allow-Methods", "PUT,POST,GET,OPTIONS");
  this->m_webServer->sendHeader("Access-Control-Allow-Headers", "*");
  this->m_webServer->send(204);
}

void ServeurWeb::envoyerCors() const {
  this->m_webServer->sendHeader("Access-Control-Allow-Origin", "*");
}
```

#### Exercice 4.1.4 - Prise en charge de CORS - Ajout des headers CORS

Dans vos routes, il faut ajouter les headers CORS. Pour cela, avant d'appeler la méthode send() de la classe WebServer, il faut appeler la méthode "envoyerCors" :

```cpp
// ...
    this->envoyerCors();
    this->m_webServer->send(200, "text/json", /* ... */);
```

#### Exercice 4.1.5 - Votre collègue n'est pas prêt ou vous travaillez seul de chez vous ?

Si votre collègue n'est pas prêt ou que la situation vous oblige à travailler seul, vous pouvez utiliser un serveur web local. Pour cela, vous allez devoir connecter votre ESP32 à votre réseau WiFi local. Ce point est traité dans le point 4.1.1. La première étape est donc de valider que vous y arrivez bien et que votre ESP32 et votre ordinateur sont sur le même réseau. Pour vous aidez, récupérez l'adresse IP de votre ESP32 sur votre trace ainsi que l'adresse IP de votre ordinateur à l'aide des commandes ```ipconfig``` (Windows), ```ifconfig``` (Mac / Linux) ou ```ip a``` (Linux si ifconfig non installé).

Ensuite récupérez la solution Visual Studio "M13_CoeurReacteurCSharp" qui se trouve à la racine de ce module.

Pour lancer l'application, vous pouvez soit passer par Visual Studio en ouvrant la solution ou vous pouvez lancer l'exécution dans une console en vous plaçant dans le répertoire du projet et en tapant la commande ```dotnet run```.

L'application expose un site sur le port 80 de votre ordinateur. Vous pouvez accéder à ce site en lançant votre navigateur web et en tapant l'adresse suivante : http://localhost:80. Vous pouvez tester l'application web en validant que le statut de la simulation fonctionne quand vous cliquez sur le bouton "Activer le coeur" ou "Désactiver le coeur".

![Application web du simulateur - État repos](img/ex4_simulateur_repos.png)
![Application web du simulateur - État actif](img/ex4_simulateur_actif.png)

Une fois l'application web en marche, vous pouvez modifier l'adresse du serveur web dans le champ "Adresse du serveur web" de l'application web. Dans l'exemple suivant, l'ESP32 est sur le même réseau que l'ordinateur qui affiche l'application web et a comme adresse IP "192.168.2.139" :

![Utilisation du client web pour un ESP32](img/ex4_simulateur_client_ESP32_actif.png)

On peut observer que l'application web affiche le statut du coeur. Si vous cliquez sur le bouton "Activer le coeur" ou sur le bouton "Désactiver le coeur", l'application web effectue une requête sur l'API REST de l'ESP32 et affiche le statut du coeur.

Si cela ne fonctionne pas, vous devriez avoir le symbole de l'erreur d'affiché :

![Utilisation du client web pour un ESP32 - Erreur](img/ex4_simulateur_client_web_page_erreur.png)

Dans le cas d'une telle erreur, ouvrez le mode développeur du navigateur et affichez la trace réseau. À partir de celle-ci, vous pourrez investiguer le problème :

- Validez que vous êtes bien connecté à votre réseau WiFi local
- Validez que vous êtes capable d'effectuer une requête ICMP de votre ordinateur vers l'ESP32 (Ping)
- Validez que votre l'API de votre ESP32 répond sur les bonnes routes avec les bons verbes
- Validez que l'application web est bien démarrée et que vous pouvez y accéder
- Validez que vous avez bien ajouté les entêtes pour désactiver les sécurités pour CORS

Si vous n'avez pas suivi les étapes pour CORS, vous allez avoir les erreurs suivantes dans la partie réseau et dans la partie console :

![Utilisation du client web pour un ESP32 - Erreur - Réseau](img/ex4_simulateur_client_web_reseau_erreur.png)
![Utilisation du client web pour un ESP32 - Erreur - Console JavaScript](img/ex4_simulateur_client_web_console_erreur.png)

Une fois les problèmes résolus, la partie réseau devrait ressembler à :

![Utilisation du client web pour un ESP32 - Pas de problème - Réseau](img/ex4_simulateur_client_web_reseau_ok.png)

### Exercice 4.2 - Périphérique client

Le deuxième montage comprend un ESP32, un bouton et deux DELs (une rouge, une verte). La DEL verte permet d'indiquer que le coeur du réacteur est au repos. La DEL rouge indique que le coeur du réacteur est actif. Pour connaître l'état du réacteur, vous devez utiliser l'API REST de votre collègue (n'oubliez pas de vous connecter sur le même réseau !). À l'appui du bouton, si le coeur du réacteur est au repos, il devient actif. Si le coeur du réacteur est actif, il devient au repos.

#### Exercice 4.2.1 - Connection à votre réseau domestique ou au point d'accès créé par l'équipier

Écrivez le code qui permet de se connecter sur votre réseau domestique ou sur le point d'accès créé par l'équipier. Gardez le tout configurable facilement car vous risquez de devoir alterner entre votre réseau domestique et le point d'accès créé par votre collègue.

#### Exercice 4.2.2 - Affichage du statut du coeur du réacteur

- Écrivez le code qui permet d'interroger l'API REST décrite dans la section 4.1.2 afin de savoir si le réacteur est actif ou au repos.
- Écrivez le code qui permet d'aller chercher cet état toute les 2000 millisecondes. Ce temps doit être facilement paramétrable. Une fois le statut récupéré, vous devez afficher le statut à l'aide de la DEL verte ou rouge.

#### Exercice 4.2.3 - Prise en charge du bouton

- Écrivez le code qui permet de détecter l'appui sur le bouton. À l'appuie sur le bouton poussoir, vous devez valider le statut actuel du réacteur et ensuite envoyer le bon ordre au réacteur à l'aide d'une requête ```PUT``` :

- Si le coeur est déjà actif, envoyez une requête de mise en repos
- Si le coeur est au repos, envoyez une requête d'activation

#### Exercice 4.2.4 - Votre collègue n'est pas prêt ou vous travaillez seul de chez vous ?

Si votre collègue n'est pas prêt ou que la situation vous oblige à travailler seul, vous pouvez utiliser un serveur web local. Pour cela, vous allez devoir connecter votre ESP32 à votre réseau WiFi local. Ce point est traité dans le point 4.2.1. La première étape est donc de valider que vous y arrivez bien et que votre ESP32 et votre ordinateur sont sur le même réseau. Pour vous aidez, récupérez l'adresse IP de votre ESP32 sur votre trace ainsi que l'adresse IP de votre ordinateur à l'aide des commandes ```ipconfig``` (Windows), ```ifconfig``` (Mac / Linux) ou ```ip a``` (Linux si ifconfig non installé).

Ensuite récupérez la solution Visual Studio "M13_CoeurReacteurCSharp" qui se trouve à la racine de ce module.

Pour lancer l'application, vous pouvez soit passer par Visual Studio en ouvrant la solution ou vous pouvez lancer l'exécution dans une console en vous plaçant dans le répertoire du projet et en tapant la commande ```dotnet run```.

L'application expose un site sur le port 80 de votre ordinateur. Vous pouvez accéder à ce site en lançant votre navigateur web et en tapant l'adresse suivante : http://localhost:80. Vous pouvez tester l'application web en validant que le statut de la simulation fonctionne quand vous cliquez sur le bouton "Activer le coeur" ou "Désactiver le coeur".

![Application web du simulateur - État repos](img/ex4_simulateur_repos.png)
![Application web du simulateur - État actif](img/ex4_simulateur_actif.png)

Une fois le simulateur lancé, vous devez modifier l'adresse IP du réacteur dans le code de votre ESP32 par celle de votre ordinateur.

Si votre ESP32 est bien configuré, vous devriez voir le statut du coeur du réacteur changer à chaque pression du bouton sur votre ESP32.

Si ce n'est pas le cas :

- Validez que vous êtes bien connecté à votre réseau WiFi local
- Validez que vous êtes capable d'effectuer une requête ICMP de votre ordinateur vers l'ESP32 (Ping)
- Validez que l'application web est bien démarrée et que vous pouvez y accéder
- Validez que vos requête respectent bien l'API REST définie plus haut avec les bonnes routes avec les bons verbes
