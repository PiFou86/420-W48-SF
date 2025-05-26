#pragma once

#include <Arduino.h>
#include <Utilify/Action/ActionBase.h>

#include <Utilify/EEPROM/EEPROMDataStorage.h>

#include "StatistiquesSatisfaction.h"

class ActionAfficherStatistiques : public ActionBase<void>
{
public:
    ActionAfficherStatistiques(EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage);

    void execute() override;
private:
    EEPROMDataStorage<StatistiquesSatisfaction>* m_eepromStorage;
};
