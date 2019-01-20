#include <stdio.h>
#include <stdlib.h>

struct t_elem {
    char *val;
    int len;
    struct t_elem *next;
};


void push(struct t_elem **head, char *data);
void printlist(struct t_elem *head);
void freelist(struct t_elem *head);
char *find(struct t_elem *head, char *pattern);
