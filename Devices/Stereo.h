#pragma once

#include <string>

class Stereo
{
public:
  Stereo(std::string location);
  virtual ~Stereo();

  void on() const;
  void off() const;
  void setCD() const;
  void setDVD() const;
  void setRadio() const;
  void setVolume(int volume) const;

private:
  std::string location;
};
