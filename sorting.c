#include "sorting.h"
#include "edge_data_structs.h"

/*
 * Should be called with edges_quick_sort(edges, 0, n_elems - 1)
 * */
void edges_quick_sort(Edge **edges, int start_i, int end_i) {
    int split_i;
    if ( start_i < end_i ) {
        split_i = edges_partition(edges, start_i, end_i);
        edges_quick_sort(edges, start_i, split_i - 1);
        edges_quick_sort(edges, split_i + 1, end_i);
    }
}

int edges_partition(Edge **edges, int start_i, int end_i) {
    Edge *pivot = edges[end_i];
    Edge *temp;
    int i = start_i - 1;
    int j;
    for (j = start_i; j < end_i; j++) {
        if (edges[j]->x <= pivot->x) {
            i++;
            temp = edges[j];
            edges[j] = edges[i];
            edges[i] = temp;
        }
    }
    temp = edges[i + 1];
    edges[i + 1] = edges[end_i];
    edges[end_i] = temp;
    return i + 1;
}
