#ifndef TUXLLS_H
#define TUXLLS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LINE_LIMIT 1024
#define CMD_LIMIT 100

bool TUXLLS_mkdir(char *name_of_dir);
bool TUXLLS_touch(char *filename, char *ext, FILE *ptr_to_file);
void TUXLLS_showDir(char *string);
char *TUXLLS_getDir();
FILE *TUXLLS_fileExists(char *file_w_ext);
char *TUXLLS_readfile();

#endif
