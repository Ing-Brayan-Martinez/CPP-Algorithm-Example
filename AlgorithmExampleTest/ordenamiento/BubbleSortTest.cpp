//
// Created by Qard Group CA on 28/8/22.
//

#include <gtest/gtest.h>
#include <Util.h>
#include <BubbleSort.h>

TEST(BubbleSortTest, BasicAssertions) {
    std::vector<int> data  = GetData();

    //before
    std::cout << "Before Sorting: " << std::endl;
    PrintData(data);

    //sort
    std::cout << std::endl;
    BubbleSort(data);

    //after
    std::cout << "After Sorting: " << std::endl;
    PrintData(data);
}
