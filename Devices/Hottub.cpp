#include "Hottub.h"
#include <iostream>

Hottub::Hottub()
{
}

Hottub::~Hottub()
{
}

void Hottub::on()
{
  state = true;
}

void Hottub::off()
{
  state = false;
}

void Hottub::circulate() const
{
  if (state)
  {
    std::cout << "Hottub is bubbling." << std::endl;
  }
}

void Hottub::jetsOn() const
{
  if (state)
  {
    std::cout << "Hottub jets are on." << std::endl;
  }
}

void Hottub::jetsOff() const
{
  if (state)
  {
    std::cout << "Hottub jets are off." << std::endl;
  }
}

void Hottub::setTemperature(int temperature)
{
  if (temperature > this->temperature)
  {
    std::cout << "Hottub is heating to a steaming " << temperature << " degrees." << std::endl;
  }
  else
  {
    std::cout << "Hottub is cooling to " << temperature << " degrees." << std::endl;
  }

  this->temperature = temperature;
}
