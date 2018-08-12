#include "CeilingFanHighCommand.h"
#include "../../Devices/CeilingFan.h"

CeilingFanHighCommand::CeilingFanHighCommand(CeilingFan* ceilingFan)
{
  this->ceilingFan = ceilingFan;
}

CeilingFanHighCommand::~CeilingFanHighCommand()
{
}

void CeilingFanHighCommand::execute()
{
  prevLevel = ceilingFan->getSpeed();
  ceilingFan->high();
}

void CeilingFanHighCommand::undo()
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

std::string CeilingFanHighCommand::getClassName() const
{
  return "CeilingFanHighCommand";
}
