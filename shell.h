#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int process_arguments(char *input, char **args);
ssize_t _write(const char *str);
void displayPrompt(int is_interactive);
void readCommand(char *input, int is_interactive);
void executeCommand(char *input);
char **parse_command_with_arguments(char *input);
char *check_command_path(const char *command);
void exit_builtin(void);
char *get_line(void);
char **parse_command_with_arguments(char *input);
char *allocate_argument(char *start, int len);
int is_delimiter(char c);
char *allocate_argument(char *start, int len);


/* Add function declarations for new built-ins */
void env_builtin(void);

#endif /* SHELL_H */

