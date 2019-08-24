#include <stdio.h>
#include <stdlib.h>
#include "edge_data_structs.h"

void edge_list_quick_sort(Edge **edge_list, int start_i, int end_i);
int edge_list_partition(Edge **edge_list, int start_i, int end_i);
void print_edge_list(Edge **edge_list, int n_elems);

int main(int argc, char **argv) {
    Edge *edge = edge_from_tuples(0, 0, 4, 4);
    printf("Edge y_max: %d, x_min: %f, 1/m: %f\n", edge->y_max, edge->x, edge->inv_m);
    int n_elems = 8;
    Edge **edge_list = (Edge **) malloc(n_elems * sizeof(Edge));
    edge_list[0] = edge_from_tuples(1, 1, 100, 1);
    edge_list[1] = edge_from_tuples(22, 1, 100, 1);
    edge_list[2] = edge_from_tuples(4, 1, 100, 1);
    edge_list[3] = edge_from_tuples(3, 1, 100, 1);
    edge_list[4] = edge_from_tuples(3, 1, 100, 1);
    edge_list[5] = edge_from_tuples(4, 1, 100, 1);
    edge_list[6] = edge_from_tuples(11, 1, 100, 1);
    edge_list[7] = edge_from_tuples(2, 1, 100, 1);
    printf("Before qsort\n");
    print_edge_list(edge_list, n_elems);
    printf("After qsort\n");
    edge_list_quick_sort(edge_list, 0, n_elems - 1);
    print_edge_list(edge_list, n_elems);
}

/*
 * Should be called with edge_list_quick_sort(edge_list, 0, n_elems - 1)
 * */
void edge_list_quick_sort(Edge **edge_list, int start_i, int end_i) {
    int split_i;
    if ( start_i < end_i ) {
        split_i = edge_list_partition(edge_list, start_i, end_i);
        edge_list_quick_sort(edge_list, start_i, split_i - 1);
        edge_list_quick_sort(edge_list, split_i + 1, end_i);
    }
}

int edge_list_partition(Edge **edge_list, int start_i, int end_i) {
    printf("elp si: %d ei: %d\n", start_i, end_i);
    Edge *pivot = edge_list[end_i];
    Edge *temp;
    int i = start_i - 1;
    int j;
    for (j = start_i; j < end_i; j++) {
        if (edge_list[j]->x <= pivot->x) {
            i++;
            temp = edge_list[j];
            edge_list[j] = edge_list[i];
            edge_list[i] = temp;
        }
    }
    temp = edge_list[i + 1];
    edge_list[i + 1] = edge_list[end_i];
    edge_list[end_i] = temp;
    return i + 1;
}

void print_edge_list(Edge **edge_list, int n_elems) {
    printf("########## EDGE LIST #################\n");
    for (int i = 0; i < n_elems; i++) {
        printf("List elem %d, ym: %d x: %f, 1/m: %f\n", i, edge_list[i]->y_max, edge_list[i]->x, edge_list[i]->inv_m);
    }
    printf("######################################\n");
}
