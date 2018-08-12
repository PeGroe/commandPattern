#pragma once

#include "../ICommand.h"

class Stereo;

class StereoOffCommand : public ICommand
{
public:
  StereoOffCommand(Stereo* stereo);
  virtual ~StereoOffCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  Stereo* stereo;
};
