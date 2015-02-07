#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

void shell_sort(int *array, int size) {
    int gap = size / 2;

    while (gap > 0) {
        int tmp = array[gap];

        int i = gap;
        while (i < size) {
            int j = i;

            while (j >= gap && array[j - gap] > tmp) {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = tmp;
            ++i;
        }
        gap /= 2;
    }
}