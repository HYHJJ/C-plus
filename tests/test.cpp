#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "Executor.h"

TEST(ExecutorTest, Initialization)
{
    Executor executor;
    executor.Init(1, 2, 'E');

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, 'E');
}

TEST(ExecutorTest, MoveForward)
{
    Executor executor;
    executor.Init(1, 2, 'E');
    executor.DoCommands("M");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, 'E');
}

TEST(ExecutorTest, TurnLeft)
{
    Executor executor;
    executor.Init(1, 2, 'E');
    executor.DoCommands("L");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, 'N');
}

TEST(ExecutorTest, TurnRight)
{
    Executor executor;
    executor.Init(1, 2, 'E');
    executor.DoCommands("R");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, 'S');
}

TEST(ExecutorTest, ExecuteCommands)
{
    Executor executor;
    executor.Init();
    executor.DoCommands("MMRMMRMM");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, 'S');
}

TEST(ExecutorTest, ComplexCommands)
{
    Executor executor;
    executor.Init();

    executor.DoCommands("MLMLMLML");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, 'N');
}

TEST(ExecutorTest, MixedCommands)
{
    Executor executor;
    executor.Init(1, 1, 'W');

    executor.DoCommands("MRMLMMRMM");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, -2);
    EXPECT_EQ(y, 4);
    EXPECT_EQ(heading, 'N');
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}