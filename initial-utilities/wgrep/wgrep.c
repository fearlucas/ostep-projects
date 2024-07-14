#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(EXIT_FAILURE);
    }

    char *pattern = argv[1];

    for (int i = 2; i < argc; ++i) {
        stream = fopen(argv[i], "r");
        if (stream == NULL) {
            // Print the error message to stdout
	    //perror("wgrep: cannot open file\n");
            printf("wgrep: cannot open file\n");
            exit(EXIT_FAILURE);
        }

        while ((nread = getline(&line, &len, stream)) != EOF) {
            if (strstr(line, pattern) != NULL) {
		fwrite(line, nread, 1, stdout);
                //printf("%s", line);
            }
        }

        free(line);
        line = NULL;  // Resetting line to NULL to avoid double-free issues
        fclose(stream);
    }

    exit(0); // Return 0 to indicate success
}

