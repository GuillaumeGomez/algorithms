#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

void intern_quick_sort(int *array, int size, int *copy);

bool is_ordered(int *tb, int size) {
    int i = -1;

    while (++i < size - 1)
        if (tb[i] > tb[i + 1])
            return false;
    return true;
}

void move_values(int *tb, int pivot, int size, int *copy) {
    if (is_ordered(tb, size) == true)
        return;
    int i = pivot;
    int x = pivot - 1;
    int value = tb[pivot];

    while (x >= 0) {
        if (tb[x] > value)
            copy[i--] = tb[x];
        --x;
    }
    copy[i--] = value;
    x = pivot - 1;
    while (x >= 0) {
        if (tb[x] <= value)
            copy[i--] = tb[x];
        --x;
    }
    memcpy(tb, copy, sizeof(*copy) * (pivot + 1));
    intern_quick_sort(tb, pivot, copy);
}

void intern_quick_sort(int *array, int size, int *copy) {
    // I know it's not the best way to take the last element as pivot to start,
    // I'll look after another method to choose one
    int pivot = size - 1;

    move_values(array, pivot, size, copy);
}

void quick_sort(int *array, int size) {
    int *copy = malloc(sizeof(*copy) * size);

    while (is_ordered(array, size) == false)
        intern_quick_sort(array, size, copy);
    free(copy);
}