#include "HottubOffCommand.h"
#include "../../Devices/Hottub.h"

HottubOffCommand::HottubOffCommand(Hottub* hottub)
{
  this->hottub = hottub;
}

HottubOffCommand::~HottubOffCommand()
{
}

void HottubOffCommand::execute()
{
  hottub->setTemperature(98);
  hottub->off();
}

void HottubOffCommand::undo()
{
  hottub->on();
}

std::string HottubOffCommand::getClassName() const
{
  return "HottubOffCommand";
}
