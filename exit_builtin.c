#include "shell.h"

/**
 * exit_builtin - Implements the exit built-in, which exits the shell.
 */
void exit_builtin(void)
{
	_write("Exit built-in\n");
	exit(EXIT_SUCCESS);
}
