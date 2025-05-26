#include "Action/ActionEvaluationInsatisfaisant.h"

ActionEvaluationInsatisfaisant::ActionEvaluationInsatisfaisant(
    EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage)
    : m_eepromStorage(eepromStorage) {}

void ActionEvaluationInsatisfaisant::execute()  {
  StatistiquesSatisfaction stats = m_eepromStorage->load()
                                       ? m_eepromStorage->data()
                                       : StatistiquesSatisfaction{0, 0, 0};
  stats.m_nbInsatisfaits++;
  m_eepromStorage->setData(stats);
  m_eepromStorage->save();
}
