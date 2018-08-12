#pragma once

#include <string>
#include "../RemoteControl/defines.h"

class CeilingFan
{
public:
  CeilingFan(std::string location);
  virtual ~CeilingFan();

  void high();
  void medium();
  void low();
  void off();
  ceilingLevel getSpeed() const;

private:
  std::string location;
  ceilingLevel level;
};
