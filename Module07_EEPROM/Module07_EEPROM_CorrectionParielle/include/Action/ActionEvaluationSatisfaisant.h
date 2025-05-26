#pragma once

#include <Utilify/Action/ActionBase.h>

#include <Utilify/EEPROM/EEPROMDataStorage.h>

#include "StatistiquesSatisfaction.h"

class ActionEvaluationSatisfaisant : public ActionBase<void>
{
public:
    ActionEvaluationSatisfaisant(EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage);

    void execute() override;

private:
    EEPROMDataStorage<StatistiquesSatisfaction>* m_eepromStorage;
};