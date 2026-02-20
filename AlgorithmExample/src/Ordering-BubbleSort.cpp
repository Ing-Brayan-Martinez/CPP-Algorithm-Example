//
// Created by Ing Brayan Martinez on 15/12/2022.
//
module;

#include <vector>
#include <algorithm>

export module ordering.bubblesort;

namespace Ordering {

    export auto BubbleSort(std::vector<int> &data) -> void {
        bool swap_check = true;
        int n = data.size();

        for (int i = 0; (i < n) && (swap_check); i++) {
            swap_check = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (data[j] > data[j + 1]) {
                    swap_check = true;
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
}

