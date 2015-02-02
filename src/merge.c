#include <stdlib.h>
#include <string.h>
#include "algo.h"

void merge(int *tb, int start, int middle, int end) {
    int i = start, j = middle, x = 0;
    int *tmp = malloc(sizeof(*tmp) * (end - start));

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
    free(tmp);
}

void intern_merge_sort(int *tb, int start, int end) {
    if (end - start < 2)
        return;
    int middle = (start + end) / 2;

    intern_merge_sort(tb, start, middle);
    intern_merge_sort(tb, middle, end);
    merge(tb, start, middle, end);
}

void merge_sort(int *array, int size) {
    intern_merge_sort(array, 0, size);
}