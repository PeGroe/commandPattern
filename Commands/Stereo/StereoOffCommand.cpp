#include "StereoOffCommand.h"
#include "../../Devices/Stereo.h"

StereoOffCommand::StereoOffCommand(Stereo* stereo)
{
  this->stereo = stereo;
}

StereoOffCommand::~StereoOffCommand()
{
}

void StereoOffCommand::execute()
{
  stereo->off();
}

void StereoOffCommand::undo()
{
  stereo->on();
}

std::string StereoOffCommand::getClassName() const
{
  return "StereoOffCommand";
}
