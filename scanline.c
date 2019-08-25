#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include "edge_data_structs.h"


int main(int argc, char **argv) {
    int pixel_mesh_w = 100;
    int pixel_mesh_h = 100;
    int pixel_mesh[pixel_mesh_h][pixel_mesh_w];
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
    int k;
    int lowest_y = -1;
    for(i = 0; i < pixel_mesh_h; i++) {
        if (edge_table->buckets[i] != NULL) {
            lowest_y = i;
            break;
        }
    }


    EdgeList *active_edges = (EdgeList *) malloc(sizeof(EdgeList));
    EdgeList *temp_active_edges;
    active_edges->list = NULL;
    active_edges->n_edges = 0;
    int fill;
    int active_edge;
    int new_n_edges;
    if (lowest_y != -1) {
        for (i = lowest_y; i < pixel_mesh_h; i++) {

            if (edge_table->buckets[i]->list != NULL) {
                new_n_edges = active_edges->n_edges + edge_table->buckets[i]->n_edges;
                active_edges->list = (Edge **) realloc(active_edges->list, new_n_edges * sizeof(Edge *));
                for (j = 0; j < edge_table->buckets[i]->n_edges; j++) {
                    active_edges->list[active_edges->n_edges + j] = edge_table->buckets[i]->list[j];
                }
                active_edges->n_edges = new_n_edges;
                printf("On line %d, added %d to_active_edges. Now has %d active edges\n", i, edge_table->buckets[i]->n_edges, active_edges->n_edges);
                edge_table->buckets[i] = NULL;
            }
            
            edges_quick_sort(active_edges->list, 0, active_edges->n_edges - 1);

            if (active_edges->list != NULL) {
                fill = 0;
                active_edge = 0;
                for (j = 0; j < pixel_mesh_w; j++) {
                    if (active_edge <= active_edges->n_edges - 1 && j == active_edges->list[active_edge]->x) {
                        fill = !fill;
                        active_edge++;
                    }
                    pixel_mesh[i][j] = fill;
                }
            }

            k = 0;
            temp_active_edges = (EdgeList *) malloc(sizeof(EdgeList));
            temp_active_edges->list = NULL;
            temp_active_edges->n_edges = 0;
            for (j = 0; j < active_edges->n_edges; j++) {
                if (active_edges->list[j]->y_max == i) {
                    free(active_edges->list[j]);
                } else {
                    temp_active_edges->n_edges++;
                    temp_active_edges->list = (Edge **) realloc(temp_active_edges->list, temp_active_edges->n_edges * sizeof(Edge *));
                    temp_active_edges->list[k] = active_edges->list[j];
                    temp_active_edges->list[k]->x += temp_active_edges->list[k]->inv_m;
                    k++;
                }
            }
            active_edges = temp_active_edges;



        }

        printf("################### PIXEL MESH #####################\n");
        for (i = 0; i < pixel_mesh_h; i++) {
            printf("r%d:", i);
            for (j= 0; j < pixel_mesh_w; j++) {
                printf("%d", pixel_mesh[i][j]);
            }
            printf("\n");
        }
    }

}
