#include "splitline.h"


char *new_group(int pos, int len, char *string) {
    char *group;
    int i = 0;

    /* Allocate new group in memory */
    group = (char*) malloc(sizeof(char) * len);
    while (i < len) {
        group[i] = string[i+pos];
        i++;
    }

    return group;
}


char *stringoffset(int offset, char *string) {
    int index = 0;

    while (index < offset) {
        *string++;
        index++;
    }

    return string;
}


void printgroups(char **groups) {
    while (*groups != NULL) {
        printf("%s\n", *groups++);
    }
}


char **pushgroup(char *group, char **groups, int size) {
    /* Dynamic group table */
    if (groups == NULL) {
        groups = (char**) malloc(sizeof(char*) * (size+1));
        groups[0] = group;
        groups[1] = NULL;
    } else {
        groups = (char**) realloc(groups, sizeof(char*) * (size+2));
        groups[size] = group;
        groups[size+1] = NULL;
    }

    return groups;
}

char **splitline(char *string, char *pattern) {
    int error;
    int ngroup;
    char **groups = NULL;
    char *newgroup;

    regex_t re;
    regmatch_t pm;

    ngroup = 0;

    (void) regcomp(&re, pattern, REG_EXTENDED);

    while (strlen(string)) {
        error = regexec(&re, string, 1, &pm, 0);
        if (!error) {
            /* Line is only white space */
            if (!pm.rm_so && pm.rm_eo == strlen(string)) {
                break;
            /* Line start with white space */
            } else if (!pm.rm_so) {
                string = stringoffset(pm.rm_eo, string);
            /* Line don't start with white space */
            } else {
                newgroup = new_group(0, pm.rm_so, string);
                groups = pushgroup(newgroup, groups, ngroup);
                string = stringoffset(pm.rm_eo, string);
                ngroup++;
            }
        /* No white space in line */
        } else if (error == REG_NOMATCH) {
            if (strlen(string) > 0) {
                groups = pushgroup(string, groups, ngroup);
                ngroup++;
            }
            break;
        }
    }

    return groups;
}

int main(int argc, char **argv) {
    char *pattern;
    char **groups;

    if (argc < 2 || argc > 3) {
        printf(USAGE);
        return -1;
    } else {
        pattern = argc == 3 ? argv[2] : WHITE_SPACES; 
        groups = splitline(argv[1], pattern);
        if (groups != NULL) {
            printgroups(groups);
            free(groups);
        } else {
            printf("Only white spaces\n");
        }
    }
}
