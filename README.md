# ROS-Example
This project was originally meant to be a workspace for teaching myself how ROS works, and has further developed into getting unit and ROSTests working alongside it. To run this program, please ensure you have catkin [installed](https://catkin-tools.readthedocs.io/en/latest/installing.html).

## Description
This program shows the implementation of node communication and passing information around using ROS and C++. The main goal is to have a main node that accepts some data (in this case, two integers) and to perform some work on this data (add them together). In order to pass information around, we need to specify what the data is. Specifically, since we are giving data to a node and expecting to receive data back, this naturally calls for using a [service](http://wiki.ros.org/Services). 

We have a server node, now we need a client node. ROSTest allows us to integrate our nodes together and ensure that all behavior is operating as expected. It allows you to spawn up a test node, and to interact with other nodes as if it was just another regular node. For this program, the test node is the client node, and will be requesting the service from the server node. The server node then receives the request, adds the two numbers together, and responds with the result, where the test node verifies the result. 

Note that this is not testing the logic used in the server node, just the response that we received. To test individual chunks of logic, we need to use unit tests. The server node is using a custom math library that I made just for this. 

In conclusion, we use unit tests to test the logic and behavior of units of code, like functions, and we use ROSTests to integration test and ensure the information is being passed around correctly. 

## Build
`catkin_make` to build source and tests. You must do this before proceeding to run the tests.

## Tests
`catkin_make run_tests` runs all tests along with their dependencies, including the rostest. Below is an example of what the output should look like for passing. 

## Unit Test
![unit](https://github.com/Dillon-Roller/ROS-Example/blob/master/picture-examples/unit-tests.png)

## ROS Test
![ros-test](https://github.com/Dillon-Roller/ROS-Example/blob/master/picture-examples/ros-test.png)
