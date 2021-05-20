#pragma once
#include <Arduino.h>

#include "Actionneur.h"

class DEL : public Actionneur {
 public:
  DEL(int const& p_id, String const& p_description, int p_pin, bool p_estAllumee = false);

  virtual void allumer();
  virtual void eteindre();
  virtual bool estAllume() const;

 private:
  int m_pin;
  bool m_estAllumee;
};
