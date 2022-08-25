#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};

struct node* init(int number);
struct node* pop(struct node* head);
struct node* push(int number, struct node* head);
void destroy(struct node* root);

#endif  // SRC_STACK_H_
