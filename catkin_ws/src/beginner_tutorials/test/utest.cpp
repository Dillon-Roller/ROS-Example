#include <gtest/gtest.h>
#include "ros/ros.h"
TEST(TestGroup, testName){

}


int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "tester");
  return RUN_ALL_TESTS();
}
