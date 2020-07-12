#include <gtest/gtest.h>
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>

TEST(TestNode, testCreateBag) {
  ros::Time::init();
  rosbag::Bag bag;
  bag.open("test.bag", rosbag::bagmode::Write);

  std_msgs::String str;
  str.data = std::string("foo");

  std_msgs::Int32 i;
  i.data = 42;

  bag.write("chatter", ros::Time::now(), str);
  bag.write("numbers", ros::Time::now(), i);

  bag.close();
}

TEST(TestNode, testAddIntsClient){
  
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  beginner_tutorials::AddTwoInts srv;

  //Request the 2 integers to be 1 and 1 respectively
  srv.request.a = (long long int)1;
  srv.request.b = (long long int)1;

  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
  }

  //Assert the sum be 1 + 1 = 2
  EXPECT_EQ((long int)srv.response.sum, (long int)2);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  return RUN_ALL_TESTS();
}
