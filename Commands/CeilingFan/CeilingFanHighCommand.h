#pragma once

#include "../ICommand.h"
#include "../../RemoteControl/defines.h"

class CeilingFan;

class CeilingFanHighCommand : public ICommand
{
public:
  CeilingFanHighCommand(CeilingFan* ceilingFan);
  virtual ~CeilingFanHighCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  CeilingFan * ceilingFan;
  ceilingLevel prevLevel;
};
