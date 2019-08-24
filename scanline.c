#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "edge_data_structs.h"


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
