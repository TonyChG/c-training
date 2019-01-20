#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dlist.h"


void dpush(struct t_delem **head, char *data) {
    struct t_delem *new_elem = (struct t_delem*) malloc(sizeof(struct t_delem));

    new_elem->data = strdup(data);
    new_elem->next = (*head);
    new_elem->prev = NULL;

    if ((*head) != NULL)
        (*head)->prev = new_elem;
    (*head) = new_elem;
}

void printdlist(struct t_delem *elem, int reverse) {
    struct t_delem *last;

    while (elem != NULL) {
        if (!reverse) {
            printf("%s\n", elem->data);
        }
        last = elem;
        elem = elem->next;
    }

    while (last != NULL) {
        if (!reverse) break;
        printf("%s\n", last->data);
        last = last->prev;
    }
}

/* int main(int argc, char **argv) { */
/*     struct t_elem *head = NULL; */
/*  */
/*     push(&head, "titi"); */
/*     push(&head, "tutu"); */
/*     push(&head, "tata"); */
/*     printdlist(head, 0); */
/*     printdlist(head, PRINT_REVERSE); */
/*     return (0); */
/* } */
