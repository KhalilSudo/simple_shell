#include "main.h"

/**
 * find_full_path - Find the full path of a command.
 * @args: The arguments of the command.
 * @Path: The search paths.
 *
 * Return: The full path of the command, or NULL if not found.
 */
char *find_full_path(char **args, char **Path)
{
	char *fullpath = NULL;

	if (strchr(args[0], '/') && args[0] != NULL)
	{
		fullpath = strdup(args[0]);
		if (!fullpath)
		{
			perror("Error copying path");
			return (NULL);
		}
	}
	else if (Builtin(args[0]))
	{
		execute_builtin(args[0]);
		free(args);
		return (NULL);
	}
	else
	{
		if (!Path)
		{
			fprintf(stderr, "Unable to retrieve PATH environment variable\n");
			free(args);
			return (NULL);
		}

		fullpath = path_checker(Path, args[0]);

		if (!fullpath)
		{
			free(args);
			exit(98);
		}
	}

	return (fullpath);
}

/**
 * execute_command - Execute a command with the given arguments and full path.
 * @fullpath: The full path of the command.
 * @args: The arguments of the command.
 */
void execute_command(char *fullpath, char **args)
{
	if (fullpath != NULL)
	{
		execution(fullpath, args);
		free(fullpath);
	}
}

/**
 * process_usrcmd - Process a user command.
 * @line: The command line input.
 */
void process_usrcmd(char *line)
{
	char **args = NULL;
	char **Path = NULL;
	char *fullpath = NULL;

	args = parseLine(line);
	if (!args)
		return;

	Path = find_Path();
	fullpath = find_full_path(args, Path);

	execute_command(fullpath, args);
	free(Path);
	free(args);
}
/**
 * handleInput - handleInput of a command.
 * @line: The arguments of the command.
 *
 * Return: void.
 */
void handleInput(char *line)
{
	char *comment = NULL;

	while (isspace(*line))
		line++;

	if (*line == '\0')
	{
		return;
	}

	comment = strchr(line, '#');

	if (comment != NULL)
	{
		*comment = '\0';
	}

	process_usrcmd(line);
}
