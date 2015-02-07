#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "algo.h"

typedef struct s_node {
    int value;
    struct s_node *left;
    struct s_node *right;
} node;

node *create_node(int value) {
    node *ret = malloc(sizeof(*ret));

    ret->right = ret->left = NULL;
    ret->value = value;
    return ret;
}

void add_node(node *n, int value) {
    if (value > n->value) {
        if (n->right)
            add_node(n->right, value);
        else {
            n->right = create_node(value);
        }
    } else {
        if (n->left)
            add_node(n->left, value);
        else
            n->left = create_node(value);
    }
}

void recreate_array(int *array, int *i, node **n) {
    if ((*n)->left) {
        recreate_array(array, i, &((*n)->left));
    } else {
        array[(*i)++] = (*n)->value;
    }
    if ((*n)->right) {
        recreate_array(array, i, &((*n)->right));
    }
    free(*n);
}

void tree_sort(int *array, int size) {
    node *head = create_node(array[0]);
    int i = 1;

    while (i < size) {
        add_node(head, array[i++]);
    }
    i = 0;
    recreate_array(array, &i, &head);
}