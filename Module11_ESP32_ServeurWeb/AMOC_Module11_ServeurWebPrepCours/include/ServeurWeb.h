#pragma once
#include <Arduino.h>

class WebServer;
class ServeurWeb {
 public:
  ServeurWeb();
  void tick();
  void renvoyerRessource(const String& p_nomFichier);

 private:
  WebServer* m_webServer;
  void afficherRacine();
  void afficherFichiersStatiques();
  String obtenirContentType(const String& p_nomRessource);

  void allumer(void);
  void eteindre(void);
};
