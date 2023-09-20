#include "main.h"

#define BUFFSIZE 80

/**
 * parseLine - Tokenize a line of input into an array of strings.
 * @line: The input line to be tokenized.
 *
 * Return: An array of strings representing the tokens.
 */
char **parseLine(char *line)
{
	const char *delim = " :\t\r\n";

	line[strcspn(line, "\n")] = '\0';

	return (tokenizeLine(line, delim));
}

/**
 * tokenizeLine - Tokenize a line using the given delimiter.
 * @line: The input line to be tokenized.
 * @delim: The delimiter to use for tokenization.
 *
 * Return: An array of strings representing the tokens.
 */
char **tokenizeLine(char *line, const char *delim)
{
	int bufsize = BUFFSIZE;
	int index = 0;
	char *token;
	char **args = malloc(bufsize * sizeof(char *));

	if (args == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);

	while (token != NULL)
	{
		args[index] = token;
		index++;

		if (index >= bufsize)
		{
			bufsize += BUFFSIZE;
			args = realloc(args, bufsize * sizeof(char *));
			if (args == NULL)
			{
				fprintf(stderr, "Memory reallocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, delim);
	}

	args[index] = NULL;
	return (args);
}
