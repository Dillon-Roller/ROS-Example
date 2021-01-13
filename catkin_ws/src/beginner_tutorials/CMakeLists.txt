cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
add_message_files(FILES Num.msg)
add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(add_two_ints_server src/add_two_ints_server.cpp src/math_functions.cpp)
target_link_libraries(add_two_ints_server ${catkin_LIBRARIES})
add_dependencies(add_two_ints_server beginner_tutorials_gencpp)


if(CATKIN_ENABLE_TESTING)
    find_package(rostest REQUIRED)

    ## Node Test 
    add_rostest_gtest(rostest rostest/rostest.test rostest/rostest.cpp src/math_functions.cpp)
    target_link_libraries(rostest ${catkin_LIBRARIES})
    add_dependencies(rostest beginner_tutorials_gencpp)

    ## Unit Test 
    catkin_add_gtest(unittest test/unittest.cpp src/math_functions.cpp)
    target_link_libraries(unittest ${catkin_LIBRARIES})
    add_dependencies(unittest beginner_tutorials_gencpp)

endif()