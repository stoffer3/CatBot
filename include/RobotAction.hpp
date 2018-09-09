
#pragma once

#include <vector>

namespace RobotAction
{
struct RobotAction
{
    enum {START, STOP, ROTATE, DIRECTION} type;
    union  
    {
        double rotate;
        std::vector<int> *driveDirection;
    };
};
} // RobotAction
