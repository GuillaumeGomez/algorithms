#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

int is_ordered(int *tb, int size) {
    int i = -1;

    printf("size: %d\n", size);
    if (size < 2)
        return -1;
    while (++i < size - 1)
        if (tb[i] > tb[i + 1])
            return i + 1;
    printf("return -1 !\n");
    return -1;
}

int move_values(int *tb, int pivot, int size, int *copy) {
    int end = size - 1;
    int value = tb[pivot];
    int ac = size - 1;
    int save = 0;

    printf("Chosen %d\n", value);
    while (ac >= 0) {
        if (ac != pivot && tb[ac] > value) {
            copy[end--] = tb[ac];
        }
        --ac;
    }
    save = end;
    copy[end--] = value;
    ac = size - 1;
    while (ac >= 0) {
        if (ac != pivot && tb[ac] < value) {
            copy[end--] = tb[ac];
        }
        --ac;
    }
    int x = -1;
    while (++x < size)
        printf("%d ", copy[x]);
    printf("\n");
    memcpy(tb, copy, size * sizeof(*copy));
    return save;
}

void quick_sort(int *array, int size) {
    int *copy = malloc(sizeof(*array) * size);

    int pivot = move_values(array, size - 1, size, copy);
    int tmp = pivot;

    printf("pivot = %d\n", pivot);
    for (tmp = pivot; tmp != -1; tmp = is_ordered(array, pivot)) {
        printf("TMMMMMMP %d\n", tmp);
        move_values(array, tmp, size - pivot, copy);
    }
    printf("out !\n");
    for (tmp = size - 1; tmp != -1; tmp = is_ordered(array + pivot, size - pivot))
        move_values(array + pivot, tmp, size - pivot, copy);
    free(copy);
}