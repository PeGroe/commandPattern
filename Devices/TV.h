#pragma once

#include <string>

class TV
{
public:
  TV(std::string location);
  virtual ~TV();

  void on() const;
  void off() const;
  void setInputChannel();

private:
  std::string location;
  int channel;
};