#include "shell.h"

/**
 * is_delimiter - Check if a character is a delimiter.
 *
 * @c: The character to check.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delimiter(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * allocate_argument - Allocate memory for a new argument and copy the content.
 *
 * @start: Pointer to the start of the argument.
 * @len: Length of the argument.
 *
 * Return: Pointer to the newly allocated argument.
 */
char *allocate_argument(char *start, int len)
{
	char *arg = (char *)malloc((len + 1) * sizeof(char));

	if (arg == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	strncpy(arg, start, len);
	arg[len] = '\0';
	return (arg);
}

/**
 * process_arguments - Process the input string and extract arguments.
 *
 * @input: Pointer to the input string.
 * @args: Array to store the arguments.
 *
 * Return: Number of arguments processed.
 */
int process_arguments(char *input, char **args)
{
	int i = 0;
	int arg_len = 0;
	int in_arg = 0;

	while (*input != '\0')
	{
		if (is_delimiter(*input))
		{
			if (in_arg)
			{
				args[i++] = allocate_argument(input - arg_len, arg_len);
				in_arg = 0;
				arg_len = 0;
			}
		}
		else
		{
			if (!in_arg)
			{
				in_arg = 1;
			}
			arg_len++;
		}

		input++;
	}

	if (in_arg)
	{
		args[i++] = allocate_argument(input - arg_len, arg_len);
	}

	return (i);
}

