#include "shell.h"

/**
 * parse_command_with_arguments - Parse the input command and its arguments.
 *
 * @input: The command with arguments to be parsed.
 *
 * Return: An array of strings containing the command and its arguments.
 */
char **parse_command_with_arguments(char *input)
{
	char **args;
	char *token;
	int i = 0;

	args = (char **)malloc(BUFFER_SIZE * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (token = strtok(input, " "); token != NULL && i < BUFFER_SIZE - 1; token = strtok(NULL, " "))
	{
		args[i++] = strdup(token);
	}

	args[i] = NULL;

	return args;
}

