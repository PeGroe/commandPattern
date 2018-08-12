#include "CeilingFanOffCommand.h"
#include "../../Devices/CeilingFan.h"

CeilingFanOffCommand::CeilingFanOffCommand(CeilingFan* ceilingFan)
{
  this->ceilingFan = ceilingFan;
}

CeilingFanOffCommand::~CeilingFanOffCommand()
{
}

void CeilingFanOffCommand::execute()
{
  prevLevel = ceilingFan->getSpeed();
  ceilingFan->off();
}

void CeilingFanOffCommand::undo()
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

std::string CeilingFanOffCommand::getClassName() const
{
  return "CeilingFanOffCommand";
}
