// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[]) {
//     FILE *fp;
//     char c;

//     for (int i = 1; i < argc; i++) {
//         fp = fopen(argv[i], "r");
//         if (fp == NULL) {
//             // Print the error message to stdout
//             printf("wcat: cannot open file\n");
//             return 1; // Return 1 to indicate error
//         }

//         while ((c = fgetc(fp)) != EOF) {
//             printf("%c", c);
//         }

//         fclose(fp);
//     }

//     return 0; // Return 0 to indicate success
// }
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char c;

    for (int i = 1; i < argc; ++i) {
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            // Print the error message to stdout
            printf("wcat: cannot open file\n");
            exit(1);
        }

        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
        }
        
        fclose(fp);
    }
    return 0; // Return 0 to indicate success
}
