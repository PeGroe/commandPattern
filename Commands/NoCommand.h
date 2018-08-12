#pragma once

#include "ICommand.h"

class NoCommand : public ICommand
{
public:
  NoCommand();
  virtual ~NoCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;
};
