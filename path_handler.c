#include "shell.h"

/**
 * check_command_path - Check if the command exists in the PATH.
 *
 * @command: The command to check.
 *
 * Return: The full path of the command if it exists, NULL otherwise.
 */
char *check_command_path(const char *command)
{
	char *path = getenv("PATH");
	char *token, *path_entry, *command_path;

	if (path == NULL)
		return NULL;

	token = strtok(path, ":");
	while (token != NULL)
	{
		path_entry = (char *)malloc(strlen(token) + strlen(command) + 2);
		if (path_entry == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(path_entry, token);
		strcat(path_entry, "/");
		strcat(path_entry, command);

		if (access(path_entry, F_OK) == 0)
		{
			command_path = strdup(path_entry);
			free(path_entry);
			return command_path;
		}

		free(path_entry);
		token = strtok(NULL, ":");
	}

	return NULL;
}

