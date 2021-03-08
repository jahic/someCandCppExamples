#include<iostream>
#include<rclcpp/rclcpp.hpp>
#include<functional>
#include<std_msgs/msg/string.hpp>
#include<chrono>
#include<vector>
#include<thread>
#include<sched.h>


class MinimalPublisher : public rclcpp::Node
{
    public:
        MinimalPublisher() : Node("publisher"), count_(0), thread_number(4), arr_length(36000)
        {
            publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
            timer_ = this->create_wall_timer(
                std::chrono_literals::operator""ms(500), std::bind(&MinimalPublisher::timer_callback_parallel_affinity, this));
        }

    private:
        void timer_callback()
        {
            auto message = std_msgs::msg::String();

            message.data = "Hi From publisher";

            RCLCPP_INFO(this->get_logger(), "Publishing: %s", message.data.c_str());
            publisher_->publish(message);
        }

        void timer_callback_parallel_affinity()
        {
            std::vector<std::thread> threads(thread_number);

            cpu_set_t cpuset;

            CPU_ZERO(&cpuset);

            arr_ = new int[arr_length];

            for(int i = 0; i < arr_length; i++)
            {
                arr_[i] = i;
            }

            int iterator = 0;
            int j = 0;
            for(std::vector<std::thread>::iterator it = threads.begin(); it < threads.end(); it++)
            {
                *it = std::thread(std::bind(&MinimalPublisher::heavy_function, this, arr_, iterator));
                CPU_SET(j, &cpuset);
                pthread_setaffinity_np(it->native_handle(), sizeof(cpuset), &cpuset);
                CPU_CLR(j, &cpuset);
                iterator++;
                j = j + 3;
            }

            std::chrono::high_resolution_clock::time_point before = std::chrono::high_resolution_clock::now();
            for(std::vector<std::thread>::iterator it = threads.begin(); it < threads.end(); it++)
            {
                it->join();
            }
            std::chrono::high_resolution_clock::time_point after = std::chrono::high_resolution_clock::now();

            RCLCPP_INFO(this->get_logger(), "EXEC TIME: %d", std::chrono::duration_cast<std::chrono::nanoseconds>(after - before).count());

            delete[] arr_;
        }

        void timer_callback_parallel()
        {
            std::vector<std::thread> threads(thread_number);

            arr_ = new int[arr_length];

            for(int i = 0; i < arr_length; i++)
            {
                arr_[i] = i;
            }

            int iterator = 0;
            for(std::vector<std::thread>::iterator it = threads.begin(); it < threads.end(); it++)
            {
                *it = std::thread(std::bind(&MinimalPublisher::heavy_function, this, arr_, iterator));
                iterator++;
            }

            std::chrono::high_resolution_clock::time_point before = std::chrono::high_resolution_clock::now();
            for(std::vector<std::thread>::iterator it = threads.begin(); it < threads.end(); it++)
            {
                it->join();
            }
            std::chrono::high_resolution_clock::time_point after = std::chrono::high_resolution_clock::now();

            RCLCPP_INFO(this->get_logger(), "EXEC TIME: %d", std::chrono::duration_cast<std::chrono::nanoseconds>(after - before).count());

            delete[] arr_;
        }

        void * heavy_function(int* arr_, int iterator)
        {
            int result = 1;
            for(int i = iterator * 9000; i < (iterator + 1) * iterator; i++)
            {
                result += arr_[i] * arr_[i]; 
            }

            return NULL;
        }


        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        size_t count_;
        int thread_number;
        int arr_length;
        int* arr_;

};

class MinimalSubscriber : public rclcpp::Node
{
    public:
        MinimalSubscriber() : Node("subscriber"), count_(0)
        {
            subscription_1 = this->create_subscription<std_msgs::msg::String>("topic", 10, [this](std_msgs::msg::String::SharedPtr message){
                RCLCPP_INFO(this->get_logger(), "Subscriber %d getting message %s", 1, message->data.c_str());
            });

            subscription_2 = this->create_subscription<std_msgs::msg::String>("topic", 10, [this](std_msgs::msg::String::SharedPtr message){
                RCLCPP_INFO(this->get_logger(), "Subscriber %d getting message %s", 2, message->data.c_str());
            });

            subscription_3 = this->create_subscription<std_msgs::msg::String>("topic", 10, [this](std_msgs::msg::String::SharedPtr message){
                RCLCPP_INFO(this->get_logger(), "Subscriber %d getting message %s", 3, message->data.c_str());
            });

            subscription_4 = this->create_subscription<std_msgs::msg::String>("topic", 10, [this](std_msgs::msg::String::SharedPtr message){
                RCLCPP_INFO(this->get_logger(), "Subscriber %d getting message %s", 1, message->data.c_str());
            });
        }

    private:
        size_t count_;

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_1;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_2;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_3;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_4;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    rclcpp::executors::MultiThreadedExecutor multithreaded_executor;
    auto pub_node = std::make_shared<MinimalPublisher>();
    auto sub_node = std::make_shared<MinimalSubscriber>();

    multithreaded_executor.add_node(pub_node);
    multithreaded_executor.add_node(sub_node);

    multithreaded_executor.spin();

    return 0;
}