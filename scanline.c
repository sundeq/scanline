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

    int n_buckets = pixel_mesh_h;
    EdgeTable *edge_table = init_edge_table(n_buckets);
    add_to_edge_table(edge_table, edge1);
    add_to_edge_table(edge_table, edge2);
    add_to_edge_table(edge_table, edge3);
    EdgeList *edges25 = edge_table->buckets[edge1->y_min];
    EdgeList *edges75 = edge_table->buckets[edge2->y_min];

    int i;
    int j;
    int lowest_y = -1;
    for(i = 0; i < pixel_mesh_h; i++) {
        if (edge_table->buckets[i] != NULL) {
            lowest_y = i;
            break;
        }
    }

    EdgeList *active_edges = (EdgeList *) malloc(sizeof(EdgeList));
    active_edges->list = NULL;
    active_edges->n_edges = 0;
    int new_n_edges;
    if (lowest_y != -1) {
        for(i = lowest_y; i < pixel_mesh_h; i++) {
            if (edge_table->buckets[i]->list != NULL) {
                new_n_edges = active_edges->n_edges + edge_table->buckets[i]->n_edges;
                active_edges->list = (Edge **) realloc(active_edges->list, new_n_edges * sizeof(Edge *));
                for(j = 0; j < edge_table->buckets[i]->n_edges; j++) {
                    active_edges->list[active_edges->n_edges + j] = edge_table->buckets[i]->list[j];
                }
                active_edges->n_edges = new_n_edges;
                printf("On line %d, added %d to_active_edges. Now has %d active edges\n", i, edge_table->buckets[i]->n_edges, active_edges->n_edges);
                print_edges(active_edges->list, active_edges->n_edges);
                edge_table->buckets[i] = NULL;
            }
            edges_quick_sort(active_edges->list, 0, active_edges->n_edges - 1);
        }
    }
}
