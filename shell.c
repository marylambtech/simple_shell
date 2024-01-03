#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _write - Custom write function to replace printf.
 *
 * @str: String to be written.
 *
 * Return: Number of bytes written.
 */
ssize_t _write(const char *str)
{
	return (write(STDOUT_FILENO, str, strlen(str)));
}

/**
 * displayPrompt - Displays the shell prompt if running in interactive mode.
 *
 * @is_interactive: Flag indicating whether the shell is in interactive mode.
 */
void displayPrompt(int is_interactive)
{
	if (is_interactive)
		_write("#Paul&Mariam$ ");
}

/**
 * readCommand - Reads a command from the user.
 *
 * @input: Buffer to store the user input.
 * @is_interactive: Flag indicating whether the shell is in interactive mode.
 */
void readCommand(char *input, int is_interactive)
{
	if (fgets(input, BUFFER_SIZE, stdin) == NULL)
	{
		if (is_interactive)
			_write("\n");
		exit(EXIT_SUCCESS);
	}

	input[strcspn(input, "\n")] = '\0';
}

/**
 * executeCommand - Executes the given command in a child process.
 *
 * @input: The command to be executed.
 */
void executeCommand(char *input)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execlp(input, input, NULL) == -1)
		{
			perror("execlp");
				_write("Command not found\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - Simple shell program.
 *
 * Description: This program creates a simple shell that prompts the user
 * for commands and executes them in child processes.
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[BUFFER_SIZE];
	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		displayPrompt(is_interactive);
		readCommand(input, is_interactive);

		if (strcmp(input, "exit") == 0)
		{
			break;
		}

		executeCommand(input);
	}

	return (0);
}

