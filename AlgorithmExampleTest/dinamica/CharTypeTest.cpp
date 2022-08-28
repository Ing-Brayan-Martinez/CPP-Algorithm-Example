//
// Created by brayan on 20/07/2021.
//

#include <gtest/gtest.h>
#include <ChartType.h>

TEST(CharTypeTest, BasicAssertions) {
    char* a = GetSimpleData();
    char* b = GetSimpleData();

    EXPECT_EQ(a, b);

    EXPECT_EQ(7 * 6, 42);

}
