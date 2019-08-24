#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "edge_data_structs.h"


int main(int argc, char **argv) {
    int pixel_mesh_w = 100;
    int pixel_mesh_h = 100;
    int pixel_mesh[pixel_mesh_w][pixel_mesh_h];
    Edge *edge1 = edge_from_tuples(25, 25, 75, 75);
    Edge *edge2 = edge_from_tuples(75, 75, 25, 75);
    Edge *edge3 = edge_from_tuples(25, 75, 25, 25);

    EdgeTable *edge_table = init_edge_table(n_buckets);
    add_to_edge_table(edge_table, edge1);
    add_to_edge_table(edge_table, edge2);
    add_to_edge_table(edge_table, edge3);
    EdgeList *edge_list25 = edge_table->buckets[edge1->y_min];
    EdgeList *edge_list75 = edge_table->buckets[edge2->y_min];
    print_edge_list(edge_list25->list, edge_list25->n_edges);
    print_edge_list(edge_list75->list, edge_list75->n_edges);
}
