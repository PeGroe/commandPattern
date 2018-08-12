#pragma once

#include "../ICommand.h"

class Stereo;

class StereoOnCommand : public ICommand
{
public:
  StereoOnCommand(Stereo* stereo);
  virtual ~StereoOnCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  Stereo* stereo;
};
