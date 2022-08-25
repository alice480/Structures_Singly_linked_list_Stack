#include <stdio.h>
#include <time.h>
#include "list.h"
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void add_door_test(struct door* doors);
void remove_door_test(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    add_door_test(doors);
    printf("\n");
    remove_door_test(doors);
    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void add_door_test(struct door* doors) {
    struct door my_door[1];
    my_door[0].id = doors[0].id;
    my_door[0].status = doors[0].status;
    struct node *head;
    head = init(my_door);
    int flag = 1;
    for (int i = 1; i < DOORS_COUNT; i++) {
        my_door[0].id = doors[i].id;
        my_door[0].status = doors[i].status;
        head = add_door(head, my_door);
        flag *= (head->id == doors[i].id && head->status == doors[i].status);
    }
    if (flag)
        printf("SUCCESS");
    else
        printf("FAIL");
    destroy(head);
}

void remove_door_test(struct door* doors) {
    struct door my_door[1];
    my_door[0].id = doors[0].id;
    my_door[0].status = doors[0].status;
    struct node *head, *ptr;
    head = init(my_door);
    for (int i = 1; i < DOORS_COUNT; i++) {
        my_door[0].id = doors[i].id;
        my_door[0].status = doors[i].status;
        head = add_door(head, my_door);
    }
    int flag = 1;
    ptr = find_door(doors[5].id, head);
    ptr = remove_door(ptr, ptr->next);
    flag *= (doors[5].id == ptr->id && doors[5].status == ptr->status &&
            doors[3].id == ptr->next->id && doors[3].status == ptr->next->status);
    if (flag)
        printf("SUCCESS");
    else
        printf("FAIL");
    destroy(head);
}
