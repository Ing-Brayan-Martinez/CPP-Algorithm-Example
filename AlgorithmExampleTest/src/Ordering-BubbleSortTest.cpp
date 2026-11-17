//
// Created by Qard Group CA on 28/8/22.
//

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
import util.data;
import ordering.bubblesort;

TEST(BubbleSortTest, BasicAssertions) {
    std::vector<int> data  = Util::GetData();

    std::cout << std::endl << "-- BubbleSort --" << std::endl << std::endl;

    //before
    std::cout << "Before Sorting: " << std::endl;
    Util::PrintData(data);

    //sort
    std::cout << std::endl;
    Ordering::BubbleSort(data);

    //after
    std::cout << "After Sorting: " << std::endl;
    Util::PrintData(data);

    assert(std::is_sorted(std::begin(data), std::end(data)));
    std::cout << std::endl << "Test Passed!" << std::endl;
}
