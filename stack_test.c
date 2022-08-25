#include <stdio.h>
#include "stack.h"

void push_test();
void pop_test();

int main() {
    push_test();
    printf("\n");
    pop_test();
    return 0;
}

void push_test() {
    struct node *head;
    head = init(5);
    int flag = 1;
    head = push(2, head);
    flag *= (head->number == 2);
    head = push(3, head);
    flag *= (head->number == 3 && head->next->number == 2);
    if (flag)
        printf("SUCCESS");
    else
        printf("FAIL");
    destroy(head);
}

void pop_test() {
    struct node *head;
    head = init(5);
    int flag = 1;
    head = push(4, head);
    head = push(6, head);
    head = push(7, head);
    head = pop(head);
    flag *= (head->number == 6);
    head = pop(head);
    flag *= (head->number == 4);
    if (flag)
        printf("SUCCESS");
    else
        printf("FAIL");
    destroy(head);
}
