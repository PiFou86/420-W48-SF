#include "Action/ActionDumpMemory.h"

ActionDumpMemory::ActionDumpMemory(
    EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage)
    : m_eepromStorage(eepromStorage) {}

void ActionDumpMemory::execute() {
  this->m_eepromStorage->dumpEepromContent();
}
