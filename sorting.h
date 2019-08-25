#ifndef SORTING_H
#define SORTING_H

#include "edge_data_structs.h"

void edges_quick_sort(Edge **edges, int start_i, int end_i);
int edges_partition(Edge **edges, int start_i, int end_i);

#endif
