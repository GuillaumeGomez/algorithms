#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

typedef struct s_pile_container {
    int size;
    int **piles; // first value of the array is the pile's size
} pile_container;

int get_last(int *r) {
    return r[r[0] - 1];
}

int find_first_greater(pile_container *piles, int value) {
    int i;

    for (i = 0; i < piles->size && get_last(piles->piles[i]) < value; ++i);
    return i;
}

void add_piles(pile_container *piles, int value) {
    piles->size += 1;
    piles->piles = realloc(piles->piles, sizeof(*(piles->piles)) * piles->size);
    piles->piles[piles->size - 1] = malloc(sizeof(piles->piles[0][0]) * 2);
    piles->piles[piles->size - 1][0] = 2;
    piles->piles[piles->size - 1][1] = value;
}

void push_on_pile(int **pile, int value) {
    *pile = realloc(*pile, sizeof(**pile) * (pile[0][0] + 1));
    pile[0][pile[0][0]] = value;
    pile[0][0] += 1;
}

int get_littlest(pile_container *piles) {
    int i, min, pos;

    for (i = 1, min = get_last(piles->piles[0]), pos = 0; i < piles->size; ++i) {
        if (piles->piles[i][0] > 1 && get_last(piles->piles[i]) < min) {
            min = get_last(piles->piles[i]);
            pos = i;
        }
    }
    return pos;
}

int remove_last_from_stack(pile_container *piles, int i) {
    int *stack = piles->piles[i];
    int ret = get_last(stack);

    stack[0] -= 1;
    if (stack[0] < 2) {
        free(stack);
        for (; i < piles->size - 1; ++i)
            piles->piles[i] = piles->piles[i + 1];
        --piles->size;
    }
    return ret;
}

void reorder_piles(pile_container *piles) {
    int i = piles->size - 1;

    if (piles->size < 2)
        return;
    while (i > 0 && get_last(piles->piles[i]) > get_last(piles->piles[i - 1])) {
        int j = 0;
        int *tmp;

        while (get_last(piles->piles[i]) < get_last(piles->piles[j]))
            j++;
        tmp = piles->piles[i];
        piles->piles[i] = piles->piles[j];
        piles->piles[j] = tmp;
        return;
    }
}

void patience_sort(int *array, int size) {
    pile_container piles = {0, NULL};
    int i = 0;

    if (size < 2)
        return;
    while (i < size) {
        int pos;

        if ((pos = find_first_greater(&piles, array[i])) >= piles.size) {
            add_piles(&piles, array[i]);
        } else {
            push_on_pile(&piles.piles[pos], array[i]);
        }
        ++i;
    }
    for (i = 0; i < size; ++i) {
        int pos = get_littlest(&piles);
        array[i] = remove_last_from_stack(&piles, pos);
        if (piles.size > 1 && piles.piles[pos][0] > 1)
            reorder_piles(&piles);
    }
    for (i = piles.size - 1; i >= 0; --i) {
        free(piles.piles[i]);
    }
    free(piles.piles);
}