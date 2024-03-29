#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

int process_arguments(char *input, char **args);
void displayPrompt(int is_interactive);
void readCommand(char *input, int is_interactive);
void executeCommand(char *input);
char **parse_command_with_arguments(char *input);
char *check_command_path(const char *command);
char *get_line(void);
char **parse_command_with_arguments(char *input);
char *allocate_argument(char *start, int len);
int is_delimiter(char c);
char *allocate_argument(char *start, int len);
void exit_builtin(char **args);
extern char **environ;

ssize_t _write(const char *format, ...);
void cd_builtin(char **args);
void semicolon_handler(char *input);
void executeCommand(char *command);
char *trim_whitespace(char *str);

/* Add function declarations for new built-ins */
void env_builtin(void);
void setenv_builtin(char **args);
void unsetenv_builtin(char **args);

#endif /* SHELL_H */

