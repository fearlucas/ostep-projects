#include <stdio.h>
#include <stdlib.h>

void decompress_file(FILE *stream) {
    int count;
    char character;

    while (fread(&count, sizeof(int), 1, stream) == 1) {
        if (fread(&character, sizeof(char), 1, stream) != 1) {
            printf("%s", "wunzip: error reading file\n");
            exit(1);
        }
        for (int i = 0; i < count; ++i) {
            putchar(character);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("%s", "wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; ++i) {
        FILE *stream = fopen(argv[i], "r");
        if (stream == NULL) {
            printf("%s", "wunzip: cannot open file");
            exit(1);
        }

        decompress_file(stream);
        fclose(stream);
    }

    return 0;
}
