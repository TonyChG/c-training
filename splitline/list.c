#include "list.h"


void push(struct t_elem **head, char *data) {
    struct t_elem *newnode;
    struct t_elem *tmp;

    tmp = *head;
    newnode = malloc(sizeof(struct t_elem));

    newnode->val = data;
    newnode->next = *head;

    if (*head != NULL) {
        while (tmp->next != *head) {
            tmp = tmp->next;
        }
        tmp->next = newnode;
    } else {
        newnode->next = newnode;
    }

    *head = newnode;
}


void printlist(struct t_elem *head) {
    struct t_elem *tmp;
    
    tmp = head;
    if (head != NULL) {
        do {
            printf("%s\n", tmp->val);
            tmp = tmp->next;
        } while (tmp != head);
    }
}


void freelist(struct t_elem *head) {
    struct t_elem *tmp;
    struct t_elem *next_elem;

    tmp = head;

    while (tmp->next != head) {
        free(tmp->val);
        next_elem = tmp->next;
        free(tmp);
        tmp = next_elem;
    }
}


char *find(struct t_elem *head, char *pattern) {
    struct t_elem *tmp;
    char *match = NULL;

    tmp = head;

    while (tmp->next != head) {
        /* TODO: Find a pattern */
        tmp = tmp->next;
    }

    return match;
}
