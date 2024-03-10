#include <gtest/gtest.h>

// The purpose of these tests are just to  make sure that gtest was properly installed.

TEST(SampleTest, SimpleAssertion) {
    EXPECT_EQ(1, 1);
}

TEST(SampleTest, AnotherAssertion) {
    EXPECT_TRUE(true);
}

// The main entry point for running the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}