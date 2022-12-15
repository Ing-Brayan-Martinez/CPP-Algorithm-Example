//
// Created by Qard Group CA on 12/15/22.
//
#include <gtest/gtest.h>
#include <Dinamic-ChartType.h>

TEST(CharTypeTest, BasicAssertions) {
    char* a = GetSimpleData();
    char* b = GetSimpleData();

    EXPECT_EQ(a, b);

    EXPECT_EQ(7 * 6, 42);

}