#include "Action/ActionAfficherStatistiques.h"

ActionAfficherStatistiques::ActionAfficherStatistiques(
    EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage)
    : m_eepromStorage(eepromStorage) {}

void ActionAfficherStatistiques::execute() {
  StatistiquesSatisfaction stats = m_eepromStorage->load()
                                       ? m_eepromStorage->data()
                                       : StatistiquesSatisfaction{0, 0, 0};
  Serial.print("Satisfaits: ");
  Serial.println(stats.m_nbSatisfaits);
  Serial.print("Passables: ");
  Serial.println(stats.m_nbPassables);
  Serial.print("Insatisfaits: ");
  Serial.println(stats.m_nbInsatisfaits);
}
