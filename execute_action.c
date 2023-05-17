#include "shell.h"

/**
  *execute_action - executes the arguments
  *@args: command line arguments
  *Return: nothing
  */

void execute_action(char **args)
{
	char *builtin_path = get_builtin_path(*args);
	pid_t pid;

	if (builtin_path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			/*Child process*/
			execve(builtin_path, args, NULL);
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
		free(builtin_path);
	}
	else
	{
		fprintf(stderr, "Command '%s' not found\n", *args);
	}
}
