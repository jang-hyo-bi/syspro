#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void get_environment_value(const char* env_name) {
    char* env_value = getenv(env_name);
    if (env_value != NULL) {
        printf("%s: %s\n", env_name, env_value);
    } else {
        printf("Environment variable '%s' not found.\n", env_name);
    }
}

void print_user_info() {
    printf("My Realistic User ID: %d\n", getuid());
    printf("My Valid User ID: %d\n", geteuid());
}
void print_group_info() {
	printf("My Realistic Group ID : %d\n", getgid());
	printf("My Valid Group ID : %d\n", getgid());
}
void print_process_info() {
    printf("my process number :[ %d ]\n", getpid());
}
void print_parent_info() {
	printf("my parent's process number :[ %d ]\n", getppid());
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Provide appropriate options\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'e':
                    if (argv[i + 1] != NULL) {
                        get_environment_value(argv[i + 1]);
                        i++;
                    } else {
                        get_environment_value("");
                    }
                    break;
                case 'u':
                    print_user_info();
                    break;
                case 'g':
                    print_group_info();
                    break;
                case 'i':
                    print_process_info();
                    break;
                case 'p':
                    print_parent_info();
                    break;
                default:
                    printf("xx\n");
                    break;
            }
        }
    }

    return 0;
}

