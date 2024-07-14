#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress_file(FILE *stream, int *count, char *previous_char) {
    char current_char;

    while (fread(&current_char, 1, 1 , stream) == 1) {
        if (current_char == *previous_char) {
            (*count)++;
        } else {
            if (*count > 0) {
                fwrite(count, sizeof(int), 1, stdout);
                fwrite(previous_char, sizeof(char), 1, stdout);
            }

            *previous_char = current_char;
            *count = 1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("%s", "wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int count = 0;
    char previous_char = '\0';

    for (int i = 1; i < argc; ++i) {
        FILE *stream = fopen(argv[i], "r");
        if (stream == NULL) {
            printf("wzip: cannot open file");
            exit(0);
        }

        compress_file(stream, &count, &previous_char);
        fclose(stream);
    }
    
     // Write the last run
    if (count > 0) {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&previous_char, sizeof(char), 1, stdout);
    }

    return 0;
}
