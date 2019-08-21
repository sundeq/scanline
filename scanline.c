#include <stdio.h>
#include "edge_data_structs.h"

int main(int argc, char **argv) {
    Edge *edge = edgeFromTuples(0, 0, 4, 4);
    printf("Edge y_max: %d, x_min: %d, 1/m: %f\n", edge->y_max, edge->x_min, edge->inv_m);
}

