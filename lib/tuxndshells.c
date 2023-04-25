#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./tuxndshells.h"

#define LINE_LIMIT 1024
#define CMD_LIMIT 100

#if __linux__

bool create_directory(char *name_of_dir)
{
    char command_line[CMD_LIMIT];
    bool result;

    if (name_of_dir != NULL)
    {
        setbuf(stdin, NULL);
        setbuf(stdout, NULL);
        sprintf(command_line, "mkdir %s", name_of_dir);
        result = system(command_line);
        return result;
    }

    return false;
}

bool create_file(char *filename, char *ext, FILE *ptr_to_file)
{
    char allname[CMD_LIMIT];
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    sprintf(allname, "%s%s", filename, ext);
}
#define showDirectory(string)                                      \
    const unsigned int BUFFER_SIZE = 1024;                         \
    char command[BUFFER_SIZE];                                     \
    char buffer[BUFFER_SIZE];                                      \
    char result[BUFFER_SIZE];                                      \
    strncpy(command, "pwd", sizeof("pwd"));                        \
    FILE *fp = popen(command, "r");                                \
    if (fp == NULL)                                                \
    {                                                              \
        printf("Failed to run command\n");                         \
        exit(1);                                                   \
    }                                                              \
                                                                   \
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL)                 \
    {                                                              \
        strncat(result, buffer, BUFFER_SIZE - strlen(result) - 1); \
    }                                                              \
    pclose(fp);                                                    \
    strncpy(string, result, sizeof(string) - 1);

char *get_directory()
{
    char aux_buf[LINE_LIMIT];
    system("pwd >> dir.tmp");
    FILE *tmp = fopen("dir.tmp", "r");

    if (!tmp)
    {
        puts("Couldn't open dir.tmp!");
    }
    else
    {
        char *ptr_to_buf = &aux_buf[0];
        while (fgets(aux_buf, LINE_LIMIT, tmp) != EOF)
        {
            puts(ptr_to_buf);
            printf("\n%c", ptr_to_buf[sizeof(ptr_to_buf)]);
        }
    }
}

#endif

int main(void)
{
    char string[100];
    memset(string, 0, sizeof(string));
    showDirectory(string);
    printf("%s\n", string);
}