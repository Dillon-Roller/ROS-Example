/*
  This file contains all unit tests for MathFunctions static methods
*/
#include <gtest/gtest.h>
#include "../src/math_functions.h"

TEST(MathFunctions, add){
  EXPECT_EQ(MathFunctions::add(3, 3), 6) << "Add did not yield correct result";
}

TEST(MathFunctions, subtract) {
  EXPECT_EQ(MathFunctions::subtract(3, 3), 0) << "Subtract did not yield correct result";
}

TEST(MathFunctions, multiply) {
  EXPECT_EQ(MathFunctions::multiply(3, 3), 9) << "Multiply did not yield correct result";
}

TEST(MathFunctions, divide) {
  EXPECT_EQ(MathFunctions::divide(3, 3), 1) << "Divide did not yield correct result";
}

TEST(MathFunctions, isEqual) {
  EXPECT_TRUE(MathFunctions::isEqual(3, 3)) << "isEqual returned false on 3, 3, expected true";
  EXPECT_FALSE(MathFunctions::isEqual(3, 5)) << "isEqual returned true on 3, 5, expected false";
}

TEST(MathFunctions, isNotEqual) {
  EXPECT_TRUE(MathFunctions::isNotEqual(3, 5)) << "isNotEqual returned false on 3, 5, expected true";
  EXPECT_FALSE(MathFunctions::isNotEqual(3, 3)) << "isNotEqual returned true on 3, 5, expected false";
}

/*
  Starts gtest and runs all tests
*/
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
