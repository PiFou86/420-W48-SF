#pragma once

#include <Utilify/Action/ActionBase.h>

#include <Utilify/EEPROM/EEPROMDataStorage.h>

#include "StatistiquesSatisfaction.h"

class ActionEvaluationPassable : public ActionBase<void>
{
public:
    ActionEvaluationPassable(EEPROMDataStorage<StatistiquesSatisfaction>* eepromStorage);

    void execute() override;

private:
    EEPROMDataStorage<StatistiquesSatisfaction>* m_eepromStorage;
};