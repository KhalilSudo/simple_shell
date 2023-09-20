#include "main.h"

/**
 * find_Path - Get the PATH environment variable and tokenize it.
 *
 * Return: An array of strings representing the directories in the PATH.
 */
char **find_Path(void)
{
	char *paths = getenv("PATH");

	char **path_token = NULL;

	if (paths == NULL)
	{
		return (NULL);
	}

	path_token = parseLine(paths);

	return (path_token);
}

/**
 * appendExecutableToPath - Append an executable name to a directory path.
 * @path: The directory path.
 * @executableName: The name of the executable to append.
 *
 * Return: The concatenated path.
 */
char *appendExecutableToPath(const char *path, const char *executableName)
{
	size_t pathLen = strlen(path);
	size_t execNameLen = strlen(executableName);

	/* Allocate memory for the new string */
	char *newPath = malloc((pathLen + execNameLen + 2) * sizeof(char));

	if (newPath == NULL)
	{
		perror("Error allocating memory");
		return (NULL);
	}

	/* Copy the directory path */
	strcpy(newPath, path);

	/* Append a path separator if necessary */
	if (newPath[pathLen - 1] != '/')
	{
		strcat(newPath, "/");
	}

	/* Append the executable name */
	strcat(newPath, executableName);

	return (newPath);
}

/**
 * path_checker - Check each path for the existence of an executable.
 * @path: Array of strings representing the directories in the PATH.
 * @executableName: The name of the executable to find.
 *
 * Return: The full path to the executable, or NULL if not found.
 */
char *path_checker(char **path, const char *executableName)
{
	int i = 0;
	char *output = NULL;

	while (path[i])
	{
		output = appendExecutableToPath(path[i], executableName);
		if (output == NULL)
		{
			return (NULL); /* Memory allocation error */
		}

		if (access(output, F_OK | X_OK) == 0)
		{
			return (output); /* Return the full path if executable found */
		}

		free(output);
		i++;
	}

	return (NULL); /* Return NULL if not found in any path */
}
