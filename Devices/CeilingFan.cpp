#include "CeilingFan.h"
#include <iostream>

CeilingFan::CeilingFan(std::string location)
{
  this->location = location;
  level = OFF;
}

CeilingFan::~CeilingFan()
{
}

void CeilingFan::high()
{
  level = HIGH;
  std::cout << location << " ceiling fan is on high." << std::endl;
}

void CeilingFan::medium()
{
  level = MEDIUM;
  std::cout << location << " ceiling fan is on medium." << std::endl;
}

void CeilingFan::low()
{
  level = LOW;
  std::cout << location << " ceiling fan is on low." << std::endl;
}

void CeilingFan::off()
{
  level = OFF;
  std::cout << location << " ceiling fan is off." << std::endl;
}

ceilingLevel CeilingFan::getSpeed() const
{
  return level;
}
