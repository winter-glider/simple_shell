#include "shell.h"

/**
  *execute_action - executes the arguments
  *@args: command line arguments
  *@prog_name: filename (argv[0])
i  *Return: nothing
  */

void execute_action(char **args, char *prog_name)
{
	char *path = get_builtin_path(args[0]);
	pid_t pid;

	/*
	*if (strncmp(*args, "/", 1) == 0)
		path = strdup(args[0]);
	 */

	if (path != NULL)
	{
		if (args[0] == NULL || args[0][0] == '\0' ||
				strspn(args[0], " ") == strlen(args[0]))
		{
			free(path);
			return;
		}
		pid = fork();
		if (pid == 0)
		{
			/*Child process*/
			execve(args[0], args, NULL);
			perror("execve");
			_exit(EXIT_FAILURE);
		}
		else if (pid > 0)
			waitpid(pid, NULL, 0);
		else
			perror("fork");
		free(path);
	}
	else
		perror(prog_name);
}

