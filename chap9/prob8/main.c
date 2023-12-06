#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAXARG 20
#define MAXLINE 100

void execute_command(char *args[], int background) {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        printf("Error executing command.\n");
        exit(EXIT_FAILURE);
    } else {
        if (!background) {
            waitpid(pid, NULL, 0);
        }
    }
}

int main() {
    char input[MAXLINE];
    char *commands[MAXARG];
    char *args[MAXARG];
    char *token;
    int background = 0;

    while (1) {
        printf("[Shell] ");
        fflush(stdout);

        if (fgets(input, MAXLINE, stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        if (input[strlen(input) - 1] == '\n')
            input[strlen(input) - 1] = '\0';

        int i = 0;
        token = strtok(input, ";&");
        while (token != NULL) {
            commands[i++] = token;
            token = strtok(NULL, ";&");
        }
        commands[i] = NULL;

        for (int j = 0; j < i; j++) {
            token = strtok(commands[j], " ");
            int k = 0;
            while (token != NULL) {
                args[k++] = token;
                token = strtok(NULL, " ");
            }
            args[k] = NULL;

            if (strcmp(args[k - 1], "&") == 0) {
                args[k - 1] = NULL;
                background = 1;
            }

            for (int l = 0; l < k; l++) {
                if (strcmp(args[l], ">") == 0) {
                    args[l] = NULL;
                    int fd = open(args[l + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                } else if (strcmp(args[l], "<") == 0) {
                    args[l] = NULL;
                    int fd = open(args[l + 1], O_RDONLY);
                    dup2(fd, STDIN_FILENO);
                    close(fd);
                }
            }

            execute_command(args, background);
            background = 0;
        }
    }

    return 0;
}

