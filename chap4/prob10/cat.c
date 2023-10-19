#include <stdio.h>
#include <stdlib.h>

void displayFileContents(FILE *fp, int printLineNumbers) {
    int line_number = 0;
    int c;
    int is_newline = 1;

    while ((c = getc(fp)) != EOF) {
        if (is_newline && printLineNumbers) {
            printf("%d: ", ++line_number);
        }
        putc(c, stdout);
        if (c == '\n') {
            is_newline = 1; 
        } else {
            is_newline = 0; 
        }
    }
}

int main(int argc, char *argv[]) {
    int printLineNumbers = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-n] file1.txt file2.txt file3.txt ...\n", argv[0]);
        return 1;
    }

    int arg_index = 1;

    if (strcmp(argv[arg_index], "-n") == 0) {
        printLineNumbers = 1;
        arg_index++;
    }

    for (; arg_index < argc; arg_index++) {
        FILE *fp = fopen(argv[arg_index], "r");

        if (fp == NULL) {
            fprintf(stderr, "%s\n", argv[arg_index]);
            continue;
        }


        displayFileContents(fp, printLineNumbers);
        fclose(fp);
    }

    return 0;
}

