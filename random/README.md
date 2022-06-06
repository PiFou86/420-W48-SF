# Problèmes communs

## Compilation

### Résolution de dépendances

Il est possible que Pio ne trouve pas toutes dépendances des bibliothèques. Pour forcer une recherche approndondie, vous pouvez utiliser le paramètre ```lib_ldf_mode``` avec la valeur ```deep+``` décrit dans la documentation : [lib-ldf-mode](https://docs.platformio.org/en/stable/projectconf/section_env_library.html#lib-ldf-mode).

## Réseau

### Bridge WiFi

Certains couples "Point d'accès" et "Carte réseau WiFi" fonctionnent mal ensemble et ne permettent pas de créer un bridge fonctionnel dans votre outil de virtualisation favori. Si vous rencontrez des problèmes avec un bridge WiFi, il est conseillé d'utiliser un bridge sur une interface physique. (Référence : https://forums.virtualbox.org/viewtopic.php?t=98133)

## Système de fichiers

SPIFFS a modifié sa façon de transiger avec les répertoires À VALIDER. Une solution est de retourner sur l'ancienne version du module ESP32 (attention que d'autres versions plus récentes ne soient pas installées)
