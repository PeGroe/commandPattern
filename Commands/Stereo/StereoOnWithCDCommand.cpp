#include "StereoOnWithCDCommand.h"
#include "../../Devices/Stereo.h"

StereoOnWithCDCommand::StereoOnWithCDCommand(Stereo * stereo)
{
  this->stereo = stereo;
}

StereoOnWithCDCommand::~StereoOnWithCDCommand()
{
}

void StereoOnWithCDCommand::execute()
{
  stereo->on();
  stereo->setCD();
  stereo->setVolume(11);
}

void StereoOnWithCDCommand::undo()
{
  stereo->off();
}

std::string StereoOnWithCDCommand::getClassName() const
{
  return "StereoOnWithCDCommand";
}
