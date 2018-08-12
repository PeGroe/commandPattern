#pragma once

#include "../ICommand.h"

class Light;

class LightOffCommand : public ICommand
{
public:
  LightOffCommand(Light* light);
  virtual ~LightOffCommand();

  void execute() override;
  void undo() override;
  std::string getClassName() const override;

private:
  Light* light;
};
