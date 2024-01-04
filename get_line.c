#include "shell.h"

/**
 * get_line - Custom getline function.
 *
 * Return: A string containing the input line.
 */
char *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t index;
	ssize_t bytesRead;
	char *line;

	if (index >= BUFFER_SIZE || index == 0)
	{
		index = 0;
		bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytesRead <= 0)
		return (NULL);
	}

	line = &buffer[index];

	while (index < BUFFER_SIZE && buffer[index] != '\n')
		index++;

	if (index < BUFFER_SIZE && buffer[index] == '\n')
	{
		buffer[index] = '\0';
		index++;
	}

	return (line);
}

