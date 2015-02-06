#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

typedef struct s_element {
    struct s_element *next;
    int value;
} element;

element *add_element(element *prev, int value) {
    element *n = malloc(sizeof(*n));

    n->next = NULL;
    n->value = value;
    if (prev) {
        n->next = prev->next;
        prev->next = n;
    }
    return n;
}

void insertion_sort(int *array, int size) {
    if (size < 2)
        return;
    element *f = add_element(NULL, array[0]);
    int i = 0;

    while (++i < size) {
        element *tmp = f;
        element *prev = NULL;

        while (tmp) {
            if (array[i] < tmp->value) {
                element *new = add_element(prev, array[i]);

                if (!prev) {
                    new->next = f;
                    f = new;
                }
                break;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        if (!tmp)
            add_element(prev, array[i]);
    }
    i = 0;
    while (f) {
        element *tmp = f->next;
        array[i++] = f->value;
        free(f);
        f = tmp;
    }
}