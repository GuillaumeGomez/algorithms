#include "algo.h"

void move_values(int *tb, int pivot) {
    int i = pivot - 1;
    int new_limit = pivot;
    int value = tb[pivot];

    while (i >= 0) {
        if (tb[i] > value) {
            tb[pivot] = tb[i];
            tb[i] = value;
            pivot = i;
        }
        ++i;
    }
}

void quick_sort(int *array, int size) {
    // I know it's not the best way to take the last element as pivot to start,
    // I'll look after another method to choose one
    int pivot = size - 1;

    move_values(array, pivot);
}