#include <gtest/gtest.h>

TEST(TestunitTest, alwaysTrue){
  EXPECT_TRUE(false);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
