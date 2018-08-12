#include "TV.h"
#include <iostream>

TV::TV(std::string location)
{
  this->location = location;
}

TV::~TV()
{
}

void TV::on() const
{
  std::cout << location << " TV is on." << std::endl;
}

void TV::off() const
{
  std::cout << location << " TV is off." << std::endl;
}

void TV::setInputChannel()
{
  this->channel = 3;
  std::cout << location << " TV channel is set for DVD." << std::endl;
}
