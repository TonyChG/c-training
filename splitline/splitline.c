#include "splitline.h"


void stringoffset(int offset, char **string) {
    int index = 0;

    while (index < offset) {
        (*string)++;
        index++;
    }
}


int splitline(struct t_delem **head, char *string, char *pattern) {
    int error;
    int ngroup = 0;

    regex_t re;
    regmatch_t pm;

    /* Compile pattern */
    (void) regcomp(&re, pattern, REG_EXTENDED);

    if (!strlen(string)) {
        printf("No input data\n");
        return -1;
    }
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
                dpush(head, strndup(string, pm.rm_so));
                stringoffset(pm.rm_eo, &string);
                ngroup++;
            }
        /* No white space in line */
        } else if (error == REG_NOMATCH) {
            if (strlen(string) > 0) {
                dpush(head, string);
                ngroup++;
            }
            break;
        }
    }
    return 0;
}


int main(int argc, char **argv) {
    char *pattern;
    int status;
    struct t_delem *head = NULL;

    if (argc < 2 || argc > 3) {
        printf(USAGE);
        return -1;
    } else {
        pattern = argc == 3 ? argv[2] : WHITE_SPACES; 
        status = splitline(&head, argv[1], pattern);
        if (status != -1) {
            if (head != NULL) {
                printdlist(head, PRINT_REVERSE);
            } else {
                printf("Only white spaces\n");
            }
        } else {
            printf(USAGE);
            return 0;
        }
    }
}
