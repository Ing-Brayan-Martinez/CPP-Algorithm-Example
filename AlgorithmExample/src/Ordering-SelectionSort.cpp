//
// Created by Qard Group CA on 28/8/22.
//
#include "Ordering-SelectionSort.h"

std::vector<int> SelectionSort(std::vector<int> data) {
    std::vector<int>result;
    std::vector<int>::iterator it, et, at;
    double min;

    while (data.size() != 0) {
        it = data.begin();
        at = it;
        min =* it;

        for (et = data.begin(); et != data.end(); et++) {
            if (*et < min) {
                min = *et;
                at = et;
            }
        }
        data.erase(at);
        result.push_back(min);
    }
    return result;
}
