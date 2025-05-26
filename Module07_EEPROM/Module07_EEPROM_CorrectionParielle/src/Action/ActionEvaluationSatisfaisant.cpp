#include "Action/ActionEvaluationSatisfaisant.h"

ActionEvaluationSatisfaisant::ActionEvaluationSatisfaisant(
    EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage)
    : m_eepromStorage(eepromStorage) {}

void ActionEvaluationSatisfaisant::execute() {
  StatistiquesSatisfaction stats = m_eepromStorage->load()
                                       ? m_eepromStorage->data()
                                       : StatistiquesSatisfaction{0, 0, 0};
  stats.m_nbSatisfaits++;
  m_eepromStorage->setData(stats);
  m_eepromStorage->save();
}
