/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

std::map<std::string, double> robotConfig = {
    {"RampTime", 0.325},
    {"PIDDeadband", 0.114}, // TODO: PID needs to be tuned.
    {"clawMotorSpeed", 0.75},
    {"liftMotorSpeedFactor", 0.5},
    {"beltMotorSpeedFactor", 0.5},
    {"record", 0},
};

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

   SetConfig();
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

void RobotContainer::OpenDriveBaseFile() {
   m_driveBase.openFile();
}

void RobotContainer::CloseDriveBaseFile() {
   m_driveBase.closeFile();
}

void RobotContainer::ReadFile() {
   // Reset file to start.
   file.close();
   file.open("/home/lvuser/wcrj/autonomous.txt");

   // Read the file.
   std::string line;
   while (getline(file, line))
   {
      commands.push_back(line);
   }
}

void RobotContainer::SetConfig() {
   wpi::outs() << "Reading file!\n";

   // Reset file to start.
   configfile.close();
   configfile.open("/home/lvuser/wcrj/config.txt");

   std::string line;
   //std::map<std::string,double>::iterator itr;
   while (getline(configfile, line))
   {
      std::string name;
      double value;
      std::istringstream words (line);
      words >> name;
      words >> value;
      wpi::outs() << name << " " << value << "\n";

      // Write to variable
      robotConfig[name] = value;
   }
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Read the file

   std::string command = commands.at(command_no);
   command_no++;
   wpi::outs() << command << "\n";

   std::string verb;
   std::vector<double> args;
   std::istringstream words (command);
   words >> verb;
   double num;
   while (words >> num)
   {
      args.push_back(num);
   }

   if (args.size()==3)
   {
      return new ArcadeDrive(&m_driveBase, [this, args] {return args[0];}, [this, args] {return args[1];}, args[2]);
   }
   return new ArcadeDrive(&m_driveBase, [this, args] {return args[0];}, [this, args] {return args[1];}, 1);
}