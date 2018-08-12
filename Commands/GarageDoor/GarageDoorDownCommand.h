#pragma once

#include "../ICommand.h"

class GarageDoor;

class GarageDoorDownCommand : public ICommand
{
public:
  GarageDoorDownCommand(GarageDoor* garageDoor);
  virtual ~GarageDoorDownCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  GarageDoor* garageDoor;
};
