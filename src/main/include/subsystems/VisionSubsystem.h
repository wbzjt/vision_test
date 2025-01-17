// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/GenericEntry.h>
#include <frc/DriverStation.h>
class VisionSubsystem : public frc2::SubsystemBase {
 public:
  VisionSubsystem();

  /**
   * Example command factory method.
   */
  frc2::CommandPtr VisionMethodCommand();

  /**
   * An example method querying a boolean state of the subsystem (for example, a
   * digital sensor).
   *
   * @return value of some boolean subsystem state, such as a digital sensor.
   */
  bool VisionCondition();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

    //定义Networktables的实例
  // nt::NetworkTableInstance m_ntInst;
  // std::shared_ptr<nt::NetworkTable> m_table;
  // std::shared_ptr<nt::DoubleTopic> test_topic;

  /* nano的摄像机识别的数据传输topic */
  nt::NetworkTableEntry  AprilTag_entry;
  nt::NetworkTableEntry  Chassis_entry;
  nt::NetworkTableEntry  Vision_entry;

  /* 触摸屏驾驶战的数据传输topic */
  nt::NetworkTableEntry  Com_entry;


  // 摄像头的识别结果
  double tag_pos[3] = {0.0, 0.0, 0.0}; // AprilTag识别的目标全局位置
  double chassis_pos[3] = {0.0, 0.0, 0.0}; // 底盘的当前全局位置
  float tag_ID; // AprilTag的识别ID

  // 触摸屏的传输结果
  double com_pos[3] = {0.0, 0.0, 0.0}; // 触摸屏传输的目标全局位置
  double com_flag = 0.0; // 触摸屏传输的标志位


  double test_value = 0.0;
  std::vector<double> test_array = {0.1, 0.1, 0.1};
  double test1 = 0.001;
};
