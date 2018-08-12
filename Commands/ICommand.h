#pragma once

#include <string>

class ICommand
{
public:
  virtual void execute() = 0;
  virtual void undo() = 0;
  virtual std::string getClassName() const = 0;
};