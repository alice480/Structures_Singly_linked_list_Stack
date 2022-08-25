#include "list.h"
#include <stdio.h>

struct node* init(struct door* door) {
    struct node *head = malloc(sizeof(struct node));
    head->id = door->id;
    head->status = door->status;
    head->next = NULL;
    return head;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->id = door->id;
    new_node->status = door->status;
    new_node->next = elem;
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    while (root->id != door_id && root != NULL) {
        root = root->next;
    }
    return root;
}

struct node* remove_door(struct node* elem, struct node* root) {
    elem->next = root->next;
    free(root);
    return elem;
}

void destroy(struct node* root) {
    while (root) {
        struct node *ptr;
        ptr = root;
        root = root->next;
        free(ptr);
    }
}
