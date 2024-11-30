#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "Executor.h"

// 测试初始化
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

// 测试前进
TEST(ExecutorTest, MoveForward)
{
    Executor executor;
    executor.Init(1, 2, 'E');
    executor.Move("M");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, 'E');
}

// 测试左转
TEST(ExecutorTest, TurnLeft)
{
    Executor executor;
    executor.Init(1, 2, 'E');
    executor.Move("L");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, 'N');
}

// 测试右转
TEST(ExecutorTest, TurnRight)
{
    Executor executor;
    executor.Init(1, 2, 'E');
    executor.Move("R");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 1);
    EXPECT_EQ(y, 2);
    EXPECT_EQ(heading, 'S');
}

// 测试执行长命令
TEST(ExecutorTest, ExecuteCommands)
{
    Executor executor;
    executor.Init();
    executor.Move("MMRMMRMM");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 2);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, 'S');
}

// 测试复杂命令
TEST(ExecutorTest, ComplexCommands)
{
    Executor executor;
    executor.Init();

    executor.Move("MLMLMLML");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 0);
    EXPECT_EQ(heading, 'N');
}

// 测试混合命令
TEST(ExecutorTest, MixedCommands)
{
    Executor executor;
    executor.Init(1, 1, 'W');

    executor.Move("MRMLMMRMM");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, -2);
    EXPECT_EQ(y, 4);
    EXPECT_EQ(heading, 'N');
}

// 测试快速模式下的移动
TEST(ExecutorTest, FastMove)
{
    Executor executor;
    executor.Init();

    executor.Move("FMLMLMFR");

    int32_t x, y;
    char heading;
    executor.GetPositionAndHeading(x, y, heading);

    EXPECT_EQ(x, -3);
    EXPECT_EQ(y, 1);
    EXPECT_EQ(heading, 'W');
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}