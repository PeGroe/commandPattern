#include "Stereo.h"
#include <iostream>

Stereo::Stereo(std::string location)
{
  this->location = location;
}

Stereo::~Stereo()
{
}

void Stereo::on() const
{
  std::cout << location << " stereo is on." << std::endl;
}

void Stereo::off() const
{
  std::cout << location << " stereo is off." << std::endl;
}

void Stereo::setCD() const
{
  std::cout << location << " stereo is set for CD input." << std::endl;
}

void Stereo::setDVD() const
{
  std::cout << location << " stereo is set for DVD input." << std::endl;
}

void Stereo::setRadio() const
{
  std::cout << location << " stereo is set for Radio." << std::endl;
}

void Stereo::setVolume(int volume) const
{
  std::cout << location << " stereo volume set to " << volume << "." << std::endl;
}
