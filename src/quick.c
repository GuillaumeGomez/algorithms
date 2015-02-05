#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

int is_ordered(int *tb, int size) {
    int i = -1;

    if (size < 2)
        return -1;
    while (++i < size - 1)
        if (tb[i] > tb[i + 1])
            return i + 1;
    return -1;
}

int move_values(int *tb, int pivot, int size, int *copy) {
    if (size < 2)
        return 0;
    int end = size;
    int value = tb[pivot];
    int ac = size - 1;
    int save = 0;

    while (ac >= 0 && end > 0) {
        if (ac != pivot && tb[ac] > value) {
            copy[--end] = tb[ac];
        }
        --ac;
    }
    save = end;
    if (end > 0)
        copy[--end] = value;
    ac = size - 1;
    while (ac >= 0 && end > 0) {
        if (ac != pivot && tb[ac] <= value) {
            copy[--end] = tb[ac];
        }
        --ac;
    }
    memcpy(tb, copy, size * sizeof(*copy));
    return save;
}

void quick_sort(int *array, int size) {
    int *copy = malloc(sizeof(*array) * size);
    int pivot = move_values(array, size - 1, size, copy);
    int tmp;

    for (tmp = pivot; tmp != -1; tmp = is_ordered(array, pivot)) {
        move_values(array, tmp - 1, pivot, copy);
    }
    for (tmp = size - pivot - 1; tmp != -1; tmp = is_ordered(array + pivot, size - pivot))
        move_values(array + pivot, tmp - 1, size - pivot, copy);
    free(copy);
}