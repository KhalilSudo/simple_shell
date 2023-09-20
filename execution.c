#include "main.h"

/**
 * execution - Execute a command using the execve system call.
 * @pathcmd: The full path to the executable.
 * @args: An array of strings representing the command and its arguments.
 */
void execution(char *pathcmd, char **args)
{
	pid_t child_pid;
	int readstat = 0;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
	}

	if (child_pid == 0)
	{
		execve(pathcmd, args, env);
		perror("execve");
		free(args);
		exit(127);
	}
	else
	{
		wait(&readstat);
	}
}
