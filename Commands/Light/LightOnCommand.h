#pragma once

#include "../ICommand.h"

class Light;

class LightOnCommand : public ICommand
{
public:
  LightOnCommand(Light* light);
  virtual ~LightOnCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  Light * light;
};
