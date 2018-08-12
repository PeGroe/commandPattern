#include "TVOffCommand.h"
#include "../../Devices/TV.h"

TVOffCommand::TVOffCommand(TV* tv)
{
  this->tv = tv;
}

TVOffCommand::~TVOffCommand()
{
}

void TVOffCommand::execute()
{
  tv->off();
}

void TVOffCommand::undo()
{
  tv->on();
}

std::string TVOffCommand::getClassName() const
{
  return "TVOffCommand";
}
