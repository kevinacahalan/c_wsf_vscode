#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "some_random.h"

void random_space(FILE *ofp, int random_spaces_average_spacing) {
    if (!random_spaces_average_spacing) {
        return;
    } else if (!(rand() % random_spaces_average_spacing)) {
        switch (rand() % 6) {
        case 0:
            fprintf(ofp, "\r\r\n");
            break;
        case 1:
            fprintf(ofp, "\r\n\n");
            break;
        case 2:
            fprintf(ofp, "\n\r\n");
            break;
        case 3:
            fprintf(ofp, "\n\r\n");
            break;
        case 4:
            fprintf(ofp, "\n");
            break;
        case 5:
            fprintf(ofp, "\r\n");
            break;

        default:
            break;
        }
    }
}