#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "some_random.h"

// change these things to change stuff....
int n_monsters = 10;
int n_regions = 3;
int n_trainers = 3;
int min_monst_in_regi = 3;
int max_monst_in_regi = 10;
int min_captures = 3;
int max_captures = 6;
int random_spaces_adverage_spacing = 9; //0 for no random spaces, bigger numbers mean less


int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;

    printf("argv 1 is: %s\n", argv[1]);

    FILE *ofp = fopen(argc > 1 ? argv[1] : "input.txt", "wb");
    srand(time(NULL));

    //print monster data
    fprintf(ofp, "%d monsters\n", n_monsters);
    for (int i = 0; i < n_monsters; i++) {
        random_space(ofp, random_spaces_adverage_spacing);
        fprintf(ofp, "MONST_%d ELEM_%d %d\n", 1 + i, 1 + i % 10, 1 + i % 100);
    }

    //print region data
    fprintf(ofp, "\n%d regions\n", n_regions);
    random_space(ofp, random_spaces_adverage_spacing);
    for (int i = 0; i < n_regions; i++) {
        int monsters_in_region = min_monst_in_regi + (rand() % (1 + max_monst_in_regi - min_monst_in_regi));
        fprintf(ofp, "\nREGI_%d\n", 1 + i);
        random_space(ofp, random_spaces_adverage_spacing);
        fprintf(ofp, "%d monsters\n", monsters_in_region);
        for (int j = 0; j < monsters_in_region; j++) {
            //can end up with more then 1 monster of same type in region, this maybe should change
            int random_1_to_nmonsters = 1 + (rand() % n_monsters);
            fprintf(ofp, "MONST_%d\n", random_1_to_nmonsters);
            random_space(ofp, random_spaces_adverage_spacing);
        }
    }

    //print trainer data
    fprintf(ofp, "\n%d trainers\n", n_trainers);
    random_space(ofp, random_spaces_adverage_spacing);
    for (int i = 0; i < n_trainers; i++) {
        int regions_in_trainer = 1 + (rand() % n_regions);
        random_space(ofp, random_spaces_adverage_spacing);
        fprintf(ofp, "\nTRAIN_%d\n", 1 + i);
        random_space(ofp, random_spaces_adverage_spacing);
        fprintf(ofp, "%d captures\n", min_captures + (rand() % (1 + max_captures - min_captures)));
        random_space(ofp, random_spaces_adverage_spacing);
        fprintf(ofp, "%d regions\n", regions_in_trainer);
        for (int j = 0; j < regions_in_trainer; j++) {
            int seperation = n_regions / regions_in_trainer;
            random_space(ofp, random_spaces_adverage_spacing);
            fprintf(ofp, "REGI_%d\n", 1 + (j * seperation));
        }
    }

    return 0;
}
