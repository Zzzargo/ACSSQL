#pragma once

#include "../include/structuri.h"
#define MAX_LINE_LENGTH 100
#define STUDENTS_SECTION 1
#define COURSES_SECTION 2
#define ENROLLMENTS_SECTION 3
#define NOTA_LABORATOR 0
#define NOTA_PARTIAL 1
#define NOTA_FINAL 2
#define LAST_DIGIT_GETTER 10
#define HALF 5
#define ROUNDING_PRECISION 100.0f
#define INCREMENT 0.555555f  // Many tears were shed here

secretariat *citeste_secretariat(const char *nume_fisier);

void adauga_student(secretariat *s, int id, char *nume, int an_studiu, char statut, float medie_generala);

void elibereaza_secretariat(secretariat **s);