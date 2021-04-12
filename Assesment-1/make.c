#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        return 0;
    }

    char *filename = argv[1];

    char command[50] = "";

    strcat(command, "gcc ");
    strcat(command, filename);
    strcat(command, ".c -o ");
    strcat(command, filename);
    strcat(command, " && ");
    strcat(command, filename);

    printf("=> %s\n\n", command);
    system(command);

    return 0;
}