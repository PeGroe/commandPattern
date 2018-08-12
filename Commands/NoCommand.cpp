#include "NoCommand.h"

NoCommand::NoCommand()
{
}

NoCommand::~NoCommand()
{
}

void NoCommand::execute()
{
}

void NoCommand::undo()
{
}

std::string NoCommand::getClassName() const
{
  return "NoCommand";
}
