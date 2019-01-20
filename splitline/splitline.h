

#include <stdlib.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>
#include "dlist.h"

#define USAGE \
    "                  _ _ _   _ _\n" \
    "        ___ _ __ | (_) |_| (_)_ __   ___\n" \
    "       / __| '_ \\| | | __| | | '_ \\ / _ \\\n" \
    "       \\__ \\ |_) | | | |_| | | | | |  __/\n" \
    "       |___/ .__/|_|_|\\__|_|_|_| |_|\\___|\n" \
    "           |_|\n" \
    "\n" \
    " ++ Usage: \n" \
    "    ./splitline <string> <pattern>\n" \
    "    Output all the words from the string separate by <pattern>\n"

// #define WHITE_SPACES "[ \t]+"
#define WHITE_SPACES "[ \t]+"

void stringoffset(int offset, char **string);
void splitline(struct t_delem **head, char *string, char *pattern);
