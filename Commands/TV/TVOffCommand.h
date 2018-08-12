#pragma once

#include "../ICommand.h"

class TV;

class TVOffCommand : public ICommand
{
public:
  TVOffCommand(TV* tv);
  virtual ~TVOffCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  TV * tv;
};
