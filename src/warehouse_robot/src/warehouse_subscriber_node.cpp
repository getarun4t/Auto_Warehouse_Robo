#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using String = example_interfaces::msg::String;

class RobotSubscriberNode: public rclcpp::Node
{
public:
    RobotSubscriberNode(): Node("robot_subscriber")
    {
        subsriber_ = create_

    }

private:
    rclcpp::Subscription<Empty>::SharedPtr subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotSubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}