#include "splitline.h"
#include "list.h"


void stringoffset(int offset, char **string) {
    int index = 0;

    while (index < offset) {
        (*string)++;
        index++;
    }
}


void splitline(struct t_elem **head, char *string, char *pattern) {
    int error;
    int ngroup = 0;

    regex_t re;
    regmatch_t pm;

    /* Compile pattern */
    (void) regcomp(&re, pattern, REG_EXTENDED);

    while (strlen(string)) {
        error = regexec(&re, string, 1, &pm, 0);
        if (!error) {
            /* Line is only white space */
            if (!pm.rm_so && pm.rm_eo == strlen(string)) {
                break;
            /* Line start with white space */
            } else if (!pm.rm_so) {
                stringoffset(pm.rm_eo, &string);
            /* Line don't start with white space */
            } else {
                push(head, strndup(string, pm.rm_so));
                stringoffset(pm.rm_eo, &string);
                ngroup++;
            }
        /* No white space in line */
        } else if (error == REG_NOMATCH) {
            if (strlen(string) > 0) {
                push(head, string);
                ngroup++;
            }
            break;
        }
    }
}


int main(int argc, char **argv) {
    char *pattern;
    struct t_elem *head = NULL;

    if (argc < 2 || argc > 3) {
        printf(USAGE);
        return -1;
    } else {
        pattern = argc == 3 ? argv[2] : WHITE_SPACES; 
        splitline(&head, argv[1], pattern);
        if (head != NULL) {
            printlist(head);
            /* freelist(head); */
        } else {
            printf("Only white spaces\n");
        }
    }
}
