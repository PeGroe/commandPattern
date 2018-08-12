#pragma once

#include "../ICommand.h"

class Stereo;

class StereoOnWithCDCommand : public ICommand
{
public:
  StereoOnWithCDCommand(Stereo* stereo);
  virtual ~StereoOnWithCDCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  Stereo* stereo;
};
