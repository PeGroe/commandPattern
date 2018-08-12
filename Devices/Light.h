#pragma once

#include <string>

class Light
{
public:
  Light(std::string location);
  virtual ~Light();

  void on() const;
  void off() const;

private:
  std::string location;
};