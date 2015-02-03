#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

void intern_quick_sort(int *array, int size);

bool is_ordered(int *tb, int size) {
    int i = -1;

    while (++i < size - 1)
        if (tb[i] > tb[i + 1])
            return false;
    return true;
}

void move_values(int *tb, int pivot, int size) {
    if (is_ordered(tb, size) == true)
        return;
    int x = pivot - 1;
    int value = tb[pivot];
    int ac = pivot;

    while (x >= 0) {
        if (tb[x] > value) {
            tb[ac] = tb[x];
            tb[x] = value;
            ac = x;
        }
        --x;
    }
    intern_quick_sort(tb, pivot);
}

void intern_quick_sort(int *array, int size) {
    // I know it's not the best way to take the last element as pivot to start,
    // I'll look after another method to choose one
    int pivot = size - 1;

    move_values(array, pivot, size);
}

void quick_sort(int *array, int size) {
    while (is_ordered(array, size) == false)
        intern_quick_sort(array, size);
}