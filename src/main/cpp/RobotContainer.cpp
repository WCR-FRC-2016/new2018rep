/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
   //wpi::outs() << "Debug Statement 1\n";
   m_driveBase.SetDefaultCommand(ArcadeDrive(&m_driveBase, 
    [this] { return m_driverStick.GetX(frc::GenericHID::kRightHand)/2;} ,
    [this] { return -m_driverStick.GetY(frc::GenericHID::kLeftHand)/1.5;}
   ));
   m_clawMotors.SetDefaultCommand(ClawMotorsDefault(&m_clawMotors));
   m_lift.SetDefaultCommand(LiftDefault(&m_lift, 
    [this] { return m_manStick.GetY(frc::GenericHID::kLeftHand);}
   ));
   //wpi::outs() << "Debug Statement 2\n";
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
   // Configure your button bindings here
   
   m_manA.WhileHeld(m_wheelsIn);
   m_manB.WhileHeld(m_wheelsOut);
   m_manX.WhenPressed(m_openClaw);
   m_manY.WhenPressed(m_closeClaw);
}