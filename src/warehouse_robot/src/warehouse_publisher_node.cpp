#include "rclcpp/rclcpp.hpp"


class RobotPublisherNode: public rclcpp::Node
{
public:
    RobotPublisherNode(): Node("robot_publisher")
    {

    }

private:

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}