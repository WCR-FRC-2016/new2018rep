/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <map>
#include <string>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

const int frontLeftDrive = 14; //encoder
const int frontRightDrive = 1; //encoder
const int backLeftDrive = 15;
const int backRightDrive = 0;

const int clawLeftMotor = 10;
const int clawRightMotor = 11;

const int liftLeftMotor = 4;
const int liftRightMotor = 5;

const int beltLeftMotor = 2;
const int beltRightMotor = 3;

// These aren't const because we might change them through a file.

// Must be stored in map to be set from file.

extern std::map<std::string, double> robotConfig;
    /*
    {"RampTime", 0.325},
    {"PIDDeadband", 0.114}, // TODO: PID needs to be tuned.
    {"clawMotorSpeed", 0.75},
    {"liftMotorSpeedFactor", 0.5},
    {"beltMotorSpeedFactor", 0.5},
    */
//};

const double NominalOutput = 0.25;
const double MaxOutput = 1.0;