#include "shell.h"

/**
 * _write - Custom function for formatted output to stdout.
 *
 * @format: Format string.
 *
 * Return: Number of characters written.
 */
ssize_t _write(const char *format, ...)
{
	va_list args;
	ssize_t n;

	va_start(args, format);
	n = vdprintf(STDOUT_FILENO, format, args);
	va_end(args);

	return (n);
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
void executeCommand(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		char *args[4];
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = command;
		args[3] = NULL;

		if (execve("/bin/sh", args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
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

