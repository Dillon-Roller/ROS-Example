#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <rosbag/bag.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>


int main(int argc, char **argv) {

    ros::Time::init();
    rosbag::Bag bag;
    bag.open("test.bag", rosbag::bagmode::Write);

    std_msgs::String str;
    str.data = std::string("x:2, y:5, sum = 7");

    bag.write("chatter", ros::Time::now(), str);

    bag.close();

    return 0;
}

