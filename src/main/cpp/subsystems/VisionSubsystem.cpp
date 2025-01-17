// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionSubsystem.h"
#include <iostream>

VisionSubsystem::VisionSubsystem() {
  // 将smartdashboard的entry赋值给子系统的entry
  AprilTag_entry = frc::SmartDashboard::GetEntry("AprilTag");
  Chassis_entry = frc::SmartDashboard::GetEntry("Chassis");
  Vision_entry = frc::SmartDashboard::GetEntry("Vision");

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
  // 根据entry更新信息
  tag_ID = AprilTag_entry.GetDouble(0);
  auto tagPosVector = Vision_entry.GetDoubleArray(std::vector<double>{0.0, 0.0, 0.0});
  for (uint8_t i = 0; i <= 2 ; i++) {
    tag_pos[i] = tagPosVector[i];
  }
  // 接收消息
  test1 += 0.001;
  test_array[0] += 0.001;
  test_array[1] += 0.001;
  test_array[2] += 0.001;
  // tag_pos[0] += 0.001;
  // test_value = m_table->GetEntry("btn_id").GetDouble(0); 

  // frc::SmartDashboard::PutNumber("tag_ID", tag_ID);
  frc::SmartDashboard::PutNumber("test1", test1);

  std::vector<double> test_array = {0.1, 0.1, 0.1};
  frc::SmartDashboard::PutNumber("test2", test_array[0]);
  frc::SmartDashboard::PutNumber("tag_pos", tag_pos[2]);


  // frc::SmartDashboard::PutNumberArray("test_array", test_array);

  } catch (const std::exception& e) {
    std::cout << "Subsystem Initialization Failed: " << e.what() << std::endl;
}

}

void VisionSubsystem::SimulationPeriodic() {

  // Implementation of subsystem simulation periodic method goes here.

}
