#include "GarageDoorDownCommand.h"
#include "../../Devices/GarageDoor.h"

GarageDoorDownCommand::GarageDoorDownCommand(GarageDoor* garageDoor)
{
  this->garageDoor = garageDoor;
}

GarageDoorDownCommand::~GarageDoorDownCommand()
{
}

void GarageDoorDownCommand::execute()
{
  garageDoor->down();
}

void GarageDoorDownCommand::undo()
{
  // Not supported
}

std::string GarageDoorDownCommand::getClassName() const
{
  return "GarageDoorDownCommand";
}
