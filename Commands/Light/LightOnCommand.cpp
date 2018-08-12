#include "LightOnCommand.h"
#include "../../Devices/Light.h"

LightOnCommand::LightOnCommand(Light * light)
{
  this->light = light;
}

LightOnCommand::~LightOnCommand()
{
}

void LightOnCommand::execute()
{
  light->on();
}

void LightOnCommand::undo()
{
  light->off();
}

std::string LightOnCommand::getClassName() const
{
  return "LightOnCommand";
}
