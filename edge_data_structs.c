#include <stdlib.h>
#include <stdio.h>
#include "edge_data_structs.h"

Edge *edge_from_tuples(int x1, int y1, int x2, int y2) {
    int y_max = y1 > y2 ? y1 : y2;
    int y_min = y1 < y2 ? y1 : y2;
    double x_min = (double) ( x1 <= x2 ? x1 : x2);
    double dy = (double) y2 - y1;
    double dx = (double) x2 - x1;
    double inv_m = 1 / (dy / dx);
    return init_edge(y_max, y_min, x_min, inv_m);
}

Edge *init_edge(int y_max, int y_min, double x_min, double inv_m) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->y_max = y_max;
    edge->y_min = y_min;
    edge->x = x_min;
    edge->inv_m = inv_m;
    return edge;
}

EdgeTable *init_edge_table(int n_buckets) {
    int i;
    EdgeTable *edge_table = (EdgeTable *) malloc(sizeof(EdgeTable));
    EdgeList **buckets = (EdgeList **) malloc(sizeof(EdgeList *) * n_buckets);
    for (i = 0; i < n_buckets; i++) {
        buckets[i] = (EdgeList *) malloc(sizeof(EdgeList));
        buckets[i]->n_edges = 0;
        buckets[i]->list = NULL;
    }
    edge_table->buckets = buckets;
    edge_table->n_buckets = n_buckets;
    return edge_table;
}

void add_to_edge_table(EdgeTable *edge_table, Edge *edge) {
    if (edge->y_min != edge->y_max) {
        EdgeList *bucket = edge_table->buckets[edge->y_min];
        bucket->n_edges++;
        if (bucket->list == NULL) {
            bucket->list = (Edge **) malloc(sizeof(Edge *));
            bucket->list[0] = edge;
        } else {
            bucket->list = (Edge **) realloc(bucket->list, bucket->n_edges * sizeof(Edge *));
            bucket->list[bucket->n_edges - 1] = edge;
        }
        edge_table->buckets[edge->y_min] = bucket;
    }
}

void print_edges(Edge **edges, int n_elems) {
    printf("########## EDGE LIST #################\n");
    for (int i = 0; i < n_elems; i++) {
        printf("List elem %d, ymax: %d, ymin: %d, x: %f, 1/m: %f\n", i, edges[i]->y_max, edges[i]->y_min, edges[i]->x, edges[i]->inv_m);
    }
    printf("######################################\n");
}
