/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LiftDefault.h"

LiftDefault::LiftDefault(Lift* lift, std::function<double()> speed) : m_lift{lift}, m_speed{speed} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({lift});
}

// Called when the command is initially scheduled.
void LiftDefault::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void LiftDefault::Execute() {
    double passSpeed = (abs(m_speed()*1000) > 200?m_speed():0.0);
    m_lift->Move(passSpeed);
}

// Called once the command ends or is interrupted.
void LiftDefault::End(bool interrupted) {}

// Returns true when the command should end.
bool LiftDefault::IsFinished() { return false; }
