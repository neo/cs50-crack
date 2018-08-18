#define MAX_LENGTH 5
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lenofchar(int len, char c);
void prev(char **curr, char firstchar);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    char *hash = argv[1];

    int saltlen = 2;
    char *salt = malloc((saltlen + 1) * sizeof(char));
    strncpy(salt, hash, saltlen);
    salt[saltlen] = '\0';

    char *last = lenofchar(MAX_LENGTH + 1, 'A');
    do
    {
        prev(&last, 'A');
        char *testhash = crypt(last, salt);
        if (strcmp(testhash, hash) == 0)
        {
            printf("%s\n", last);
            return 0;
        }
    }
    while (strcmp(last, "A") != 0);

    free(salt);
}

char *lenofchar(int len, char c)
{
    char *result = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        *(result + i) = c;
    }
    *(result + len) = '\0';
    return result;
}

void prev(char **curr, char firstchar)
{
    int len = strlen(*curr);
    char *allAsatlen = lenofchar(len, firstchar);

    if (strcmp(*curr, allAsatlen) == 0)
    {
        *curr = lenofchar(len - 1, 'z');
    }
    else
    {
        char *target = *curr + (len - 1);

        while (*target == firstchar)
        {
            *target = 'z';
            target --;
        }

        if (*target == 'a')
        {
            *target = 'Z';
        }
        else
        {
            *target = *target - 1;
        }
    }

    free(allAsatlen);
}
