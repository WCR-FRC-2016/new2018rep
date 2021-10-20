/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
    m_driveBase.SetDefaultCommand(ArcadeDrive(&m_driveBase, 
    //[this] { return m_driverStick.GetX(frc::GenericHID::kRightHand);} ,
    //[this] { return -m_driverStick.GetY(frc::GenericHID::kLeftHand) ;}
    [this] {return 0.5;},
    [this] {return 0.0;}
    ));
}