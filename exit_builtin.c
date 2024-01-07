#include "shell.h"

/**
 * exit_builtin - Implements the exit built-in with arguments.
 *
 * @args: Array of strings containing the arguments.
 */
void exit_builtin(char **args)
{
	if (args[1] != NULL)
	{
		int status = atoi(args[1]);

		_write("Exit with status %d\n", status);
		exit(status);
	}
	else
	{
		_write("Exit built-in\n");
		exit(EXIT_SUCCESS);
	}
}

