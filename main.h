#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ctype.h>
extern char **environ;

#define INITIAL_BUF_SIZE 1024
#define BUF_SIZE_INCREMENT 1024

char **parseLine(char *line);
char *path_checker(char **path, const char *exename);
char *appendExecutableToPath(const char *path, const char *executableName);
char **find_Path(void);
void execution(char *pathcmd, char **args);
void process_usrcmd(char *line);
char **tokenizeLine(char *line, const char *delim);
void execute_builtin(char *command);
int Builtin(char *command);
void non_interactive(FILE *scriptFile);
void interactive(char *prompt);
char *find_full_path(char **args, char **Path);
void execute_command(char *fullpath, char **args);
void process_usrcmd(char *line);
void handleInput(char *line); 



#endif /* MAIN_H */
