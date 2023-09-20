#include "main.h"

/**
 * interactive - Run the shell in interactive mode.
 * @prompt: The shell prompt.
 */
void interactive(char *prompt)
{
	char *line = NULL;
	size_t length;
	int readStat;

	while (1)
	{
		printf("\n%s ", prompt);
		readStat = getline(&line, &length, stdin);

		if (readStat == -1)
		{
			exit(EXIT_FAILURE);
		}

		handleInput(line);

		free(line);
		line = NULL;
	}
}

/**
 * non_interactive - Run the shell in non-interactive mode.
 * @scriptFile: The script file to read commands from.
 */
void non_interactive(FILE *scriptFile)
{
	char *line = NULL;
	size_t length;
	int readStat;

	while ((readStat = getline(&line, &length, scriptFile)) != -1)
	{
		handleInput(line);
		free(line);
	}

	fclose(scriptFile);
}
