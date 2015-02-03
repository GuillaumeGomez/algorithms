#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "algo.h"

#define TB_SIZE 25000

int cmp(void *a, void *b) {
    int *x = a, *y = b;

    return *x - *y;
}

float p(int *tb, int size) {
    int *copy = malloc(sizeof(*copy) * size);
    struct timeval tmp, tmp2;

    memcpy(copy, tb, size * sizeof(*tb));
    gettimeofday(&tmp, NULL);
    qsort(copy, size, sizeof(*copy), (__compar_fn_t)cmp);
    gettimeofday(&tmp2, NULL);
    int i;
    for (i = 0; i < size - 1; i++) {
        if (copy[i] > copy[i + 1]) {
            printf("failure.\n");
            break;
        }
    }
    free(copy);
    return ((float)(tmp2.tv_sec - tmp.tv_sec)) + (tmp2.tv_usec - tmp.tv_usec) / 1000000.f;
}

float profile_function(int *tb, int size, void(*func)(int*, int)) {
    int *copy = malloc(sizeof(*copy) * size);
    struct timeval tmp, tmp2;

    memcpy(copy, tb, size * sizeof(*tb));
    gettimeofday(&tmp, NULL);
    func(copy, size);
    gettimeofday(&tmp2, NULL);
    int i;
    for (i = 0; i < size - 1; i++) {
        if (copy[i] > copy[i + 1]) {
            printf("failure.\n");
            break;
        }
    }
    free(copy);
    return ((float)(tmp2.tv_sec - tmp.tv_sec)) + (tmp2.tv_usec - tmp.tv_usec) / 1000000.f;
}

int main() {
    int tb[TB_SIZE], i = 0;

    for (; i < TB_SIZE; ++i)
        tb[i] = TB_SIZE - i;
    printf("Initialization done.\n");
    printf("\033[33;1m=> bubble sort: worst = n^2 | best = n | average = n^2\033[0m\n");
    printf("reversed array: %f secs\n", profile_function(tb, TB_SIZE, bubble_sort));
    printf("\033[33;1m=> merge sort : worst = n log n | best = n log n | average = n log n\033[0m\n");
    printf("reversed array: %f secs\n", profile_function(tb, TB_SIZE, merge_sort));
    printf("\033[33;1m=> quick sort : worst = n^2 | best = n log n | average = n log n\033[0m\n");
    printf("reversed array: %f secs\n", profile_function(tb, TB_SIZE, quick_sort));

    printf("original qsort: %f secs\n", p(tb, TB_SIZE));
    return 0;
}