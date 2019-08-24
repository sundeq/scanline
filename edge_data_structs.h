#ifndef EDGE_DATA_STRUCTS_H
#define EDGE_DATA_STRUCTS_H

typedef struct Edge Edge;
typedef struct EdgeTable EdgeTable;

struct Edge {
    int y_max;
    double x;
    double inv_m;
};


struct EdgeTable {
    Edge ***buckets;
    int n_buckets;
};

Edge *edge_from_tuples(int x1, int y1, int x2, int y2);
Edge *init_edge(int y_max, double x_min, double inv_m);
EdgeTable *init_edge_table(Edge ***buckets,int n_buckets);
void print_edge_list(Edge **edge_list, int n_elems);

#endif
