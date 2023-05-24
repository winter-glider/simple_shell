#include "shell.h"

/**
  *execute_action - executes the arguments
  *@args: command line arguments
  *@prog_name: filename (argv[0])
  *Return: nothing
  */

void execute_action(char **args, char *prog_name)
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
			_exit(EXIT_FAILURE);
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
		perror(prog_name);
	}
}

