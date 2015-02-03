#include <stdlib.h>
#include <string.h>
#include "algo.h"

void merge(int *tb, int start, int middle, int end, int *tmp) {
    int i = start, j = middle, x = 0;

    while (x < (end - start) && i < middle && j < end) {
        if (tb[i] > tb[j]) {
            tmp[x++] = tb[j++];
        } else if (tb[i] < tb[j]) {
            tmp[x++] = tb[i++];
        } else {
            tmp[x++] = tb[i++];
            tmp[x++] = tb[j++];
        }
    }
    while (i < middle)
        tmp[x++] = tb[i++];
    while (j < end)
        tmp[x++] = tb[j++];
    memcpy(tb + start, tmp, (end - start) * sizeof(*tb));
}

void intern_merge_sort(int *tb, int start, int end, int *tmp) {
    if (end - start < 2)
        return;
    int middle = (start + end) / 2;

    intern_merge_sort(tb, start, middle, tmp);
    intern_merge_sort(tb, middle, end, tmp);
    merge(tb, start, middle, end, tmp);
}

void merge_sort(int *array, int size) {
    int *tmp = malloc(sizeof(*tmp) * size);

    intern_merge_sort(array, 0, size, tmp);
    free(tmp);
}
