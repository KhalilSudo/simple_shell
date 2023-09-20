#include "main.h"

/**
 * Builtin - Check if a command is a built-in command.
 * @command: The command to check.
 *
 * Return: 1 if command is built-in, 0 otherwise.
 */
int Builtin(char *command)
{
	if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * execute_builtin - Execute built-in commands.
 * @command: The built-in command to execute.
 */
void execute_builtin(char *command)
{
	int i;

	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}

	/* Check if the user entered the "env" command */
	if (strcmp(command, "env") == 0)
	{
		/* Print the current environment */
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}
}
