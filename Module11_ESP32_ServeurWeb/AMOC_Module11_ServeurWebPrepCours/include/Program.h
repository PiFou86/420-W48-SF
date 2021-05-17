#pragma once

class ServeurWeb;
class Program {
 public:
  Program();
  void connexionReseau();
  void loop();
  

 private:
   ServeurWeb* m_serveurWeb;

};