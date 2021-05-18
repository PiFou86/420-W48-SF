#pragma once
#include <Arduino.h>
#include <FS.h>

class WebServer;

class ServeurWeb {
 public:
  ServeurWeb();
  void tick();

 private:
  WebServer* m_webServer;
  
  void afficherRacine();

  void ajouterFichiersStatiques(String const& p_debutNomFichier);
  void ajouterFichiersStatiques(String const& p_debutNomFichier,
                                File& p_fichier);
                                
  void ressourceNonTrouvee(String const& p_nomFichier);

  void allumer(void);
  void eteindre(void);
};
