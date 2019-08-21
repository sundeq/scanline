#ifndef EDGE_DATA_STRUCTS_H
#define EDGE_DATA_STRUCTS_H

typedef struct Edge Edge;
typedef struct EdgeTable EdgeTable;

struct Edge {
    int y_max;
    int x_min;
    double inv_m;
};


struct EdgeTable {
    Edge ***buckets;
    int n_buckets;
};

Edge *edgeFromTuples(int x1, int y1, int x2, int y2);
Edge *initEdge(int y_max, int x_min, double inv_m);
EdgeTable *initEdgeTable(Edge ***buckets,int n_buckets);

#endif
