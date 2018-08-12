#pragma once

#include "../ICommand.h"

class GarageDoor;

class GarageDoorUpCommand : public ICommand
{
public:
  GarageDoorUpCommand(GarageDoor* garageDoor);
  virtual ~GarageDoorUpCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  GarageDoor* garageDoor;
};
