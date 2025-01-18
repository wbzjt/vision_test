// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionSubsystem.h"
#include <iostream>

VisionSubsystem::VisionSubsystem() {
  // 将smartdashboard的entry赋值给子系统的entry
  Chassis_entry = frc::SmartDashboard::GetEntry("Chassis");
  AprilTag_entry = frc::SmartDashboard::GetEntry("AprilTag_ID");

}

frc2::CommandPtr VisionSubsystem::VisionMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  return RunOnce([/* this */] { /* one-time action goes here */ });
}

bool VisionSubsystem::VisionCondition() {
  // Query some boolean state, such as a digital sensor.
  return false;
}

void VisionSubsystem::Periodic() {
  try {

  // 接收消息
  GetPose_V();
  GetTag_V();
  frc::SmartDashboard::PutNumber("AprilTag_robot", tag_ID);
  frc::SmartDashboard::PutNumber("chassis_pos1", chassis_pos.X().value());

  } catch (const std::exception& e) {
    std::cout << "VisionSubsystem Periodic Failed: " << e.what() << std::endl;
}

}

void VisionSubsystem::SimulationPeriodic() {

  // Implementation of subsystem simulation periodic method goes here.

}

frc::Pose2d VisionSubsystem::GetPose_V() {
  // 获取entry的double数组
    
    auto tagPosVector = Chassis_entry.GetDoubleArray(std::vector<double>{0.0, 0.0, 0.0});
    chassis_pos = frc::Pose2d(units::meter_t{tagPosVector[0]}, 
                      units::meter_t{tagPosVector[1]}, 
                      units::degree_t{tagPosVector[2]});

    return chassis_pos;
}

double VisionSubsystem::GetTag_V() {
  // 根据entry更新信息
  tag_ID = AprilTag_entry.GetDouble(101);
  return tag_ID;
}
