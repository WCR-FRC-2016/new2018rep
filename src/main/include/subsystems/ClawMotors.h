/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class ClawMotors : public frc2::SubsystemBase {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  bool initialized = false;
  
  WPI_TalonSRX* LeftMotor;
  WPI_TalonSRX* RightMotor;

 public:
  ClawMotors();
  void ClawMotorsInit();
  void Periodic();
  void WheelsIn();
  void WheelsOut();
  void Stop();
};
