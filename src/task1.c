#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task1.h"
#define MAX_LINE_LENGTH 100
#define STUDENTS_SECTION 1
#define COURSES_SECTION 2
#define ENROLLMENTS_SECTION 3
#define NOTA_LABORATOR 0
#define NOTA_PARTIAL 1
#define NOTA_FINAL 2
#define ROUNDING_PRECISION 100

secretariat *citeste_secretariat(const char *nume_fisier) {
    FILE *fin = fopen(nume_fisier, "r");
    if (fin == NULL) {
        fprintf(stderr, "Error opening file %s\n", nume_fisier);
        exit(EXIT_FAILURE);
    }
    secretariat *bigboi = malloc(sizeof(secretariat));
    if (bigboi == NULL) {
        fprintf(stderr, "Error allocating memory for secretariat\n");
        exit(EXIT_FAILURE);
    }

    bigboi->nr_studenti = 0;
    bigboi->nr_materii = 0;
    bigboi->nr_inrolari = 0;

    char line[MAX_LINE_LENGTH];
    char current_section = 0;
    int curr_section_line_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, fin) != NULL) {
        line[strcspn(line, "\n")] = '\0';  //  Remove newline character on each line

        // Find which section we are in
        if (strcmp(line, "[STUDENTI]") == 0) {
            current_section = STUDENTS_SECTION;
            curr_section_line_count = 0;
            continue;
        } else if (strcmp(line, "[MATERII]") == 0) {
            current_section = COURSES_SECTION;
            curr_section_line_count = 0;
            continue;
        } else if (strcmp(line, "[INROLARI]") == 0) {
            current_section = ENROLLMENTS_SECTION;
            curr_section_line_count = 0;
            continue;
        }

        // Fill in the data
        if (current_section == STUDENTS_SECTION) {  // Reading student data
            // Each time we read a new student, we need to allocate more memory for the array of students

            if (curr_section_line_count == 0) {
                bigboi->studenti = malloc(sizeof(student));
            } else {
                student *temp = NULL;
                temp = realloc(bigboi->studenti, (curr_section_line_count + 1) * sizeof(student));
                if (temp) {
                    bigboi->studenti = temp;
                    temp = NULL;
                } else {
                    fprintf(stderr, "Error reallocating memory for student\n");
                    exit(EXIT_FAILURE);
                }
            }

            // Almighty scanner
            sscanf(line, "%d, %99[^,], %d, %c", &bigboi->studenti[curr_section_line_count].id,
            bigboi->studenti[curr_section_line_count].nume, &bigboi->studenti[curr_section_line_count].an_studiu,
            &bigboi->studenti[curr_section_line_count].statut);

            bigboi->nr_studenti++;
            curr_section_line_count++;
        } else if (current_section == COURSES_SECTION) {  // Reading course data
            // Each time we read a new course, we need to allocate more memory for the array of students
            if (curr_section_line_count == 0) {
                bigboi->materii = malloc(sizeof(materie));
            } else {
                materie *temp = NULL;
                temp = realloc(bigboi->materii, (curr_section_line_count + 1) * sizeof(materie));
                if (temp) {
                    bigboi->materii = temp;
                    temp = NULL;
                } else {
                    fprintf(stderr, "Error reallocating memory for course\n");
                    exit(EXIT_FAILURE);
                }
            }

            // Allocating memory for the course name and professor name
            // Becuse in the struct they are pointers to char arrays
            bigboi->materii[curr_section_line_count].nume = malloc(sizeof(char) * MAX_STUDENT_NAME);
            if (bigboi->materii[curr_section_line_count].nume == NULL) {
                fprintf(stderr, "Error allocating memory for course name\n");
                exit(EXIT_FAILURE);
            }
            bigboi->materii[curr_section_line_count].nume_titular = malloc(sizeof(char) * MAX_STUDENT_NAME);
            if (bigboi->materii[curr_section_line_count].nume_titular == NULL) {
                fprintf(stderr, "Error allocating memory for professor name\n");
                exit(EXIT_FAILURE);
            }

            // Almighty scanner
            // I don't know why but the %[^\n] works here
            sscanf(line, "%d, %[^,], %[^\n]", &bigboi->materii[curr_section_line_count].id,
            bigboi->materii[curr_section_line_count].nume, bigboi->materii[curr_section_line_count].nume_titular);

            bigboi->nr_materii++;
            curr_section_line_count++;
        } else if (current_section == ENROLLMENTS_SECTION) {  // Reading enrollment data
            // Each time we read a new enrollment, we need to allocate more memory for the array of enrollments
            if (curr_section_line_count == 0) {
                bigboi->inrolari = malloc(sizeof(inrolare));
            } else {
                inrolare *temp = NULL;
                temp = realloc(bigboi->inrolari, (curr_section_line_count + 1) * sizeof(inrolare));
                if (temp) {
                    bigboi->inrolari = temp;
                    temp = NULL;
                } else {
                    fprintf(stderr, "Error reallocating memory for enrollment\n");
                    exit(EXIT_FAILURE);
                }
            }

            // Almighty scanner
            sscanf(line, "%d, %d, %f %f %f", &bigboi->inrolari[curr_section_line_count].id_student,
            &bigboi->inrolari[curr_section_line_count].id_materie,
            &bigboi->inrolari[curr_section_line_count].note[NOTA_LABORATOR],
            &bigboi->inrolari[curr_section_line_count].note[NOTA_PARTIAL],
            &bigboi->inrolari[curr_section_line_count].note[NOTA_FINAL]);

            bigboi->nr_inrolari++;
            curr_section_line_count++;
        }
    }

    // Now we need to calculate the cumulatve GPA for each student
    for (int i = 0; i < bigboi->nr_studenti; i++) {
        float grades = 0;
        int courses_count = 0;
        for (int j = 0; j < bigboi->nr_inrolari; j++) {
            if (bigboi->inrolari[j].id_student == bigboi->studenti[i].id) {
                grades += bigboi->inrolari[j].note[NOTA_LABORATOR] + bigboi->inrolari[j].note[NOTA_PARTIAL] +
                bigboi->inrolari[j].note[NOTA_FINAL];
                courses_count++;
            }
        }
        bigboi->studenti[i].medie_generala = (float)((int)(grades / (float)courses_count * (float)ROUNDING_PRECISION)) /
        (float)ROUNDING_PRECISION;
    }

    fclose(fin);
    return bigboi;
}

void adauga_student(secretariat *s, int id, char *nume, int an_studiu, char statut, float medie_generala) {
    // Make space for the new student
    student *temp = NULL;
    temp = realloc(s->studenti, (s->nr_studenti + 1) * sizeof(student));
    if (temp) {
        s->studenti = temp;
        temp = NULL;
    } else {
        fprintf(stderr, "Error reallocating memory for student\n");
        exit(EXIT_FAILURE);
    }
    s->nr_studenti++;

    // Set the new student's data
    s->studenti[s->nr_studenti - 1].id = id;
    snprintf(s->studenti[s->nr_studenti - 1].nume,  MAX_STUDENT_NAME, "%s", nume);
    s->studenti[s->nr_studenti - 1].an_studiu = an_studiu;
    s->studenti[s->nr_studenti - 1].statut = statut;
    s->studenti[s->nr_studenti - 1].medie_generala = medie_generala;
}

void elibereaza_secretariat(secretariat **s) {
    // Free the memory allocated for the students
    free((**s).studenti);
    (**s).studenti = NULL;

    // Free the memory allocated for the courses
    // Don't forget to free the memory allocated for the course name and professor name
    for (int i = 0; i < (**s).nr_materii; i++) {
        free((**s).materii[i].nume);
        (**s).materii[i].nume = NULL;
        free((**s).materii[i].nume_titular);
        (**s).materii[i].nume_titular = NULL;
    }
    free((**s).materii);
    (**s).materii = NULL;

    // Free the memory allocated for the enrollments
    free((**s).inrolari);
    (**s).inrolari = NULL;

    // Now free the memory allocated for the bigboi
    free(*s);
    *s = NULL;
}
