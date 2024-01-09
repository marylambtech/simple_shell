#include "shell.h"

/**
 * env_builtin - Execute the env built-in.
 */
void env_builtin(void)
{
	extern char **environ;
	int i = 0;

	while (environ[i] != NULL)
	{
		_write(environ[i]);
		_write("\n");
		i++;
	}
}

/**
 * setenv_builtin - Implements the setenv built-in command.
 *
 * @args: Array of arguments passed to the command.
 */
void setenv_builtin(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		_write("Usage: setenv VARIABLE VALUE\n");
		return;
	}

	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * unsetenv_builtin - Implements the unsetenv built-in command.
 *
 * @args: Array of arguments passed to the command.
 */
void unsetenv_builtin(char **args)
{
	if (args[1] == NULL)
	{
		_write("Usage: unsetenv VARIABLE\n");
		return;
	}

	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
	}
}
