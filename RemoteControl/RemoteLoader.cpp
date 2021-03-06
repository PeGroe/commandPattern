// RemoteControl.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include "RemoteControl.h"

#include "../Devices/Light.h"
#include "../Devices/GarageDoor.h"
#include "../Devices/CeilingFan.h"
#include "../Devices/Stereo.h"
#include "../Devices/TV.h"
#include "../Devices/Hottub.h"

#include "../Commands/Light/LightOnCommand.h"
#include "../Commands/Light/LightOffCommand.h"
#include "../Commands/CeilingFan/CeilingFanLowCommand.h"
#include "../Commands/CeilingFan/CeilingFanMediumCommand.h"
#include "../Commands/CeilingFan/CeilingFanHighCommand.h"
#include "../Commands/CeilingFan/CeilingFanOffCommand.h"
#include "../Commands/GarageDoor/GarageDoorUpCommand.h"
#include "../Commands/GarageDoor/GarageDoorDownCommand.h"
#include "../Commands/Stereo/StereoOnCommand.h"
#include "../Commands/Stereo/StereoOnWithCDCommand.h"
#include "../Commands/Stereo/StereoOffCommand.h"
#include "../Commands/TV/TVOnCommand.h"
#include "../Commands/TV/TVOffCommand.h"
#include "../Commands/Hottub/HottubOnCommand.h"
#include "../Commands/Hottub/HottubOffCommand.h"
#include "../Commands/MacroCommand/MacroCommand.h"


int main()
{
  ////////////////////////////////////////////////////
  // This is the client part of the command pattern //
  ////////////////////////////////////////////////////

  // Devices (Receiver)
  Light* livingRoomLight = new Light("Living Room");
  Light* kitchenLight    = new Light("Kitchen");
  CeilingFan* ceilingFan = new CeilingFan("Living Room");
  GarageDoor* garageDoor = new GarageDoor("");
  Stereo* stereo         = new Stereo("Living Room");
  TV* tv                 = new TV("Living Room");
  Hottub* hottub         = new Hottub();

  // Concrete Commands
  LightOnCommand* livingRoomLightOn           = new LightOnCommand(livingRoomLight);
  LightOffCommand* livingRoomLightOff         = new LightOffCommand(livingRoomLight);
  LightOnCommand* kitchenLightOn              = new LightOnCommand(kitchenLight);
  LightOffCommand* kitchenLightOff            = new LightOffCommand(kitchenLight);
  CeilingFanLowCommand* ceilingFanOnLow       = new CeilingFanLowCommand(ceilingFan);
  CeilingFanMediumCommand* ceilingFanOnMedium = new CeilingFanMediumCommand(ceilingFan);
  CeilingFanHighCommand* ceilingFanOnHigh     = new CeilingFanHighCommand(ceilingFan);
  CeilingFanOffCommand* ceilingFanOff         = new CeilingFanOffCommand(ceilingFan);
  GarageDoorUpCommand* garageDoorUp           = new GarageDoorUpCommand(garageDoor);
  GarageDoorDownCommand* garageDoorDown       = new GarageDoorDownCommand(garageDoor);
  StereoOnCommand* stereoOn                   = new StereoOnCommand(stereo);
  StereoOnWithCDCommand* stereoOnWithCD       = new StereoOnWithCDCommand(stereo);
  StereoOffCommand* stereoOff                 = new StereoOffCommand(stereo);
  TVOnCommand* tvOn                           = new TVOnCommand(tv);
  TVOffCommand* tvOff                         = new TVOffCommand(tv);
  HottubOnCommand* hottubOn                   = new HottubOnCommand(hottub);
  HottubOffCommand* hottubOff                 = new HottubOffCommand(hottub);

  // Create vectors for the party extension
  std::vector<ICommand*> partyOn;
  partyOn.push_back(livingRoomLightOn);
  partyOn.push_back(stereoOn);
  partyOn.push_back(tvOn);
  partyOn.push_back(hottubOn);
  MacroCommand* partyOnMacro = new MacroCommand(partyOn);

  std::vector<ICommand*> partyOff;
  partyOff.push_back(livingRoomLightOff);
  partyOff.push_back(stereoOff);
  partyOff.push_back(tvOff);
  partyOff.push_back(hottubOff);
  MacroCommand* partyOffMacro = new MacroCommand(partyOff);

  ////////////////////////////////////////////////////
  // This is the invoker part of the command pattern //
  ////////////////////////////////////////////////////

  // Remote Control (Invoker)
  RemoteControl* remoteControl = new RemoteControl();
  remoteControl->setCommand(0, livingRoomLightOn, livingRoomLightOff);
  remoteControl->setCommand(1, kitchenLightOn, kitchenLightOff);
  remoteControl->setCommand(2, stereoOnWithCD, stereoOff);
  remoteControl->setCommand(3, ceilingFanOnLow, ceilingFanOff);
  remoteControl->setCommand(4, ceilingFanOnMedium, ceilingFanOff);
  remoteControl->setCommand(5, ceilingFanOnHigh, ceilingFanOff);
  remoteControl->setCommand(6, partyOnMacro, partyOffMacro);

  remoteControl->printRemoteControlConfiguration();

  // Simple Command Pattern Test
  remoteControl->onButtonWasPushed(0);
  remoteControl->offButtonWasPushed(0);
  remoteControl->onButtonWasPushed(1);
  remoteControl->offButtonWasPushed(1);
  remoteControl->onButtonWasPushed(2);
  remoteControl->offButtonWasPushed(2);

  // Undo Button Test
  remoteControl->onButtonWasPushed(0);
  remoteControl->offButtonWasPushed(0);
  remoteControl->printRemoteControlConfiguration();
  remoteControl->undoButtonWasPushed();
  remoteControl->offButtonWasPushed(0);
  remoteControl->onButtonWasPushed(0);
  remoteControl->printRemoteControlConfiguration();
  remoteControl->undoButtonWasPushed();

  // CeilingFan Test
  remoteControl->onButtonWasPushed(4);
  remoteControl->offButtonWasPushed(4);
  remoteControl->printRemoteControlConfiguration();
  remoteControl->undoButtonWasPushed();
  remoteControl->onButtonWasPushed(5);
  remoteControl->printRemoteControlConfiguration();
  remoteControl->undoButtonWasPushed();

  // Party Test (Execute group of commands)
  remoteControl->printRemoteControlConfiguration();
  std::cout << "--- Pushing Macro On ---" << std::endl;
  remoteControl->onButtonWasPushed(6);
  std::cout << std::endl << "--- Pushing Macro Off ---" << std::endl;
  remoteControl->offButtonWasPushed(6);

  return 0;
}

