#include "RemoteControl.h"
#include "../Commands/NoCommand.h"
#include <string>
#include <typeinfo>
#include <iostream>


RemoteControl::RemoteControl()
{
  for (int i = 0; i < 7; i++)
  {
    onCommands.push_back(new NoCommand());
    offCommands.push_back(new NoCommand());
  }

  undoCommand = new NoCommand();
}

RemoteControl::~RemoteControl()
{
}

void RemoteControl::setCommand(int slot, ICommand* onCommand, ICommand* offCommand)
{
  this->onCommands[slot]  = onCommand;
  this->offCommands[slot] = offCommand;
}

void RemoteControl::onButtonWasPushed(int slot)
{
  this->onCommands[slot]->execute();
  undoCommand = this->onCommands[slot];
}

void RemoteControl::offButtonWasPushed(int slot)
{
  this->offCommands[slot]->execute();
  undoCommand = this->offCommands[slot];
}

void RemoteControl::undoButtonWasPushed()
{
  undoCommand->undo();
}

void RemoteControl::printRemoteControlConfiguration() const
{
  std::cout << std::endl;
  std::cout << "------------------- Remote Control -------------------" << std::endl;

  for (uint16_t i = 0; i < onCommands.size(); i++)
  {
    std::string stringBuffer = "[slot " + std::to_string(i) + "] " + onCommands[i]->getClassName();
    stringBuffer.resize(35, ' ');
    stringBuffer += offCommands[i]->getClassName();

    std::cout << stringBuffer << std::endl;
  }

  std::cout << "[undo]   " << undoCommand->getClassName() << std::endl;
  std::cout << std::endl;
}
