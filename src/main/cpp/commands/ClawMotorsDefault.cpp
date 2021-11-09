/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClawMotorsDefault.h"

ClawMotorsDefault::ClawMotorsDefault(ClawMotors* clawMotors) : m_clawMotors{clawMotors} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({clawMotors});
}

// Called when the command is initially scheduled.
void ClawMotorsDefault::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ClawMotorsDefault::Execute() {
    m_clawMotors->Stop();
}

// Called once the command ends or is interrupted.
void ClawMotorsDefault::End(bool interrupted) {}

// Returns true when the command should end.
bool ClawMotorsDefault::IsFinished() { return false; }
