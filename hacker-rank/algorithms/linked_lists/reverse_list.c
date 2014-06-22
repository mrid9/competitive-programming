#include <stdio.h>
#include <stdlib.h>

/* Source: HackerRank
   Reverse a linked list */

typedef struct list {
    int key;
    struct list *next;
} list;


void append_to_tail(list **root, int item) {
    
    list *new_node = malloc(sizeof(list));
    list *p = *root;
    
    new_node->key = item;
    new_node->next = NULL;
    
    if (*root == NULL)
        *root = new_node;
    else {
        while (p->next)
            p = p->next;
        p->next = new_node;
    }
}

void print(list *head) {
    
    if (head) {
        printf("%d ", head->key);
        print(head->next);
    }
}

void reverse(list **head) {
    
    list *prev = NULL, *cur = (*head), *temp;
    
    while (cur) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    *head = prev;
}

int main() {
    
    list *x = NULL;
    
    append_to_tail(&x, 1);
    append_to_tail(&x, 2);
    append_to_tail(&x, 3);
    append_to_tail(&x, 4);
    append_to_tail(&x, 5);
    
    print(x);
    printf("\n");
    
    reverse(&x);
    
    print(x);
    printf("\n");

    
    return 0;
}