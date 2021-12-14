/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//
// 2020Mar17 Walko - Added some comment and reordered some statements for better clarity
//
#pragma once

#include <string>
#include <vector>
#include <fstream>

#include "frc/XboxController.h"
#include "subsystems/DriveBase.h"
#include "subsystems/ClawPneumatics.h"
#include "subsystems/ClawMotors.h"
#include "subsystems/Lift.h"
#include "subsystems/Belt.h"
#include "commands/ArcadeDrive.h"
#include "commands/ClawMotorsDefault.h"
#include "commands/LiftDefault.h"
#include "commands/BeltDefault.h"
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/Button.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  void ReadFile();
  
  int command_no;
 
 private:
  frc::XboxController m_driverStick{0};
  frc::XboxController m_manStick{1};

  // Wheels In - Manipulator A Button
  frc2::Button m_manA{[&] {return m_manStick.GetAButton();} };
  frc2::InstantCommand m_wheelsIn{[this] {m_clawMotors.WheelsIn();}, {&m_clawMotors} };

  // Wheels Out - Manipulator B Button
  frc2::Button m_manB{[&] {return m_manStick.GetBButton();} };
  frc2::InstantCommand m_wheelsOut{[this] {m_clawMotors.WheelsOut();}, {&m_clawMotors} };
  
  // Open Claw - Manipulator X Button
  frc2::Button m_manX{[&] {return m_manStick.GetXButton();}};
  frc2::InstantCommand m_openClaw{[this] {return m_clawPneumatics.OpenClaw();} , {&m_clawPneumatics} };
  
  // Close Claw - Manipulator Y Button
  frc2::Button m_manY{[&] {return m_manStick.GetYButton();}};
  frc2::InstantCommand m_closeClaw{[this] {return m_clawPneumatics.CloseClaw();} , {&m_clawPneumatics} };
  
  // Push Seatbelt - Manipulator L Trigger
  frc2::Button m_manLT{[&] {return (0.2 < m_manStick.GetTriggerAxis(frc::GenericHID::kLeftHand));} };
  frc2::InstantCommand m_pushBelt{[this] {return m_belt.Move(m_manStick.GetTriggerAxis(frc::GenericHID::kLeftHand));} , {&m_belt} };
  
  // Pull Seatbelt - Manipulator R Trigger
  frc2::Button m_manRT{[&] {return (0.2 < m_manStick.GetTriggerAxis(frc::GenericHID::kRightHand));} };
  frc2::InstantCommand m_pullBelt{[this] {return m_belt.Move(-m_manStick.GetTriggerAxis(frc::GenericHID::kRightHand));} , {&m_belt} };
  
  DriveBase m_driveBase;
  ClawPneumatics m_clawPneumatics;
  ClawMotors m_clawMotors;
  Lift m_lift;
  Belt m_belt;

  void ConfigureButtonBindings();

  std::vector<std::string> commands;
  std::fstream file {"/home/lvuser/autonomous.txt"};
};