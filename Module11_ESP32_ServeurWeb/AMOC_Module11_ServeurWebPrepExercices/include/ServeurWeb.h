#pragma once
#include <Arduino.h>
#include <FS.h>
#include <vector>

class WebServer;
class Actionneur;

class ServeurWeb {
 public:
  ServeurWeb(std::vector<Actionneur*> const& p_actionneurs);
  void tick();

 private:
  std::vector<Actionneur*> const& m_actionneurs;
  WebServer* m_webServer;
  
  void afficherRacine();

  void ajouterFichiersStatiques(String const& p_debutNomFichier);
  void ajouterFichiersStatiques(String const& p_debutNomFichier,
                                File& p_fichier);
                                
  void ressourceNonTrouvee(String const& p_nomFichier);

  void actionner(int const& p_id);
  void statuts(void) const;
};
