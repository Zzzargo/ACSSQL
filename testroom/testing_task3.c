#include <stdio.h>
#include <stdlib.h>
#include "../src/task1.h"
#include "../src/task3.h"
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    secretariat *bigboi = citeste_secretariat(argv[1]);
    cripteaza_studenti(bigboi, "pclp1", 5, "aa", 2, "output_task3.txt");
    return 0;
}