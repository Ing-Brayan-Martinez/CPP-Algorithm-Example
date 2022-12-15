//
// Created by Qard Group CA on 28/8/22.
//
#include "Ordering-QuickSort.h"

namespace Ordering {

    namespace {

        template <typename T>
        int partition(std::vector<T> &data, int lower, int upper) {
            int i = (lower - 1);
            int pivot = data[upper];

            for (int j = lower; j < upper; j++) {
                if (data[j] <= pivot) {
                    i++;
                    std::swap(data[i], data[j]);
                }
            }

            std::swap(data[i + 1], data[upper]);
            return (i + 1);
        }

        template <typename T>
        void InternalQuickSort(std::vector<T> &data, int lower, int upper) {
            if (upper > lower) {
                // partitioning index is returned by the partition method , partition
                // element is at its correct poition

                int partitionIndex = partition(data, lower, upper);

                // Sorting elements before and after the partition index
                InternalQuickSort(data, lower, partitionIndex - 1);
                InternalQuickSort(data, partitionIndex + 1, upper);
            }
        }
    }

    auto QuickSort(std::vector<int> &data) -> void {
        int lower = 0;
        int upper = data.size() - 1;

        if (upper > lower) {
            int partitionIndex = partition(data, lower, upper);

            InternalQuickSort(data, lower, partitionIndex - 1);
            InternalQuickSort(data, partitionIndex + 1, upper);
        }
    }

}