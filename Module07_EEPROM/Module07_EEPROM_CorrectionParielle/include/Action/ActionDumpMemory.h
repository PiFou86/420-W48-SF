#pragma once

#include <Arduino.h>
#include <Utilify/Action/ActionBase.h>

#include <Utilify/EEPROM/EEPROMDataStorage.h>

#include "StatistiquesSatisfaction.h"

class ActionDumpMemory : public ActionBase<void>
{
public:
    ActionDumpMemory(EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage);
    
    void execute() override;
private:
    EEPROMDataStorage<StatistiquesSatisfaction>* m_eepromStorage;
};
