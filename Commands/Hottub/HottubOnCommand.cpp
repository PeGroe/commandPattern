#include "HottubOnCommand.h"
#include "../../Devices/Hottub.h"

HottubOnCommand::HottubOnCommand(Hottub* hottub)
{
  this->hottub = hottub;
}

HottubOnCommand::~HottubOnCommand()
{
}

void HottubOnCommand::execute()
{
  hottub->on();
  hottub->setTemperature(104);
  hottub->circulate();
}

void HottubOnCommand::undo()
{
  hottub->off();
}

std::string HottubOnCommand::getClassName() const
{
  return "HottubOnCommand";
}
