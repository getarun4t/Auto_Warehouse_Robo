#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using String = example_interfaces::msg::String;

class RobotPublisherNode: public rclcpp::Node
{
public:
    RobotPublisherNode(): Node("robot_publisher")
    {
        publisher_ = create_publisher<String>(
            "warehouse_test", 
            10
        );
        timer_ = create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&RobotPublisherNode::publishMsg, this)
        );
        RCLCPP_INFO(get_logger(), "Started the publisher");
    }

private:

    void publishMsg(){
        auto msg = String();
        msg.data = "Test";
        publisher_->publish(msg);
        RCLCPP_INFO(get_logger(), "Publishing a message");
    }

    rclcpp::Publisher<String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}