#pragma once

#include <Utilify/Action/ActionBase.h>

#include <Utilify/EEPROM/EEPROMDataStorage.h>

#include "StatistiquesSatisfaction.h"

class ActionEvaluationInsatisfaisant : public ActionBase<void>
{
public:
    ActionEvaluationInsatisfaisant(EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage);

    void execute() override;

private:
    EEPROMDataStorage<StatistiquesSatisfaction>* m_eepromStorage;
};