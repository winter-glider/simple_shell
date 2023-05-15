#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUM_ARGS 10

// Signal handler for SIGINT (CTRL-C)
void sigint_handler(int signum) {
    printf("\n");  // Print newline after CTRL-C
    fflush(stdout);  // Flush output to ensure prompt is printed on new line
}

// Split command string into individual arguments
void split_command(char* command, char** args, int* num_args) {
    *num_args = 0;
    args[*num_args] = strtok(command, " ");
    while (args[*num_args] != NULL) {
        (*num_args)++;
        args[*num_args] = strtok(NULL, " ");
    }
}

// Redirect standard input or output to/from a file
int redirect(char* filename, int direction) {
    int fd;
    if (direction == 0) {
        // Redirect standard input from file
        fd = open(filename, O_RDONLY);
        if (fd == -1) {
            perror("open");
            return -1;
        }
        dup2(fd, STDIN_FILENO);
    } else {
        // Redirect standard output to file
        fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if (fd == -1) {
            perror("open");
            return -1;
        }
        dup2(fd, STDOUT_FILENO);
    }
    close(fd);
    return 0;
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_NUM_ARGS + 1];  // Add 1 for NULL terminator
    int num_args;
    pid_t pid;
    int status;
    int bg_exec;
    int i;
    char* infile;
    char* outfile;
    int redirect_in;
    int redirect_out;
    int append_out;

    // Install signal handler for SIGINT (CTRL-C)
    signal(SIGINT, sigint_handler);

    while (1) {
        // Reset variables for new command
        bg_exec = 0;
        infile = NULL;
        outfile = NULL;
        redirect_in = 0;
        redirect_out = 0;
        append_out = 0;

        // Print prompt
        printf("> ");
        fflush(stdout);  // Flush output to ensure prompt is printed immediately

        // Read input command
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove trailing newline
        command[strlen(command) - 1] = '\0';

        // Check if command should be executed in background
        if (command[strlen(command) - 1] == '&') {
            bg_exec = 1;
            command[strlen(command) - 1] = '\0';
        }

        // Split command into arguments
        split_command(command, args, &num_args);

        // Exit if command is "exit"
        if (strcmp(args[0], "exit") == 0) {
            exit(0);
        }

        // Handle input/output redirection
        for (i = 0; i < num_args; i++) {
            if (strcmp(args[i], "<") == 0) {
                // Redirect input from file
                infile = args[i + 1];
                redirect_in = 1;
                args[i] = NULL;
            } else if (strcmp(args[i], ">") == 0) {
            outfile = args[i + 1];
            redirect_out = 1;
            args[i] = NULL;
        } else if (strcmp(args[i], ">>") == 0) {
            // Append output to file
            outfile = args[i + 1];
            append_out = 1;
            args[i] = NULL;
        }
    }

    // Fork a new process to execute the command
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process

        // Handle input redirection
        if (redirect_in) {
            if (redirect(infile, 0) == -1) {
                exit(1);
            }
        }

        // Handle output redirection
        if (redirect_out) {
            if (append_out) {
                if (redirect(outfile, 1 | O_APPEND) == -1) {
                    exit(1);
                }
            } else {
                if (redirect(outfile, 1) == -1) {
                    exit(1);
                }
            }
        }

        // Execute command
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }

        // Child process should never reach this point
        exit(0);
    } else {
        // Parent process

        // Wait for child process to finish if not executed in background
        if (!bg_exec) {
            waitpid(pid, &status, 0);
        }
    }
}
return 0;
}
