#include "CeilingFanLowCommand.h"
#include "../../Devices/CeilingFan.h"

CeilingFanLowCommand::CeilingFanLowCommand(CeilingFan* ceilingFan)
{
  this->ceilingFan = ceilingFan;
}

CeilingFanLowCommand::~CeilingFanLowCommand()
{
}

void CeilingFanLowCommand::execute()
{
  prevLevel = ceilingFan->getSpeed();
  ceilingFan->low();
}

void CeilingFanLowCommand::undo()
{
  if (prevLevel == HIGH) {
    ceilingFan->high();
  }
  else if (prevLevel == MEDIUM) {
    ceilingFan->medium();
  }
  else if (prevLevel == LOW) {
    ceilingFan->low();
  }
  else if (prevLevel == OFF) {
    ceilingFan->off();
  }
}

std::string CeilingFanLowCommand::getClassName() const
{
  return "CeilingFanLowCommand";
}
