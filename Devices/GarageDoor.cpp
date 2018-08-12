#include "GarageDoor.h"
#include <iostream>

GarageDoor::GarageDoor(std::string location)
{
  this->location = location;
}

GarageDoor::~GarageDoor()
{
}

void GarageDoor::up() const
{
  std::cout << "Garage Door is Open." << std::endl;
}

void GarageDoor::down() const
{
  std::cout << "Garage Door is Closed." << std::endl;
}

void GarageDoor::stop() const
{
  std::cout << "Garage Door is Stopped." << std::endl;
}

void GarageDoor::lightOn() const
{
  std::cout << "Garage light is on." << std::endl;
}

void GarageDoor::lightOff() const
{
  std::cout << "Garage light is off." << std::endl;
}
