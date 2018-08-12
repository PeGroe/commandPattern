#include "GarageDoorUpCommand.h"
#include "../../Devices/GarageDoor.h"

GarageDoorUpCommand::GarageDoorUpCommand(GarageDoor * garageDoor)
{
  this->garageDoor = garageDoor;
}

GarageDoorUpCommand::~GarageDoorUpCommand()
{
}

void GarageDoorUpCommand::execute()
{
  garageDoor->up();
}

void GarageDoorUpCommand::undo()
{
  // Not supported
}

std::string GarageDoorUpCommand::getClassName() const
{
  return "GarageDoorUpCommand";
}
