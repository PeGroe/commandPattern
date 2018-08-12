#pragma once

#include "../ICommand.h"

class TV;

class TVOnCommand : public ICommand
{
public:
  TVOnCommand(TV* tv);
  virtual ~TVOnCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  TV* tv;
};
