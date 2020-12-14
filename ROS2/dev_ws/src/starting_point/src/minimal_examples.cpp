/**
 * AUTHOR: Arian AJDARI 
 * 
 * DESCRIPTION: This file contains a bunch of Nodes represented as classes. They usually play the role of subscribers and publishers. The main
 * purpose of this file is to demonstrate different capabilities of ROS2.
 * 
 * ATTENTION: If you feel dizzy of seeing so many classes on top of each other, head down to main to read a summarized version and come back to each class for further clarification
 * 
 * WARNING: USE AT YOUR OWN RISK.
 * 
 * ADVICE: Allthough this will work on compiled version of ROS2, it is good to compile ROS2 from binaries, so users can navigate to files that
 * I point out in this documentation
 */

// Chrono is used extensively in ROS2 for measuring time and setting up timers
#include <chrono>

// Functional is used to bind functions of classes in different scenarios such as timers, threads etc.
#include <functional>

// Main ROS2 class - C++ implmentations
#include <rclcpp/rclcpp.hpp>

// This class was created on rclcpp package as an addon. It's purpose was to test the most sensible way to extend ROS2 with additional capabilities.
#include <rclcpp/allocator/allocator_stack.hpp>

// Message of type string that is passed through publishers and subscriberd
#include <std_msgs/msg/string.hpp>

// Gives the ability to use stuff such as 500ms, 100s with Chrono
using namespace std::chrono_literals;

//Standard stuff
#include <memory>
#include <string>
#include <thread>
#include <sstream>
#include <future>
#include <atomic>

/**
 * Main logical unit of ROS is extended through rclcpp::Node class. This class contains most commonly used elements by Robotics Engineers such
 * as Subscribers, Publishers, Timers, Services etc. 
 * 
 * This particular class plays the rols of a Publisher.
 */
class MinimalPublisher : public rclcpp::Node
{
    public:
        //Through constructor we can give the node the name, namespace and possibly determine QoS settings.
        MinimalPublisher() : Node("minimal_publisher") 
        {
            // We create a publisher which publishes a message of type std_msgs::msg::String.
            // We publish the message on topic named "topic".
            // Number 10 indicates how many of them to keep.
            // Additional settings include how many messages to keep, should we be able to drop messages (Best Effort) etc.
            publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);

            // Timer binds the function and selects the repeat rate (frequency)
            timer = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
        }

    private:
        // Function which will be executed every 500ms (determined in timer).
        void timer_callback()
        {
            auto message = std_msgs::msg::String();

            std::stringstream ss;

            //The reason why we publish thread id is to get an understanding of how spinners (single threaded executor and multithreaded executor work)
            //As we notice during singlethreaded executor, always the same thread publishes the message. Whereas with multithreaded executor, available thread picks up
            // the message and publishes it. Here questions such as thread locking come into play.
            ss << std::this_thread::get_id();
            
            message.data = ss.str();

            //For displaying purposes only. Since this is like printf, it's not advisable to use this in any real-time context.
            RCLCPP_INFO(this->get_logger(), "Publishing on Thread: '%s'", message.data.c_str());
            publisher->publish(message);
        }

        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};

/**
 * This class plays the role of subscriber. For the sake of demonstration, we use two different subscribers and check which thread gets the message.
 * This comes into play when choosing the type of executor.
 */
class MinimalSubscriber : public rclcpp::Node
{
    public:
        MinimalSubscriber() : Node("minimal_subscriber")
        {
            subscriber = this->create_subscription<std_msgs::msg::String>("topic", 10, [this](std_msgs::msg::String::SharedPtr message) {
                std::stringstream ss;
                ss << std::this_thread::get_id();
                message->data = ss.str();
                RCLCPP_INFO(this->get_logger(), "Received on Thread: '%s'", message->data.c_str());
            });

            subscriber2 = this->create_subscription<std_msgs::msg::String>("topic", 10, [this](std_msgs::msg::String::SharedPtr message) {
                std::stringstream ss;
                ss << std::this_thread::get_id();
                message->data = ss.str();
                RCLCPP_INFO(this->get_logger(), "Received on Thread 2: '%s'", message->data.c_str());
            });
        }
    
    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber2;
};


/**
 * This class creates a thread (BLOCKING), does a calculation and publishes the thread id as a message. 
 * Purpose of this class is to prove the thread-safe nature of ROS code.
 */
class MinimalPublisherBlockingThread : public rclcpp::Node
{
    public:
        MinimalPublisherBlockingThread() : Node("minimal_publisher_blocking_thread")
        {
            publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);
            timer = this->create_wall_timer(500ms, std::bind(&MinimalPublisherBlockingThread::timer_callback, this));
        }

    private:
        void timer_callback()
        {
            std::thread(std::bind(&MinimalPublisherBlockingThread::thread_calc, this)).join();
            
            auto message = std_msgs::msg::String();

            std::stringstream ss;
            ss << std::this_thread::get_id();
            
            message.data = ss.str();
            RCLCPP_INFO(this->get_logger(), "Publishing on Thread: '%s'", message.data.c_str());
            publisher->publish(message);
        }

        void thread_calc()
        {   
            auto message = std_msgs::msg::String();

            std::stringstream ss;
            ss << std::this_thread::get_id();

            message.data = ss.str();

            RCLCPP_INFO(this->get_logger(), "Performing calculation on Thread: '%s'", message.data.c_str());
            int sum = 0;
            for(int i = 0; i < 1000000000; i++)
                sum+= i;

        }


        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};

/**
  * This class creates a thread (NON-BLOCKING), does a calculation and publishes the thread id as a message. 
  * Purpose of this class is to prove the thread-safe nature of ROS2 code.
  * It also publishes the time it took to finish the calculation. 
  * It also proves that threads running in background are safe in ROS2 context.
 */
class MinimalPublisherNonBlockingThread : public rclcpp::Node
{
    public:
        MinimalPublisherNonBlockingThread() : Node("minimal_publisher_blocking_thread"), calculation_finished(false) ,thread_created(false)
        {
            publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);
            timer = this->create_wall_timer(500ms, std::bind(&MinimalPublisherNonBlockingThread::timer_callback, this));
        }

    private:
        void timer_callback()
        {
            if(!thread_created)
            {
                std::thread(std::bind(&MinimalPublisherNonBlockingThread::thread_calc, this)).detach();
                thread_created = true;
            }       
            auto message = std_msgs::msg::String();

            std::stringstream ss;
            ss << std::this_thread::get_id();
            message.data = ss.str();
            if(calculation_finished)
            {
                RCLCPP_INFO(this->get_logger(), "Calculation Finished on Thread: '%s'", message.data.c_str());
                calculation_finished = false;
                thread_created = false;
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "Calculation Continuing on Thread: '%s'", message.data.c_str());
            }
            publisher->publish(message);
        }

        void thread_calc()
        {   
            auto message = std_msgs::msg::String();

            std::stringstream ss;
            ss << std::this_thread::get_id();

            message.data = ss.str();

            //RCLCPP_INFO(this->get_logger(), "Performing calculation on Thread: '%s'", message.data.c_str());
            int sum = 0;
            for(int i = 0; i < 1000000000; i++)
                sum+= i;

            calculation_finished = true;
        }

        bool calculation_finished;
        bool thread_created;

        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};

/**
 * This class creates a multiple-thread (BLOCKING), does a calculation and publishes the thread id as a message. 
 * Purpose of this class is to prove the thread-safe nature of ROS code.
 */
class MinimalPublisherMultipleBlockingThreads : public rclcpp::Node
{
    public: 
        MinimalPublisherMultipleBlockingThreads() : Node("minimal_publisher_multiple_blocking_threads") 
        {
            publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);
            timer = this->create_wall_timer(500ms, std::bind(&MinimalPublisherMultipleBlockingThreads::timer_callback, this));
        }
    private:
        MinimalPublisherMultipleBlockingThreads(const char * name) : Node(name)
        {

        }

        void timer_callback()
        {
            std::chrono::time_point<std::chrono::system_clock> before = std::chrono::high_resolution_clock::now();
            auto message = std_msgs::msg::String();

            MinimalPublisherMultipleBlockingThreads* object = new MinimalPublisherMultipleBlockingThreads("object_pointer");
            
            // We notice a little problem here. When user wants to declare a function to be consumed by std::thread which has an argument
            // Users have to create an instance of same object and pass it as a pointer. Sending "this" does not work. The class has to static to work I think.
            // Although the results are the same, implementation details looks a little bit clumsy.
            for(int i = 0; i < 10; i++)
                std::thread(std::bind(&MinimalPublisherMultipleBlockingThreads::thread_calc, object, i)).join();
            
            // Prevent memory leak.
            delete object;

            std::chrono::time_point<std::chrono::system_clock> after = std::chrono::high_resolution_clock::now();

            std::stringstream ss;
            ss << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
            message.data = ss.str();
            
            //Notice the performance gain.
            RCLCPP_INFO(this->get_logger(), "Calculation Finished on Thread for '%s' milliseconds", message.data.c_str());
            publisher->publish(message);
        }

        void thread_calc(int instance)
        {   
            auto message = std_msgs::msg::String();

            std::stringstream ss;
            ss << std::this_thread::get_id();

            message.data = ss.str();

            int sum = 0;
            for(int i = instance; i < 1000000000; i++)
                sum+= i;
        }

        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};

/**
  * This class creates a multiple-threads (NON-BLOCKING), does a calculation and publishes the thread id as a message. 
  * Purpose of this class is to prove the thread-safe nature of ROS2 code.
  * It also publishes the time it took to finish the calculation. 
  * It also proves that threads running in background are safe in ROS2 context.
 */
class MinimalPublisherMultipleNonBlockingThreads : public rclcpp::Node
{
    public: 
        MinimalPublisherMultipleNonBlockingThreads() : Node("minimal_publisher_multiple_non_blocking_threads"), thread_created(false)
        {
            publisher = this->create_publisher<std_msgs::msg::String>("topic", 10);
            timer = this->create_wall_timer(100ms, std::bind(&MinimalPublisherMultipleNonBlockingThreads::timer_callback, this));
        }
        bool calculation_finished[7]{false,false,false,false,false,false,false};
    private:
        MinimalPublisherMultipleNonBlockingThreads(const char * name) : Node(name)
        {

        }

        void timer_callback()
        {
            auto message = std_msgs::msg::String();
            
            if(!thread_created)
            {
                before = std::chrono::high_resolution_clock::now();
                

                object = new MinimalPublisherMultipleNonBlockingThreads("object_pointer");

                for(int i = 0; i < 7; i++)
                    std::thread(std::bind(&MinimalPublisherMultipleNonBlockingThreads::thread_calc, object, i)).detach();
                thread_created = true;
            }
            
            if(object->calculation_finished[0] 
            && object->calculation_finished[1] 
            && object->calculation_finished[2] 
            && object->calculation_finished[3]
            && object->calculation_finished[4] 
            && object->calculation_finished[5] 
            && object->calculation_finished[6]
            )
            {
                delete object;
                
                after = std::chrono::high_resolution_clock::now();

                std::stringstream ss;
                ss << std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
                message.data = ss.str();
                
                calculation_finished[0] = false;
                calculation_finished[1] = false;
                calculation_finished[2] = false;
                calculation_finished[3] = false;
                calculation_finished[4] = false;
                calculation_finished[5] = false;
                calculation_finished[6] = false;
                thread_created = false;
                RCLCPP_INFO(this->get_logger(), "Calculation Finished on Thread for '%s' milliseconds", message.data.c_str());
                publisher->publish(message);
            }
            else
            {
                message.data = "";
                RCLCPP_INFO(this->get_logger(), "Calculating...", message.data.c_str());
            }

            
        }

        void thread_calc(int instance)
        {   
            auto message = std_msgs::msg::String();

            std::stringstream ss;
            ss << std::this_thread::get_id();

            message.data = ss.str();
            
            int sum = 0;
            for(int i = instance; i < 1000000000; i = i + 7)
                sum+= i;
            
            calculation_finished[instance] = true;
        }

        std::chrono::time_point<std::chrono::system_clock> before;
        std::chrono::time_point<std::chrono::system_clock> after;

        
        bool thread_created;

        MinimalPublisherMultipleNonBlockingThreads* object;
        rclcpp::TimerBase::SharedPtr timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};

int main(int argc, char ** argv)
{
    /**
     * ADVICE: Only one demo can be compiled at a time
     * ADVICE: ROS2 Foxy was used
     * ADVICE: Other combinations are possible as well.
     * ADVICE: Using visual studio code in LINUX environment should instantly recognise rclcpp classes because of modified c_cpp_properties.json
     *         inside .vscode folder.
     * 
     * FUTURE: Other meaningful demos may be added.
     */

    //Classes contained in this file
    // 1. MinimalPublisher
    // 2. MinimalSubscriber
    // 3. MinimalPublisherBlockingThread
    // 4. MinimalPublisherNonBlockingThread
    // 5. MinimalPublisherMultipleBlockingThreads
    // 6. MinimalPublisherMultipleNonBlockingThreads

    // This does initialization stuff
    rclcpp::init(argc, argv);

//DEMO 1    
    //Normal rclcpp::spin - single threaded. Most commonly used in ROS1.
    /** WARNING: ONLY ONE NODE */ 
    //Uncomment and compile the row below to be able to use it.
    /*
        rclcpp::spin(std::make_shared<MinimalPublisher>());
    */
//END DEMO 1

//DEMO 2
    //Single Threaded Executor
    //Notice how always the same thread publishes the message. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::SingleThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisher>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 2

//DEMO 3
    //Single Threaded Executor
    //Notice how always the same thread publishes and receives the message. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::SingleThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisher>();
        auto sub_node = std::make_shared<MinimalSubscriber>();
        executor.add_node(pub_node);
        executor.add_node(sub_node);
        executor.spin();
    */
//END DEMO 3

//DEMO 4
    //Multi Threaded Executor
    //Notice how different threads publish the message. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::MultiThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisher>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 4    

//DEMO 5
    //Multi Threaded Executor
    //Notice how different threads publish and receive the message. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::MultiThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisher>();
        auto sub_node = std::make_shared<MinimalSubscriber>();
        executor.add_node(pub_node);
        executor.add_node(sub_node);
        executor.spin();
    */
//END DEMO 5
    
//DEMO 6
    //Single Threaded Executor Blocking User Threads. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::SingleThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherBlockingThread>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 6
    
//DEMO 7
    //Multi Threaded Executor Blocking User Threads. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::MultiThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherBlockingThread>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 7

//DEMO 8
    //Single Threaded Executor Non Blocking User Threads. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::SingleThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherNonBlockingThread>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 8
    
//DEMO 9
    //Multi Threaded Executor Non Blocking User Threads. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::MultiThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherNonBlockingThread>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 9

//DEMO 10
    //Single Threaded Executor Multiple Blocking User Threads. Uncomment the chunck down below to execute.
    /** WARNING: It can take quite some time to finish the calculation :) */
    /*
        rclcpp::executors::SingleThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherMultipleBlockingThreads>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 10
    
//DEMO 11
    //Multi Threaded Executor Multiple Blocking User Threads. Uncomment the chunck down below to execute.
    /*
        rclcpp::executors::MultiThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherMultipleBlockingThreads>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 11

//DEMO 12
    //Single Threaded Executor Multiple Non Blocking User Threads. Uncomment the chunck down below to execute.
    /** TIP: Notice the speed-up compared to DEMO: 10 and DEMO: 11 */
    /*
        rclcpp::executors::SingleThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherMultipleNonBlockingThreads>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 12
    
//DEMO 13
    //Multi Threaded Executor Multiple Non Blocking User Threads. Uncomment the chunck down below to execute.
    /** TIP: Notice the speed-up compared to DEMO: 10 and DEMO: 11 */
    /*
        rclcpp::executors::MultiThreadedExecutor executor;
        auto pub_node = std::make_shared<MinimalPublisherMultipleNonBlockingThreads>();
        executor.add_node(pub_node);
        executor.spin();
    */
//END DEMO 13


   // It's self-explanatory
    rclcpp::shutdown();

    return 0;
}