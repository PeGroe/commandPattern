#include "TVOnCommand.h"
#include "../../Devices/TV.h"

TVOnCommand::TVOnCommand(TV* tv)
{
  this->tv = tv;
}

TVOnCommand::~TVOnCommand()
{
}

void TVOnCommand::execute()
{
  tv->on();
  tv->setInputChannel();
}

void TVOnCommand::undo()
{
  tv->off();
}

std::string TVOnCommand::getClassName() const
{
  return "TVOnCommand";
}
