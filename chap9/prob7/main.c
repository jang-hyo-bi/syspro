#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAXARG 20
#define MAXLINE 100

int main() {
    char input[MAXLINE];
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

		int i=0;
        token = strtok(input, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (args[0] == NULL)
            continue;

        if (strcmp(args[i - 1], "&") == 0) {
            args[i - 1] = NULL;
            background = 1;
        }

        pid_t pid = fork();

        if (pid < 0) {
            printf("Fork failed.\n");
            continue;
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                printf("Error executing command.\n");
                exit(EXIT_FAILURE);
            }
        } else {
            if (!background) {
                waitpid(pid, NULL, 0);
            }
            background = 0;
        }
    }

    return 0;
}

