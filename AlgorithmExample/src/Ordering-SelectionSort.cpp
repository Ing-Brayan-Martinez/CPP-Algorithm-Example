//
// Created by Qard Group CA on 28/8/22.
//
#include "Ordering-SelectionSort.h"

namespace Ordering {

    auto SelectionSort(std::vector<int> &data) -> void {

        for (int i = 0; i < data.size() - 1; i++) {
            int min_index = i;
            for (int j = i + 1; j < data.size(); j++) {
                if (data[min_index] > data[j]) {
                    min_index = j;
                }
            }
            if (min_index != i)
            {
                std::swap(data[i], data[min_index]);
            }
        }
    }
}

