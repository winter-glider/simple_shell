#include "shell.h"

/**
  *execute_action - executes the arguments
  *@args: command line arguments
  *Return: nothing
  */

void execute_action(char **args)
{
	char *path = get_builtin_path(*args);
	pid_t pid;

	if (_strncmp(*args, "/", 1) == 0)
		path = strdup(args[0]);

	if (path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			/*Child process*/
			execve(path, args, NULL);
			perror("execve");
			_exit(1);
		}
		else if (pid > 0)
		{
			/* Parent process*/
			waitpid(pid, NULL, 0);
		}
		else
		{
			/*Error forking*/
			perror("fork");
		}
		free(path);
	}
	else
	{
		fprint("Command '%s' not found\n", STDERR_FILENO, *args);
	}
}

