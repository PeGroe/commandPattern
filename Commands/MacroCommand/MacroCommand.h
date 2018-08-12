#pragma once

#include "../ICommand.h"
#include <vector>

class MacroCommand : public ICommand
{
public:
  MacroCommand(std::vector<ICommand*> commands);
  virtual ~MacroCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  std::vector<ICommand*> commands;
};
