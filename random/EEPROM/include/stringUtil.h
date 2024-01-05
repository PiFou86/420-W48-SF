#pragma once

#include <Arduino.h>

inline String padLeft(String p_texte, uint16_t p_tailleMin,
                      char p_remplissage) {
  while (p_texte.length() < p_tailleMin) {
    p_texte = p_remplissage + p_texte;
  }

  return p_texte;
}