#include <rclcpp/rclcpp.hpp>

class MyNode: public rclcpp::Node
{
public:
    MyNode():Node("cpp_test")
    {
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1), // 1 Hz
            std::bind(&MyNode::timer_callback, // refernece to the callbackfunction
            this // reference of this instance of class
        ));
    }
private:

    int count_ = 0;

    void timer_callback()
    {
        count_++;
        RCLCPP_INFO(this->get_logger(), "Hello, World %d",count_);
    }
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    RCLCPP_INFO(node->get_logger(), "Hello, World!");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}