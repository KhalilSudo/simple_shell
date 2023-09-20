#include "main.h"

/**
 * main - Entry point of the simple shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char **argv)
{
	char *prompt = "$";

	if (argc > 1)
	{
		FILE *scriptFile = fopen(argv[1], "r");

		if (scriptFile == NULL)
		{
			fprintf(stderr, "Failed to open script file: %s\n", argv[1]);
			return (1);
		}

		non_interactive(scriptFile);
	}
	else
	{
		if (!isatty(STDIN_FILENO))
		{
			non_interactive(stdin);
		}
		else
		{
			interactive(prompt);
		}
	}

	return (0);
	}
