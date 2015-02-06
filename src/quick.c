#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

static void swap(int *a, int *b) {
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void sort(int *array, int begin, int end) {
    static int pivot;

    if (end > begin) {
        int l = begin + 1;
        int r = end;
        swap(&array[begin], &array[begin + (end - begin) / 2]);
        pivot = array[begin];

        while (l < r) {
            if (array[l] <= pivot) {
                l++;
            } else {
                while (l < --r && array[r] >= pivot);
                swap(&array[l], &array[r]); 
            }
      }
      l--;
      swap(&array[begin], &array[l]);
      sort(array, begin, l);
      sort(array, r, end);
   }
}

void quick_sort(int *array, int size) {
    sort(array, 0, size);
}