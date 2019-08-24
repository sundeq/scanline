#include <stdlib.h>
#include <stdio.h>
#include "edge_data_structs.h"

Edge *edge_from_tuples(int x1, int y1, int x2, int y2) {
    int y_max = y1 > y2 ? y1 : y2;
    double x_min = (double) ( x1 <= x2 ? x1 : x2);
    double dy = (double) y2 - y1;
    double dx = (double) x2 - x1;
    double inv_m = 1 / (dy / dx);
    return init_edge(y_max, x_min, inv_m);
}

Edge *init_edge(int y_max, double x_min, double inv_m) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->y_max = y_max;
    edge->x = x_min;
    edge->inv_m = inv_m;
    return edge;
}

EdgeTable *init_edge_table(Edge ***buckets,int n_buckets) {
    EdgeTable *edgeTable = (EdgeTable *) malloc(sizeof(EdgeTable));
    edgeTable->buckets = buckets;
    edgeTable->n_buckets = n_buckets;
    return edgeTable;
}

void print_edge_list(Edge **edge_list, int n_elems) {
    printf("########## EDGE LIST #################\n");
    for (int i = 0; i < n_elems; i++) {
        printf("List elem %d, ym: %d x: %f, 1/m: %f\n", i, edge_list[i]->y_max, edge_list[i]->x, edge_list[i]->inv_m);
    }
    printf("######################################\n");
}
