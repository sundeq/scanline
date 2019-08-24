#include "sorting.h"
#include "edge_data_structs.h"

/*
 * Should be called with edge_list_quick_sort(edge_list, 0, n_elems - 1)
 * */
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
    int i = start_i - 1;
    int j;
    for (j = start_i; j < end_i; j++) {
        if (edge_list[j]->x <= pivot->x) {
            i++;
            temp = edge_list[j];
            edge_list[j] = edge_list[i];
            edge_list[i] = temp;
        }
    }
    temp = edge_list[i + 1];
    edge_list[i + 1] = edge_list[end_i];
    edge_list[end_i] = temp;
    return i + 1;
}
