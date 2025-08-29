#include "rclcpp/rclcpp.hpp"


class RobotSubscriberNode: public rclcpp::Node
{
public:
    RobotSubscriberNode(): Node("robot_subscriber")
    {

    }

private:

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotSubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}