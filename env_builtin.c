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

