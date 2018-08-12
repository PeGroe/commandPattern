#pragma once

#include <string>

class GarageDoor
{
public:
  GarageDoor(std::string location);
  virtual ~GarageDoor();

  void up() const;
  void down() const;
  void stop() const;
  void lightOn() const;
  void lightOff() const;

private:
  std::string location;
};
