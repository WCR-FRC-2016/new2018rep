/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Belt.h"
#include "OpenOneMotor.h"
#include "RobotMap.h"

Belt::Belt() {}

void Belt::BeltInit() {
    initialized = true;

    OpenOneMotor* OpenBeltMotor = new OpenOneMotor();
    LeftMotor = OpenBeltMotor->Open(beltLeftMotor);
    RightMotor = OpenBeltMotor->Open(beltRightMotor);
    
    RightMotor->Set(ctre::phoenix::motorcontrol::ControlMode::Follower, beltLeftMotor);

    LeftMotor->SetInverted(false);
    RightMotor->SetInverted(true);
}

void Belt::Periodic() {
    if (!initialized) {
        Belt::BeltInit();
    }
}

void Belt::Move(double speed){
    LeftMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, speed * beltMotorSpeedFactor);
}