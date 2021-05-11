#include "Program.h"

#include "LCD1602.h"
#include "LCD1602ProxyI2C.h"

Program::Program() {
  this->m_LCD = new LCD1602(new LCD1602ProxyI2C());

  this->m_LCD->effacer();
  this->m_LCD->definirPositionCurseur(0, 0);
  this->m_LCD->afficher("Bonjour a tous !");
  this->m_LCD->definirPositionCurseur(0, 1);
  this->m_LCD->afficher("Bienvenue !");
}

void Program::loop() {
    ;
}