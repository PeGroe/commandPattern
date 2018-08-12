#pragma once

#include "../ICommand.h"

class Hottub;

class HottubOnCommand : public ICommand
{
public:
  HottubOnCommand(Hottub* hottub);
  virtual ~HottubOnCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  Hottub* hottub;
};
