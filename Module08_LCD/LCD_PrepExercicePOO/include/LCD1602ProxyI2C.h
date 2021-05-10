#pragma once
#include "LCD1602Proxy.h"

class LiquidCrystal_I2C;
class LCD1602ProxyI2C : public LCD1602Proxy {
 public:
  LCD1602ProxyI2C();
  virtual void definirPositionCurseur(int p_colonne, int p_ligne) const;
  virtual void afficher(const String& p_texte) const;
  virtual void effacer() const;

 private:
  LiquidCrystal_I2C* m_lcd;
};
