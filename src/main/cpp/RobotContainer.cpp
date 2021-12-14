/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
   m_driveBase.SetDefaultCommand(ArcadeDrive(&m_driveBase, 
    [this] { return m_driverStick.GetX(frc::GenericHID::kRightHand)/2;} ,
    [this] { return -m_driverStick.GetY(frc::GenericHID::kLeftHand)/1.5;}
   ));
   m_clawMotors.SetDefaultCommand(ClawMotorsDefault(&m_clawMotors));
   m_lift.SetDefaultCommand(LiftDefault(&m_lift, 
    [this] { return m_manStick.GetY(frc::GenericHID::kLeftHand);}
   ));
   m_belt.SetDefaultCommand(BeltDefault(&m_belt));
   
   ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
   // Configure your button bindings here
   
   m_manA.WhileHeld(m_wheelsIn);
   m_manB.WhileHeld(m_wheelsOut);
   m_manX.WhenPressed(m_openClaw);
   m_manY.WhenPressed(m_closeClaw);
   m_manLT.WhileHeld(m_pushBelt);
   m_manRT.WhileHeld(m_pullBelt);
}

void RobotContainer::ReadFile() {
   // Reset file to start.
   file.clear();
   file.seekg(0, std::ios::beg);

   // Read the file.
   std::string line;
   while (getline(file, line))
   {
      commands.push_back(line);
   }
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Read the file

   std::string command = commands.at(command_no);
   command_no++;
   wpi::outs() << command << " " << command[0] << "\n";

   std::string verb;
   std::vector<int> args;
   std::istringstream words (command);
   words >> verb;
   int num;
   while (words >> num)
   {
      args.push_back(num);
   }

   return new ArcadeDrive(&m_driveBase, [this, args] {return args[0];}, [this, args] {return args[1];}, args[2]);
}