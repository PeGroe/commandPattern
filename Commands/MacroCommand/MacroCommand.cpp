#include "MacroCommand.h"

MacroCommand::MacroCommand(std::vector<ICommand*> commands)
{
  this->commands = commands;
}

MacroCommand::~MacroCommand()
{
}

void MacroCommand::execute()
{
  for (uint16_t i = 0; i < commands.size(); i++)
  {
    commands[i]->execute();
  }
}

void MacroCommand::undo()
{
  // Backwards loop
  for (uint16_t i = static_cast<uint16_t>(commands.size()) - 1; i > 0; i--)
  {
    commands[i]->undo();
  }
}

std::string MacroCommand::getClassName() const
{
  return "MacroCommand";
}
