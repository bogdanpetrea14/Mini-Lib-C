#include <string.h>
#include <stdio.h>
#include <unistd.h>

int puts(const char *string) {
    if (!string)
        return -1;
    while (*string != '\0') {
        write(1, string, 1);
        string++;
    }
    write(1, "\n", 1);

    return 0;
}