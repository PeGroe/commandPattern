#pragma once

#include "../ICommand.h"
#include "../../RemoteControl/defines.h"

class CeilingFan;

class CeilingFanLowCommand : public ICommand
{
public:
  CeilingFanLowCommand(CeilingFan* ceilingFan);
  virtual ~CeilingFanLowCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  CeilingFan* ceilingFan;
  ceilingLevel prevLevel;
};
