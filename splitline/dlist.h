
#define PRINT_REVERSE 1

struct t_delem {
    char *data;
    struct t_delem *next;
    struct t_delem *prev;
};

void printdlist(struct t_delem *elem, int reverse);
void dpush(struct t_delem **head, char *data);
