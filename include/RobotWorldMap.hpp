/*
 * RobotWorldMap.hpp
 *
 *  Created on: Jan 3, 2018
 *      Author: stoffer
 */

#pragma once

#include <vector>

namespace RobotWorldMap
{
struct RobotWorldMap
{
  bool frontBumperActivated = false;
  int distanceToObstacle = 0;
  std::vector<int> blurObjectVector;
  double compassValue = 0.0;
  double accelerometerValue = 0.0;
  double gyroValue = 0.0;
};
} /* namespace RobotWorldMap */
