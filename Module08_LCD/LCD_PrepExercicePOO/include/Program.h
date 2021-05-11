#pragma once

class LCD1602;
class Program {
 public:
  Program();
  void loop();

 private:
  LCD1602* m_LCD;
};