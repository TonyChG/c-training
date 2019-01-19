#include <stdlib.h>
#include <stdio.h>
#include <regex.h>


int search_pattern(const char *regex, const char *line) {
    regex_t re;
    int status;


    if (regcomp(&re, regex, REG_EXTENDED) != 0)
        return 0;
    status = regexec(&re, line, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0)
        return 0;
    return 1;
}


int readlines(const char *pattern, const char *filepath) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t nmatch = 0;
    ssize_t read;

    fp = fopen(filepath, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        /* printf("Réception d'une ligne de longueur %zu :\n", read); */

        if (search_pattern(pattern, line) != 0)
            printf("%s", line);
    }
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}


int readfile(const char *filepath) {
    FILE *fp = NULL;
    char ch;

    fp = fopen(filepath, "r");

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}


int main(int argc, char **argv) {
    if (argc == 3) {
        /* const char *regex = argv[1]; */
        /* const char *filepath = argv[2]; */

        printf("Pattern: %s\n", argv[1]);
        printf("File: %s\n", argv[2]);

        /* readfile(argv[2]); */
        readlines(argv[1], argv[2]);
        /* search_pattern(regex, ); */
    } else {
        printf("Usage: %s <pattern> <filepath>\n", argv[0]);
    }
    return 0;
}
