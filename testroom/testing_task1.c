#include <stdio.h>
#include <stdlib.h>
#include "../src/task1.h"
int main() {
    // if (argc != 2) {
    //     fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
    //     exit(EXIT_FAILURE);
    // }
    secretariat *bigboi = citeste_secretariat("../tests/db/small.db");
    printf("Nr. studenti: %d\n", bigboi->nr_studenti);
    printf("Nr. materii: %d\n", bigboi->nr_materii);
    printf("Nr. inrolari: %d\n", bigboi->nr_inrolari);
    for (int i = 0; i < bigboi->nr_studenti; i++) {
        printf("Student %d:\nID: %d Name: %s, Year: %d, Status: %c\n", bigboi->studenti[i].id,
        bigboi->studenti[i].id, bigboi->studenti[i].nume, bigboi->studenti[i].an_studiu,
        bigboi->studenti[i].statut);
    }
    for (int i = 0; i < bigboi->nr_materii; i++) {
        printf("Course %d:\nID: %d, Name: %s, Prof: %s\n", bigboi->materii[i].id,
        bigboi->materii[i].id, bigboi->materii[i].nume, bigboi->materii[i].nume_titular);
    }
    for (int i = 0; i < bigboi->nr_inrolari; i++) {
        printf("Enrollment:\nStudent ID: %d, Course ID: %d, Grades: [Lab: %.2f Partial: %.2f Final: %.2f]\n",
        bigboi->inrolari[i].id_student, bigboi->inrolari[i].id_materie, bigboi->inrolari[i].note[0],
        bigboi->inrolari[i].note[1], bigboi->inrolari[i].note[2]);
    }
    return 0;
}