#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/tuxlls.h"
bool TUXLLS_mkdir(char *name_of_dir)
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

bool TUXLLS_touch(char *filename, char *ext, FILE *ptr_to_file)
{
    char allname[CMD_LIMIT];
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    sprintf(allname, "%s%s", filename, ext);
}
void TUXLLS_showDir(char *string)
{
    const unsigned int BUFFER_SIZE = 1024;
    char command[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    char result[BUFFER_SIZE];
    strncpy(command, "pwd", sizeof("pwd"));
    FILE *fp = popen(command, "r");
    if (fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
    {
        strncat(result, buffer, BUFFER_SIZE - strlen(result) - 1);
    }
    pclose(fp);
    strncpy(string, result, sizeof(string) - 1);
}
char *TUXLLS_getDir()
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

FILE *TUXLLS_fileExists(char *file_w_ext)
{
    FILE *tmp;
    char output[1024];

    tmp = fopen("r", file_w_ext);

    if (!tmp)
    {
        puts("Tux cannot find your file ;(");
        return NULL;
    }
    return tmp;
}

char *TUXLLS_readfile()
{
    FILE *fp;
    char buffer[1024];

    // Abrir o arquivo para leitura
    fp = fopen("arquivo.txt", "r");

    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Ler e imprimir o conteúdo do arquivo
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }
}
