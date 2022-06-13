# Problèmes communs

## Compilation

### Résolution de dépendances

Il est possible que Pio ne trouve pas toutes dépendances des bibliothèques. Pour forcer une recherche approndondie, vous pouvez utiliser le paramètre ```lib_ldf_mode``` avec la valeur ```deep+``` décrit dans la documentation : [lib-ldf-mode](https://docs.platformio.org/en/stable/projectconf/section_env_library.html#lib-ldf-mode).

## Réseau

### Bridge WiFi

Certains couples "Point d'accès" et "Carte réseau WiFi" fonctionnent mal ensemble et ne permettent pas de créer un bridge fonctionnel dans votre outil de virtualisation favori. Si vous rencontrez des problèmes avec un bridge WiFi, il est conseillé d'utiliser un bridge sur une interface physique. (Référence : https://forums.virtualbox.org/viewtopic.php?t=98133).

Si votre ordinateur ne possède PAS de carte réseau filée Ethernet, consultez votre formateur.

## Système de fichiers

SPIFFS a modifié sa façon de transiger avec les répertoires À VALIDER. Une solution est de retourner sur l'ancienne version du module ESP32 (attention que d'autres versions plus récentes ne soient pas installées)

## Home assistant

Depuis la version 2022.06, la déclaration des capteurs (sensors) de type mqtt a été modifiée ([2022.06 - Breaking Changes](https://www.home-assistant.io/blog/2022/06/01/release-20226/#breaking-changes)). Elle passe de :

```yaml
sensor:
  - platform: "mqtt"
    name: "My sensor"
    state_topic: "some-state-topic"
```

à

```yaml
mqtt:
  sensor:
    - name: "My sensor"
      state_topic: "some-state-topic"
```

## Consommation d'énergie

L'autonomie éhergétique est importante pour les clients. Elle répond aux questions suivantes:
#### durée de charge de la pile
Pour y arriver, il faut déterminer la consommation moyenne de votre Station Météo, (puisance (courant, tension)) par unité de temps versus la puissance disponible de la pile à pleine capacité). ceci détermine le temps d'autonomie entre 2 chargements
#### méthodes de recharge
à chercher
#### autres sources de courant
pannaux solaires, éoliennes, etc

Depuis la version 2022.06, la déclaration des capteurs (sensors) de type mqtt a été modifiée ([2022.06 - Breaking Changes](https://www.home-assistant.io/blog/2022/06/01/release-20226/#breaking-changes)). Elle passe de :
