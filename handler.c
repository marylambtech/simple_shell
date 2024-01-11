#include "shell.h"

/**
 * semicolon_handler - Handle commands separated by semicolons.
 *
 * @input: The input string containing commands separated by semicolons.
 */
void semicolon_handler(char *input)
{
        char *token;
        char *saveptr;

        token = strtok_r(input, ";", &saveptr);

        while (token != NULL)
        {
                char *trimmed_command = trim_whitespace(token);

                if (trimmed_command[0] != '\0')
                {
                        executeCommand(trimmed_command);
                }

                token = strtok_r(NULL, ";", &saveptr);
        }
}

/**
 * Trim leading and trailing whitespaces from a string.
 *
 * @param str: The input string.
 * @return: A new string with leading and trailing whitespaces removed.
 */
char *trim_whitespace(char *str)
{
	char *end;


	while (*str && (*str == ' ' || *str == '\t'))
	{
		str++;
	}


	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
	{
		end--;
	}

	*(end + 1) = '\0';

	return (str);
}


