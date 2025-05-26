#pragma once

#include <Utilify/BasicVector.h>
#include <Utilify/Task/TaskAggregate.h>
#include <Utilify/EEPROM/EEPROMDataStorage.h>

#include "StatistiquesSatisfaction.h"

class Program {

public:
    Program();

    void loop();

private:
    TaskAggregate m_taskAggregate;
    EEPROMDataStorage<StatistiquesSatisfaction> m_eepromStorage;
};
