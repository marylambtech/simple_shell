#include "shell.h"

/**
 * cd_builtin - Implements the cd built-in command.
 *
 * @args: Array of arguments passed to the command.
 */
void cd_builtin(char **args)
{
	char *new_directory;

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		new_directory = getenv("HOME");
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_directory = getenv("OLDPWD");
	}
	else
	{
		new_directory = args[1];
	}

	if (chdir(new_directory) != 0)
	{
		perror("cd");
	}
	else
	{
		char current_directory[BUFFER_SIZE];

		getcwd(current_directory, sizeof(current_directory));

		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", current_directory, 1);
	}
}

