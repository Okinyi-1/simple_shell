#ifndef SHELL_H
#define SHELL_H

/* Import libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
/* Prototypes */
void display_prompt(void);
void execute_command(char *command, char **args, char **env);
void read_command(char *command);
void run_shell(void);
void exit_shell(void);
void print_environment(void);
char *path_lookup(const char *command);
/* global environ path declaration */
extern char **environ;

#endif
