#include "LightOffCommand.h"
#include "../../Devices/Light.h"

LightOffCommand::LightOffCommand(Light * light)
{
  this->light = light;
}

LightOffCommand::~LightOffCommand()
{
}

void LightOffCommand::execute()
{
  light->off();
}

void LightOffCommand::undo()
{
  light->on();
}

std::string LightOffCommand::getClassName() const
{
  return "LightOffCommand";
}
