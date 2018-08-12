#pragma once

#include "../ICommand.h"
#include "../../RemoteControl/defines.h"

class CeilingFan;

class CeilingFanOffCommand : public ICommand
{
public:
  CeilingFanOffCommand(CeilingFan* ceilingFan);
  virtual ~CeilingFanOffCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  CeilingFan* ceilingFan;
  ceilingLevel prevLevel;
};
