#include <stdlib.h>
#include "edge_data_structs.h"

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
