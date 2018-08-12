#include "StereoOnCommand.h"
#include "../../Devices/Stereo.h"

StereoOnCommand::StereoOnCommand(Stereo* stereo)
{
  this->stereo = stereo;
}

StereoOnCommand::~StereoOnCommand()
{
}

void StereoOnCommand::execute()
{
  stereo->on();
}

void StereoOnCommand::undo()
{
  stereo->off();
}

std::string StereoOnCommand::getClassName() const
{
  return "StereoOnCommand";
}
