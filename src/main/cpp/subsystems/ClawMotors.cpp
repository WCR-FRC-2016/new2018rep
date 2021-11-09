/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClawMotors.h"
#include "OpenOneMotor.h"
#include "RobotMap.h"

ClawMotors::ClawMotors() {}

void ClawMotors::ClawMotorsInit() {
    initialized = true;

    OpenOneMotor* OpenClawMotor = new OpenOneMotor();
    LeftMotor = OpenClawMotor->Open(clawLeftMotor);
    RightMotor = OpenClawMotor->Open(clawRightMotor);
}

void ClawMotors::Periodic() {
    if (!initialized) {
        ClawMotors::ClawMotorsInit();
    }
}

void ClawMotors::WheelsIn(){
    LeftMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -clawMotorSpeed);
    RightMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, clawMotorSpeed);
}

void ClawMotors::WheelsOut(){
    LeftMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, clawMotorSpeed);
    RightMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, -clawMotorSpeed);
}

void ClawMotors::Stop(){
    LeftMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    RightMotor->Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
}