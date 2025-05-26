#include "Program.h"

#include "Action/ActionAfficherStatistiques.h"
#include "Action/ActionDumpMemory.h"
#include "Action/ActionEvaluationInsatisfaisant.h"
#include "Action/ActionEvaluationPassable.h"
#include "Action/ActionEvaluationSatisfaisant.h"
#include "Utilify/DigitalInput/PushButton.h"

Program::Program() : m_taskAggregate(), m_eepromStorage(4242) {
  ActionDumpMemory* actionDumpMemory = new ActionDumpMemory(&m_eepromStorage);
  ActionAfficherStatistiques* actionAfficherStatistiques =
      new ActionAfficherStatistiques(&m_eepromStorage);

  PushButton* pushButtonSatisfait =
      new PushButton(2, new ActionEvaluationSatisfaisant(&m_eepromStorage));
  pushButtonSatisfait->callbackKeyUpLongPress(actionAfficherStatistiques);

  PushButton* pushButtonPassable =
      new PushButton(3, new ActionEvaluationPassable(&m_eepromStorage));
  pushButtonPassable->callbackKeyUpLongPress(actionAfficherStatistiques);
  
  PushButton* pushButtonInsatisfait =
      new PushButton(4, new ActionEvaluationInsatisfaisant(&m_eepromStorage));
  pushButtonInsatisfait->callbackKeyUpLongPress(actionDumpMemory);

  this->m_taskAggregate.addTask(pushButtonSatisfait);
  this->m_taskAggregate.addTask(pushButtonPassable);
  this->m_taskAggregate.addTask(pushButtonInsatisfait);
}

void Program::loop() { this->m_taskAggregate.tick(); }
