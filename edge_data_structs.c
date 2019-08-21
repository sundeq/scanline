#include <stdlib.h>
#include <stdio.h>
#include "edge_data_structs.h"

Edge *edgeFromTuples(int x1, int y1, int x2, int y2) {
    int y_max = y1 > y2 ? y1 : y2;
    int x_min = x1 <= x2 ? x1 : x2;
    double dy = (double) y2 - y1;
    double dx = (double) x2 - x1;
    double inv_m = 1 / (dy / dx);
    return initEdge(y_max, x_min, inv_m);
}

Edge *initEdge(int y_max, int x_min, double inv_m) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->y_max = y_max;
    edge->x_min = x_min;
    edge->inv_m = inv_m;
    return edge;
}

EdgeTable *initEdgeTable(Edge ***buckets,int n_buckets) {
    EdgeTable *edgeTable = (EdgeTable *) malloc(sizeof(EdgeTable));
    edgeTable->buckets = buckets;
    edgeTable->n_buckets = n_buckets;
    return edgeTable;
}
