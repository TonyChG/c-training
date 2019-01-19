
#include "memtest.h"

#define LOWER_ALPHA "abcdefghijklmnopqrstuvwxyz"
#define UPPER_ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"

/* char *new_word(size) { */
/* } */

int main(int argc, char **argv) {
    char *charset;

    charset = strdup(LOWER_ALPHA);
    /* strcat(charset, UPPER_ALPHA); */
    printf("%s\n", charset);
    return (0);
}
