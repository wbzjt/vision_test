// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/VisionSubsystem.h"

VisionSubsystem::VisionSubsystem() {
  // Implementation of subsystem constructor goes here.

    // 获取默认的 NetworkTable 实例
  // m_ntInst = nt::NetworkTableInstance::GetDefault();

  // // 获取或创建一个名为 "myTable" 的表格
  // m_table = m_ntInst.GetTable("SmartDashboard");
  // test_topic = m_table->GetTopic("btn_id");


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
  // Implementation of subsystem periodic method goes here.
  // 接收消息
  test1 += 0.001;
  // test_value = m_table->GetEntry("btn_id").GetDouble(0); 

  test_value = frc::SmartDashboard::GetEntry("AprilTag_ID").GetDouble(0.0);
  frc::SmartDashboard::PutNumber("test_value", test_value);
  frc::SmartDashboard::PutNumber("test1", test1);

}

void VisionSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
