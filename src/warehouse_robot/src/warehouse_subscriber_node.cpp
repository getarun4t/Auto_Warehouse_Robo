#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using String = example_interfaces::msg::String;

using  namespace std::placeholders;

class RobotSubscriberNode: public rclcpp::Node
{
public:
    RobotSubscriberNode(): Node("robot_subscriber")
    {
        subscriber_ = create_subscription<String>(
            "warehouse_test", 
            10,
            std::bind(&RobotSubscriberNode::subscriptionCallBack, this, _1)
        );
        RCLCPP_INFO(get_logger(), "Started the subscriber");

    }

private:   
    void subscriptionCallBack(String msg){
        RCLCPP_INFO(get_logger(), "Received a message");
    }

    rclcpp::Subscription<String>::SharedPtr subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotSubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}