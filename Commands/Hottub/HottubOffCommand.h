#pragma once

#include "../ICommand.h"

class Hottub;

class HottubOffCommand : public ICommand
{
public:
  HottubOffCommand(Hottub* hottub);
  virtual ~HottubOffCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  Hottub* hottub;
};
