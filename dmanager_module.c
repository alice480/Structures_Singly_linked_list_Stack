#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void struct_sort(struct  door* doors, int first, int last);
void output(struct door* doors);
void change_status(struct door* doors);


int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    struct_sort(doors, 0, DOORS_COUNT);
    change_status(doors);
    output(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void struct_sort(struct  door* doors, int first, int last) {
    if (first < last) {
        int left = first, right = last, middle = doors[(first + last) / 2].id;
        do {
            while (doors[left].id < middle)
                left++;
            while (middle < doors[right].id)
                right--;
            if (left <= right) {
                int buf = doors[left].id;
                doors[left].id = doors[right].id;
                doors[right].id = buf;
                left++;
                right--;
            }
        } while (left <= right);
        struct_sort(doors, first, right);
        struct_sort(doors, left, last);
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        printf("%d %d\n", doors[i].id, doors[i].status);
}

void change_status(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        doors[i].status = 0;
}
