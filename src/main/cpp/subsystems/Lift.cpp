/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"
#include "OpenOneMotor.h"
#include "RobotMap.h"

Lift::Lift() {}

void Lift::LiftInit() {
    initialized = true;

    OpenOneMotor* OpenLiftMotor = new OpenOneMotor();
    LeftMotor = OpenLiftMotor->Open(liftLeftMotor);
    RightMotor = OpenLiftMotor->Open(liftRightMotor);
    
    RightMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, liftLeftMotor);

    LeftMotor->SetInverted(false);
    RightMotor->SetInverted(true);
}

void Lift::Periodic() {
    if (!initialized) {
        Lift::LiftInit();
    }
}

void Lift::Move(double speed){
    LeftMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed * robotConfig["liftMotorSpeedFactor"]);
}