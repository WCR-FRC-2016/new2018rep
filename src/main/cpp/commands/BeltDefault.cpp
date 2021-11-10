/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/BeltDefault.h"

BeltDefault::BeltDefault(Belt* belt) : m_belt{belt} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({belt});
}

// Called when the command is initially scheduled.
void BeltDefault::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void BeltDefault::Execute() {
    m_belt->Move(0.0);
}

// Called once the command ends or is interrupted.
void BeltDefault::End(bool interrupted) {}

// Returns true when the command should end.
bool BeltDefault::IsFinished() { return false; }
