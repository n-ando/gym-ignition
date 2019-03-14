#ifndef GYMPP_ROBOT_ROBOTSINGLETON_H
#define GYMPP_ROBOT_ROBOTSINGLETON_H

#include "gympp/Robot.h"

#include <memory>

namespace gympp {
    class Robot;
    namespace gazebo {
        class RobotSingleton;
    } // namespace gazebo
} // namespace gympp

class gympp::gazebo::RobotSingleton
{
private:
    class Impl;
    std::unique_ptr<Impl> pImpl;

public:
    RobotSingleton();
    ~RobotSingleton() = default;
    RobotSingleton(RobotSingleton&) = delete;
    void operator=(const RobotSingleton&) = delete;

    static RobotSingleton& get();

    RobotPtr getRobot(const std::string& robotName) const;
    bool storeRobot(RobotPtr robotInterface);
};

#endif // GYMPP_ROBOT_ROBOTSINGLETON_H
