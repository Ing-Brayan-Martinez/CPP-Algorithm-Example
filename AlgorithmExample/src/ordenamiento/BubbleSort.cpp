//
// Created by Qard Group CA on 28/8/22.
//
#include <BubbleSort.h>

auto BubbleSort(std::vector<int> data) -> void {
    bool swap_check = true;
    int n = data.size();

    for (int i = 0; (i < n) && (swap_check); i++) {
        swap_check = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                swap_check = true;
                std::swap(data[j],
                          data[j + 1]);  // by changing swap location.
                // I mean, j. If the number is
                // greater than j + 1, then it
                // means the location.
            }
        }
    }
}
