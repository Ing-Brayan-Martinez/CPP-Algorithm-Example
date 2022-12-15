//
// Created by Qard Group CA on 28/8/22.
//

#include <gtest/gtest.h>
#include "Util-Data.h"
#include "Ordering-SelectionSort.h"

TEST(SelectionSortTest, BasicAssertions) {
    std::vector<int> data  = GetData();

    //before
    std::cout << "Before Sorting: " << std::endl;
    PrintData(data);

    //sort
    std::cout << std::endl;
    std::vector<int> result = SelectionSort(data);

    //after
    std::cout << "After Sorting: " << std::endl;
    PrintData(result);
}
