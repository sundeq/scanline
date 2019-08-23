#include <stdio.h>
#include "edge_data_structs.h"

void edge_list_quick_sort(Edge **edge_list, int start_i, int end_i);
int edge_list_partition(Edge **edge_list, int start_i, int end_i);

int main(int argc, char **argv) {
    Edge *edge = edge_from_tuples(0, 0, 4, 4);
    printf("Edge y_max: %d, x_min: %f, 1/m: %f\n", edge->y_max, edge->x, edge->inv_m);
}

void edge_list_quick_sort(Edge **edge_list, int start_i, int end_i) {
    int split_i;
    if ( start_i < end_i ) {
        split_i = edge_list_partition(edge_list, start_i, end_i);
        edge_list_quick_sort(edge_list, start_i, split_i - 1);
        edge_list_quick_sort(edge_list, split_i + 1, end_i);
    }
}

int edge_list_partition(Edge **edge_list, int start_i, int end_i) {
    Edge *pivot = edge_list[end_i];
    Edge *temp;
    int i = start_i;
    int j;
    for (j = start_i; j < end_i; j++) {
        if (edge_list[j]->x <= pivot->x) {
            i++;
            temp = init_edge(edge_list[j]->y_max, edge_list[j]->x, edge_list[j]->inv_m);
            edge_list[j] = edge_list[i];
            edge_list[i] = temp;
        }
    }
    temp = init_edge(edge_list[i + 1]->y_max, edge_list[i + 1]->x, edge_list[i + 1]->inv_m);
    edge_list[i + 1] = edge_list[end_i];
    edge_list[end_i] = temp;
    return i;
}
