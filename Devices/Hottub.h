#pragma once

class Hottub
{
public:
  Hottub();
  virtual ~Hottub();

  void on();
  void off();
  void circulate() const;
  void jetsOn() const;
  void jetsOff() const;
  void setTemperature(int temperature);

private:
  int temperature;
  bool state;
};