#include <stdio.h>
#include <stdlib.h>
#include "edge_data_structs.h"

int main(int argc, char **argv) {
    Edge *edge1 = initEdge(10, 0, 1);
    Edge *edge2 = initEdge(50, 10, -1);
    Edge *edge3 = initEdge(100, 20, 1);

    int n_buckets = 2;
    Edge ***buckets = (Edge ***) malloc(n_buckets * sizeof(Edge **));
    buckets[0] = (Edge **) malloc(1 * sizeof(Edge *));
    buckets[0][0] = edge1;
    buckets[1] = (Edge **) malloc(2 * sizeof(Edge *));
    buckets[1][0] = edge2;
    buckets[1][1] = edge3;
    EdgeTable *edgeTable = initEdgeTable(buckets, n_buckets);

    printf("edge 1 y_max: %d\n", edgeTable->buckets[0][0]->y_max);
    printf("edge 2 y_max: %d\n", edgeTable->buckets[1][0]->y_max);
    printf("edge 3 y_max: %d\n", edgeTable->buckets[1][1]->y_max);
}

