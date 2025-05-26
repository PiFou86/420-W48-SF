#include "Action/ActionEvaluationPassable.h"

ActionEvaluationPassable::ActionEvaluationPassable(
    EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage)
    : m_eepromStorage(eepromStorage) {}

void ActionEvaluationPassable::execute() {
  StatistiquesSatisfaction stats = m_eepromStorage->load()
                                       ? m_eepromStorage->data()
                                       : StatistiquesSatisfaction{0, 0, 0};
  stats.m_nbPassables++;
  m_eepromStorage->setData(stats);
  m_eepromStorage->save();
}