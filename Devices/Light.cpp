#include "Light.h"
#include <iostream>

Light::Light(std::string location)
{
  this->location = location;
}

Light::~Light()
{
}

void Light::on() const
{
  std::cout << location << " light is on." << std::endl;
}

void Light::off() const
{
  std::cout << location << " light is off." << std::endl;
}
