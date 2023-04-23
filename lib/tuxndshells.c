#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./tuxndshells.h"

#if __linux__
#define createDirectory(dirname) \
    do { \
        char cmd[100]; \
        sprintf(cmd, "mkdir %s", dirname); \
        system(cmd); \
    } while(0)
#define createFile(filename)\
    do{ \
        char cmd[100]; \
        sprintf(cmd, "touch %s",dirname); \
        system(cmd); \
    }   \
    while(0)

#define showDirectory(string) \
    const unsigned int BUFFER_SIZE = 1024; \
    char command[BUFFER_SIZE]; \
    char buffer[BUFFER_SIZE]; \
    char result[BUFFER_SIZE]; \
    strncpy(command,"pwd",sizeof("pwd"));    \
    FILE* fp = popen(command, "r"); \
    if (fp == NULL) { \
        printf("Failed to run command\n"); \
        exit(1); \
    } \
    \
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) { \
        strncat(result, buffer, BUFFER_SIZE - strlen(result) - 1); \
    } \
    pclose(fp); \
    strncpy(string, result,sizeof(string) - 1); \

#endif
        

int main(void){
    char string[100];
    memset(string, 0, sizeof(string));
    showDirectory(string);
    printf("%s\n", string);
}