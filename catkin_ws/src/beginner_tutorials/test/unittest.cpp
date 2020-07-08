#include <gtest/gtest.h>

TEST(TestunitTest, alwaysTrue){
  ASSERT_EQ(true, true);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
