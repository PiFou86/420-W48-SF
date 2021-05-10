#pragma once

class Affichage4Digits;
class Program {
 public:
  Program();
  void loop();

 private:
  Affichage4Digits* m_affichage4Digits;
  int m_compteur;
};