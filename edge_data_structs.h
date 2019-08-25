#ifndef EDGE_DATA_STRUCTS_H
#define EDGE_DATA_STRUCTS_H

typedef struct Edge Edge;
typedef struct EdgeList EdgeList;
typedef struct EdgeTable EdgeTable;

struct Edge {
    int y_max;
    int y_min;
    double x;
    double inv_m;
};

struct EdgeList {
    Edge **list;
    int n_edges;
};

struct EdgeTable {
    EdgeList **buckets;
    int n_buckets;
};

Edge *edge_from_tuples(int x1, int y1, int x2, int y2);
Edge *init_edge(int y_max, int y_min, double x_min, double inv_m);
EdgeTable *init_edge_table(int n_buckets);
void add_to_edge_table(EdgeTable *edge_table, Edge *edge);
void print_edges(Edge **edges, int n_elems);

#endif
