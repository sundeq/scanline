#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int y_max;
    int x_min;
    double inv_m;
};

typedef struct Edge Edge;

struct EdgeTable {
    Edge ***buckets;
    int n_buckets;
};

typedef struct EdgeTable EdgeTable;

Edge *initEdge(int y_max, int x_min, double inv_m);
EdgeTable *initEdgeTable(Edge ***buckets,int n_buckets);

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

    printf("edge 1 y_max: %d\n", buckets[0][0]->y_max);
    printf("edge 2 y_max: %d\n", buckets[1][0]->y_max);
    printf("edge 3 y_max: %d\n", buckets[1][1]->y_max);
}

Edge *initEdge(int y_max, int x_min, double inv_m) {
    Edge *edge = (Edge *) malloc(sizeof(Edge));
    edge->y_max = y_max;
    edge->x_min = x_min;
    edge->inv_m = inv_m;
    return edge;
}

EdgeTable *initEdgeTable(Edge ***buckets,int n_buckets) {
    
}
