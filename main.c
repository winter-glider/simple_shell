#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // Non-interactive mode
        int file = open(argv[1], O_RDONLY);  // open file with read-only mode
        if (file == -1) {
            perror("open");
            return 1;
        }

        char *line = NULL;
        size_t len = 0;
        ssize_t read;

        while ((read = getline(&line, &len, fdopen(file, "r"))) != -1) {
            line[strcspn(line, "\n")] = '\0';  // Remove newline character
            char **parsed_input = parse_input(line);

            if (parsed_input[0] != NULL) {
                execute_action(parsed_input, parsed_input);
            }

            for (int i = 0; parsed_input[i] != NULL; i++) {
                free(parsed_input[i]);
            }
            free(parsed_input);
        }

        free(line);
        close(file);  // close the file using close() function   
} else {
        // Interactive mode
        while (1) {
            write(1, "$ ", strlen("$ "));

            char *user_input = read_input();
            if (user_input== NULL)
                                break;
                                char **parsed_input = parse_input(user_input);
        char *action = NULL;

        interpret_input(parsed_input, &action);
        execute_action(parsed_input, parsed_input);

        for (int i = 0; parsed_input[i] != NULL; i++) {
            free(parsed_input[i]);
        }
        free(parsed_input);

        free(user_input);
    }
}

	return 0;
}
