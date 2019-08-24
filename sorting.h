#ifndef SORTING_H
#define SORTING_H

#include "edge_data_structs.h"

void edge_list_quick_sort(Edge **edge_list, int start_i, int end_i);
int edge_list_partition(Edge **edge_list, int start_i, int end_i);

#endif
