#include "CeilingFanMediumCommand.h"
#include "../../Devices/CeilingFan.h"

CeilingFanMediumCommand::CeilingFanMediumCommand(CeilingFan* ceilingFan)
{
  this->ceilingFan = ceilingFan;
}

CeilingFanMediumCommand::~CeilingFanMediumCommand()
{
}

void CeilingFanMediumCommand::execute()
{
  prevLevel = ceilingFan->getSpeed();
  ceilingFan->medium();
}

void CeilingFanMediumCommand::undo()
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

std::string CeilingFanMediumCommand::getClassName() const
{
  return "CeilingFanMediumCommand";
}
