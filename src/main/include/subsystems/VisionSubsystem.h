// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/smartdashboard/SmartDashboard.h>

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
  // std::shared_ptr<nt::DoubleEntry> dblEntry;

  double test_value = 0.0;
  double test1 = 0.001;
};
