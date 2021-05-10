#include "LCD1602.h"

#include "LCD1602Proxy.h"

LCD1602::LCD1602(LCD1602Proxy* p_proxy) : m_proxy(p_proxy) { ; }

void LCD1602::definirPositionCurseur(int p_colonne, int p_ligne) const {
  this->m_proxy->definirPositionCurseur(p_colonne, p_ligne);
}

void LCD1602::afficher(const String& p_texte) const {
  this->m_proxy->afficher(p_texte);
}

void LCD1602::effacer() const { this->m_proxy->effacer(); }