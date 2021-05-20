#pragma once

#include <vector>

class Actionneur;

class ServeurWeb;
class Program {
 public:
  Program();
  void connexionReseau();
  void loop();

 private:
  ServeurWeb* m_serveurWeb;
  std::vector<Actionneur*> m_actionneurs;
};
