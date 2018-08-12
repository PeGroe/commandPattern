#pragma once

#include "../ICommand.h"
#include "../../RemoteControl/defines.h"

class CeilingFan;

class CeilingFanMediumCommand : public ICommand
{
public:
  CeilingFanMediumCommand(CeilingFan* ceilingFan);
  virtual ~CeilingFanMediumCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  CeilingFan * ceilingFan;
  ceilingLevel prevLevel;
};
