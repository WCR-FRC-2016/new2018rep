/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClawPneumatics.h"
#include "RobotMap.h"

ClawPneumatics::ClawPneumatics() {}

void ClawPneumatics::ClawPneumaticsInit() {
    initialized = true;

    solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}

void ClawPneumatics::Periodic() {
    if (!initialized) {
        ClawPneumatics::ClawPneumaticsInit();
    }
}

void ClawPneumatics::OpenClaw() {
    solenoid.Set(frc::DoubleSolenoid::Value::kForward);
}

void ClawPneumatics::CloseClaw() {
    solenoid.Set(frc::DoubleSolenoid::Value::kReverse);
}