#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <rosbag/bag.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>


int main(int argc, char **argv) {

    ros::Time::init();
    rosbag::Bag bag;
    bag.open("./src/beginner_tutorials/bagfiles/test.bag", rosbag::bagmode::Write);

    std_msgs::String str;
    str.data = std::string("foo");

    std_msgs::Int32 i;
    i.data = 42;

    bag.write("chatter", ros::Time::now(), str);
    bag.write("numbers", ros::Time::now(), i);

    bag.close();

    return 0;
}

