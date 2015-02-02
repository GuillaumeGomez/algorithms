#include "algo.h"

void bubble_sort(int *array, int size) {
    int i = 0;

    while (i < size - 1) {
        if (array[i] > array[i + 1]) {
            int cp = array[i];

            array[i] = array[i + 1];
            array[i + 1] = cp;
            if (i > 0) {
                i -= 2;
                continue;
            }
        }
        ++i;
    }
}