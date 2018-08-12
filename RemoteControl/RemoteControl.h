#pragma once

#include <vector>

class ICommand;

class RemoteControl
{
public:
  RemoteControl();
  virtual ~RemoteControl();

  void setCommand(int slot, ICommand* onCommand, ICommand* offCommand);
  void onButtonWasPushed(int slot);
  void offButtonWasPushed(int slot);
  void undoButtonWasPushed();
  void printRemoteControlConfiguration() const;

private:
  std::vector<ICommand*> onCommands;
  std::vector<ICommand*> offCommands;
  ICommand* undoCommand;
};