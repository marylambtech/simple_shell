#include "shell.h"

/**
 * exit_builtin - Implements the exit built-in with arguments.
 *
 * @args: Array of strings containing the arguments.
 */
void exit_builtin(char **args)
{
	int status = EXIT_SUCCESS;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
	}

	_write("Exit with status %d\n", status);
	exit(status);
}
