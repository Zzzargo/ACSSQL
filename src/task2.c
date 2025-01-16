#include "task2.h"
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>

// #define DEBUG

bool check_student(char *condition_column, char *condition_operator, char *condition_value, student *slave) {
    bool conditions_met = true;

    #ifdef DEBUG
        printf("INSIDE CHECK STUDENT. CONDITION: %s %s %s\n", condition_column, condition_operator, condition_value);
    #endif

    if (strcmp(condition_column, "id") == 0) {
        #ifdef DEBUG
            printf("INSIDE CHECK STUDENT. CHECKING ID\n");
        #endif

        if (strcmp(condition_operator, "=") == 0) {
            if (atoi(condition_value) != slave->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (atoi(condition_value) == slave->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (atoi(condition_value) >= slave->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (atoi(condition_value) <= slave->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (atoi(condition_value) < slave->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (atoi(condition_value) > slave->id) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "nume") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (strcmp(condition_value, slave->nume) != 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (strcmp(condition_value, slave->nume) == 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (strcmp(condition_value, slave->nume) >= 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (strcmp(condition_value, slave->nume) <= 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (strcmp(condition_value, slave->nume) < 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (strcmp(condition_value, slave->nume) > 0) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "an_studiu") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (atoi(condition_value) != slave->an_studiu) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (atoi(condition_value) == slave->an_studiu) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (atoi(condition_value) >= slave->an_studiu) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (atoi(condition_value) <= slave->an_studiu) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (atoi(condition_value) < slave->an_studiu) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (atoi(condition_value) > slave->an_studiu) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "statut") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (*condition_value != slave->statut) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (*condition_value == slave->statut) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (*condition_value >= slave->statut) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (*condition_value <= slave->statut) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (*condition_value < slave->statut) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (*condition_value > slave->statut) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "medie_generala") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (fabs(atof(condition_value) - slave->medie_generala) > EPSILON) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (fabs(atof(condition_value) - slave->medie_generala) < EPSILON) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (atof(condition_value) >= slave->medie_generala) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (atof(condition_value) <= slave->medie_generala) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (atof(condition_value) > slave->medie_generala) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (atof(condition_value) < slave->medie_generala) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    }

    #ifdef DEBUG
        printf("REACHED END OF CHECK STUDENT\n");
    #endif

    return conditions_met;
}

bool check_course(char *condition_column, char *condition_operator, char *condition_value, materie *course) {
    bool conditions_met = true;
    if (strcmp(condition_column, "id") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (atoi(condition_value) != course->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (atoi(condition_value) == course->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (atoi(condition_value) >= course->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (atoi(condition_value) <= course->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (atoi(condition_value) < course->id) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (atoi(condition_value) > course->id) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "nume") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (strcmp(condition_value, course->nume) != 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (strcmp(condition_value, course->nume) == 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (strcmp(condition_value, course->nume) >= 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (strcmp(condition_value, course->nume) <= 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (strcmp(condition_value, course->nume) < 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (strcmp(condition_value, course->nume) > 0) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "nume_titular") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (strcmp(condition_value, course->nume_titular) != 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (strcmp(condition_value, course->nume_titular) == 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (strcmp(condition_value, course->nume_titular) >= 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (strcmp(condition_value, course->nume_titular) <= 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (strcmp(condition_value, course->nume_titular) < 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (strcmp(condition_value, course->nume_titular) > 0) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    }
    return conditions_met;
}

bool check_enrollment(char *condition_column, char *condition_operator, char *condition_value, inrolare *enrollment) {
    bool conditions_met = true;

    #ifdef DEBUG
        printf("CHECK ENROLLMENT. Condition: %s %s %s\n", condition_column, condition_operator, condition_value);
    #endif

    if (strcmp(condition_column, "id_student") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (atoi(condition_value) != enrollment->id_student) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (atoi(condition_value) == enrollment->id_student) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (atoi(condition_value) >= enrollment->id_student) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (atoi(condition_value) <= enrollment->id_student) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (atoi(condition_value) < enrollment->id_student) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (atoi(condition_value) > enrollment->id_student) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "id_materie") == 0) {
        if (strcmp(condition_operator, "=") == 0) {
            if (atoi(condition_value) != enrollment->id_materie) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (atoi(condition_value) == enrollment->id_materie) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (atoi(condition_value) >= enrollment->id_materie) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (atoi(condition_value) <= enrollment->id_materie) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (atoi(condition_value) < enrollment->id_materie) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (atoi(condition_value) > enrollment->id_materie) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(condition_column, "note") == 0) {
        char *curr_grades = malloc(MAX_VALUE_LENGTH * sizeof(char));
        snprintf(curr_grades, MAX_VALUE_LENGTH, "%.2f %.2f %.2f", enrollment->note[NOTA_LABORATOR],
        enrollment->note[NOTA_PARTIAL], enrollment->note[NOTA_FINAL]);

        #ifdef DEBUG
            printf("CHECK ENROLLMENT GRADES. Current enrollment grades: %s\n", curr_grades);
        #endif

        if (strcmp(condition_operator, "=") == 0) {
            if (strcmp(condition_value, curr_grades) != 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "!=") == 0) {
            if (strcmp(condition_value, curr_grades) == 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">") == 0) {
            if (strcmp(condition_value, curr_grades) > 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<") == 0) {
            if (strcmp(condition_value, curr_grades) < 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, ">=")) {
            if (strcmp(condition_value, curr_grades) >= 0) {
                conditions_met = false;
            }
        } else if (strcmp(condition_operator, "<=")) {
            if (strcmp(condition_value, curr_grades) <= 0) {
                conditions_met = false;
            }
        } else {
            fprintf(stderr, "Error: Invalid operator\n");
            exit(EXIT_FAILURE);
        }
        free(curr_grades);
    }
    return conditions_met;
}

bool check_conditions(char *condition_column, char *condition_operator, char *condition_value,
char table, ...) {
    va_list opt_args;
    va_start(opt_args, table);
    bool conditions_met = true;

    #ifdef DEBUG
        printf("INSIDE CHECK_CONDITIONS. CONDITIONS: %s %s %s\n", condition_column, condition_operator,
        condition_value);
    #endif

    switch (table) {
        case STUDENTS_TABLE: {
            student slave = va_arg(opt_args, student);

            #ifdef DEBUG
                printf("CHECKING CONDITIONS FOR STUDENT: %d %s %d %c %.2f\n", slave.id, slave.nume, slave.an_studiu,
                slave.statut, slave.medie_generala);
            #endif

            conditions_met = check_student(condition_column, condition_operator, condition_value, &slave);
            break;
        }
        case COURSES_TABLE: {
            materie course = va_arg(opt_args, materie);

            #ifdef DEBUG
                printf("CHECKING CONDITIONS FOR COURSE: %d %s %s\n", course.id, course.nume, course.nume_titular);
            #endif

            conditions_met = check_course(condition_column, condition_operator, condition_value, &course);
            break;
        }
        case ENROLLMENTS_TABLE: {
            inrolare enrollment = va_arg(opt_args, inrolare);

            #ifdef DEBUG
                printf("CHECKING CONDITIONS FOR ENROLLMENT: %d %d %.2f %.2f %.2f\n", enrollment.id_student,
                enrollment.id_materie, enrollment.note[NOTA_LABORATOR], enrollment.note[NOTA_PARTIAL],
                enrollment.note[NOTA_FINAL]);
            #endif

            conditions_met = check_enrollment(condition_column, condition_operator, condition_value, &enrollment);
            break;
        }
        default: {
            fprintf(stderr, "Error: Invalid table name\n");
            exit(EXIT_FAILURE);
            break;
        }
    }
    va_end(opt_args);
    return conditions_met;
}

// There could have been 2 separate functions for the two types of SELECT, but I obey the DRY principle
void handle_select(secretariat *bigboi, char *table, char **selected_columns, int selected_columns_count,
int conditions_count, char **conditions) {
    bool filtered_select = (conditions_count > 0);  // smOrt

    #ifdef DEBUG
        printf("INSIDE HANDLE SELECT. FILTERED SELECT. CONDITIONS:\n");
        for (int i = 0; i < conditions_count; i++) {
            printf("%s\n", conditions[i]);
        }
    #endif

    bool conditions_met = true;
    if (strcmp(table, "studenti") == 0) {
        #ifdef DEBUG
            printf("INSIDE HANDLE SELECT STUDENTS\n");
        #endif

        for (int i = 0; i < bigboi->nr_studenti; i++) {  // For each student
            if (filtered_select) {
                //  Check if the conditions are met
                for (int j = 0; j < conditions_count; j++) {
                    char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                    //  We need to copy the condition because strtok modifies the string
                    snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);
                    char *condition_column = strtok(condition, " ");
                    char *condition_operator = strtok(NULL, " ");
                    char *condition_value = strtok(NULL, "\0");

                    #ifdef DEBUG
                        printf("INSIDE HANDLE SELECT STUDENTS. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                        condition_column, condition_operator, condition_value);
                    #endif

                    conditions_met = check_conditions(condition_column, condition_operator, condition_value,
                    STUDENTS_TABLE, bigboi->studenti[i]);
                    free(condition);
                    if (!conditions_met) {
                        #ifdef DEBUG
                            printf("INSIDE HANDLE SELECT STUDENTS. Condition not met\n");
                        #endif
                        break;  // Prevent further processing if a condition is not met
                    }
                }
            }

            if (strcmp(selected_columns[0], "*") == 0) {
                // All columns
                if (conditions_met) {
                    printf("%d %s %d %c %.2f\n", bigboi->studenti[i].id, bigboi->studenti[i].nume,
                    bigboi->studenti[i].an_studiu, bigboi->studenti[i].statut, bigboi->studenti[i].medie_generala);
                    continue;
                }
            }
            for (int j = 0; j < selected_columns_count; j++) {
                if (strcmp(selected_columns[j], "id") == 0) {
                    if (conditions_met) {
                        printf("%d", bigboi->studenti[i].id);
                    }
                } else if (strcmp(selected_columns[j], "nume") == 0) {
                    if (conditions_met) {
                        printf("%s", bigboi->studenti[i].nume);
                    }
                } else if (strcmp(selected_columns[j], "an_studiu") == 0) {
                    if (conditions_met) {
                        printf("%d", bigboi->studenti[i].an_studiu);
                    }
                } else if (strcmp(selected_columns[j], "statut") == 0) {
                    if (conditions_met) {
                        printf("%c", bigboi->studenti[i].statut);
                    }
                } else if (strcmp(selected_columns[j], "medie_generala") == 0) {
                    if (conditions_met) {
                        printf("%.2f", bigboi->studenti[i].medie_generala);
                    }
                }

                // Print a space after each column, except for the last one
                if (j != selected_columns_count - 1 && conditions_met) {
                    printf(" ");
                }
            }
            if (conditions_met) {  // Print a newline if a row was printed
                printf("\n");
            }
        }
    } else if (strcmp(table, "materii") == 0) {
        for (int i = 0; i < bigboi->nr_materii; i++) {  // For each course
            if (filtered_select) {
                //  Check if the conditions are met
                for (int j = 0; j < conditions_count; j++) {
                    char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));

                    #ifdef DEBUG
                        printf("Length of allocated memory for condition: %ld\n", strlen(conditions[j] + 1));
                    #endif

                    //  We need to copy the condition because strtok modifies the string
                    snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                    #ifdef DEBUG
                        printf("INSIDE HANDLE SELECT COURSES. CONDITION READ: %s\n", condition);
                    #endif

                    char *condition_column = strtok(condition, " ");
                    char *condition_operator = strtok(NULL, " ");
                    char *condition_value = strtok(NULL, "\0");

                    #ifdef DEBUG
                        printf("INSIDE HANDLE SELECT COURSES. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                        condition_column, condition_operator, condition_value);
                    #endif

                    conditions_met = check_conditions(condition_column, condition_operator, condition_value,
                    COURSES_TABLE, bigboi->materii[i]);
                    free(condition);
                    if (!conditions_met) {
                        #ifdef DEBUG
                            printf("INSIDE HANDLE SELECT COURSES. Condition not met\n");
                        #endif

                        break;  // Prevent further processing if a condition is not met
                    }
                }
            }
            if (strcmp(selected_columns[0], "*") == 0) {
                // All columns

                if (conditions_met) {
                    printf("%d %s %s\n", bigboi->materii[i].id, bigboi->materii[i].nume,
                    bigboi->materii[i].nume_titular);
                    continue;
                }
            }
            for (int j = 0; j < selected_columns_count; j++) {
                if (strcmp(selected_columns[j], "id") == 0) {
                    if (conditions_met) {
                        printf("%d", bigboi->materii[i].id);
                    }
                } else if (strcmp(selected_columns[j], "nume") == 0) {
                    if (conditions_met) {
                        printf("%s", bigboi->materii[i].nume);
                    }
                } else if (strcmp(selected_columns[j], "nume_titular") == 0) {
                    if (conditions_met) {
                        printf("%s", bigboi->materii[i].nume_titular);
                    }
                }

                // Print a space after each column, except for the last one
                if  (j != selected_columns_count - 1 && conditions_met) {
                    printf(" ");
                }
            }
            if (conditions_met) {  // Print a newline if a row was printed
                printf("\n");
            }
        }
    } else if (strcmp(table, "inrolari") == 0) {
        for (int i = 0; i < bigboi->nr_inrolari; i++) {  // For each enrollment
            if (filtered_select) {
                //  Check if the conditions are met
                for (int j = 0; j < conditions_count; j++) {
                    char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                    //  We need to copy the condition because strtok modifies the string
                    snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                    #ifdef DEBUG
                        printf("INSIDE HANDLE SELECT ENROLLMENTS. CONDITION READ: %s\n", condition);
                    #endif

                    char *condition_column = strtok(condition, " ");
                    char *condition_operator = strtok(NULL, " ");
                    char *condition_value = strtok(NULL, "\0");

                    #ifdef DEBUG
                        printf(
                        "INSIDE HANDLE SELECT ENROLLMENTS. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                        condition_column, condition_operator, condition_value);
                    #endif

                    conditions_met = check_conditions(condition_column, condition_operator, condition_value,
                    ENROLLMENTS_TABLE, bigboi->inrolari[i]);
                    free(condition);
                    if (!conditions_met) {
                        break;  // Prevent further processing if a condition is not met
                    }
                }
            }
            if (strcmp(selected_columns[0], "*") == 0) {
                // All columns

                if (conditions_met) {
                    printf("%d %d %.2f %.2f %.2f\n", bigboi->inrolari[i].id_student, bigboi->inrolari[i].id_materie,
                    bigboi->inrolari[i].note[NOTA_LABORATOR], bigboi->inrolari[i].note[NOTA_PARTIAL],
                    bigboi->inrolari[i].note[NOTA_FINAL]);
                }
                continue;
            }
            for (int j = 0; j < selected_columns_count; j++) {
                if (strcmp(selected_columns[j], "id_student") == 0) {
                    if (conditions_met) {
                        printf("%d", bigboi->inrolari[i].id_student);
                    }
                } else if (strcmp(selected_columns[j], "id_materie") == 0) {
                    if (conditions_met) {
                        printf("%d", bigboi->inrolari[i].id_materie);
                    }
                } else if (strcmp(selected_columns[j], "note") == 0) {
                    if (conditions_met) {
                        printf("%.2f %.2f %.2f", bigboi->inrolari[i].note[NOTA_LABORATOR],
                        bigboi->inrolari[i].note[NOTA_PARTIAL],
                        bigboi->inrolari[i].note[NOTA_FINAL]);
                    }
                }
                // Print a space after each column, except for the last one
                if (j != selected_columns_count - 1 && conditions_met) {
                    printf(" ");
                }
            }
            if (conditions_met) {  // Print a newline if a row was printed
                printf("\n");
            }
        }
    }
}

void handle_update(secretariat *bigboi, char *table, char *column_to_update, char *value_to_assign,
int conditions_count, char **conditions) {
    #ifdef DEBUG
        printf("INSIDE HANDLE UPDATE\n");
    #endif

    bool conditions_met = true;
    if (strcmp(table, "studenti") == 0) {
        if (strcmp(column_to_update, "id") == 0) {
            fprintf(stderr, "Cannot update id column\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < bigboi->nr_studenti; i++) {
            conditions_met = true;
            // First check if the conditions are met

            for (int j = 0; j < conditions_count; j++) {
                // We need to copy the condition because strtok modifies the string
                char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                #ifdef DEBUG
                    printf("INSIDE HANDLE UPDATE. CONDITION READ: %s\n", condition);
                #endif

                char *condition_column = strtok(condition, " ");
                char *condition_operator = strtok(NULL, " ");
                char *condition_value = strtok(NULL, "\0");

                #ifdef DEBUG
                    printf(
                    "INSIDE HANDLE UPDATE. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                    condition_column, condition_operator, condition_value);
                #endif

                bool curr_condition_met = check_conditions(condition_column, condition_operator, condition_value,
                STUDENTS_TABLE, bigboi->studenti[i]);

                conditions_met = curr_condition_met && conditions_met;
                free(condition);
            }

            // For some reason if i compose the if statement in one line, it doesn't work
            if (strcmp(column_to_update, "nume") == 0) {
                #ifdef DEBUG
                    printf("INSIDE HANDLE UPDATE. Trying to update name\n");
                #endif

                if (conditions_met) {
                    snprintf(bigboi->studenti[i].nume, MAX_VALUE_LENGTH, "%s", value_to_assign);

                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Student %d now has name %s\n", bigboi->studenti[i].id,
                        bigboi->studenti[i].nume);
                    #endif
                }
            } else if (strcmp(column_to_update, "an_studiu") == 0) {
                if (conditions_met) {
                    bigboi->studenti[i].an_studiu = atoi(value_to_assign);
                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Student %d now has an_studiu %d\n", bigboi->studenti[i].id,
                        bigboi->studenti[i].an_studiu);
                    #endif
                }
            } else if (strcmp(column_to_update, "statut") == 0) {
                if (conditions_met) {
                    bigboi->studenti[i].statut = *value_to_assign;

                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Student %d now has statut %c\n", bigboi->studenti[i].id,
                        bigboi->studenti[i].statut);
                    #endif
                }
            } else if (strcmp(column_to_update, "medie_generala") == 0) {
                if (conditions_met) {
                    bigboi->studenti[i].medie_generala = (float)atof(value_to_assign);

                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Student %d now has medie_generala %f\n", bigboi->studenti[i].id,
                        bigboi->studenti[i].medie_generala);
                    #endif
                }
            } else {
                fprintf(stderr, "Invalid column name.");
                exit(EXIT_FAILURE);
            }
        }
    } else if (strcmp(table, "materii") == 0) {
        if (strcmp(column_to_update, "id") == 0) {
            fprintf(stderr, "Cannot update id column\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < bigboi->nr_materii; i++) {
            // First check if the conditions are met
            conditions_met = true;
            for (int j = 0; j < conditions_count; j++) {
                // We need to copy the condition because strtok modifies the string
                char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                #ifdef DEBUG
                    printf("INSIDE HANDLE UPDATE. CONDITION READ: %s\n", condition);
                #endif

                char *condition_column = strtok(condition, " ");
                char *condition_operator = strtok(NULL, " ");
                char *condition_value = strtok(NULL, "\0");

                #ifdef DEBUG
                    printf(
                    "INSIDE HANDLE UPDATE. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                    condition_column, condition_operator, condition_value);
                #endif

                bool curr_conditions_met = check_conditions(condition_column, condition_operator, condition_value,
                COURSES_TABLE, bigboi->materii[i]);
                conditions_met = curr_conditions_met && conditions_met;
                free(condition);
            }

            if (strcmp(column_to_update, "nume") == 0) {
                if (conditions_met) {
                    snprintf(bigboi->materii[i].nume, MAX_VALUE_LENGTH, "%s", value_to_assign);

                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Course %d now has name %s\n", bigboi->materii[i].id,
                        bigboi->materii[i].nume);
                    #endif
                }
            } else if (strcmp(column_to_update, "nume_titular") == 0) {
                if (conditions_met) {
                    snprintf(bigboi->materii[i].nume_titular, MAX_VALUE_LENGTH, "%s", value_to_assign);

                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Course %d now has nume_titular %s\n", bigboi->materii[i].id,
                        bigboi->materii[i].nume_titular);
                    #endif
                }
            } else {
                fprintf(stderr, "Invalid column name.");
                exit(EXIT_FAILURE);
            }
        }
    } else if (strcmp(table, "inrolari") == 0) {
        // if (strcmp(column_to_update, "id_student") == 0 || strcmp(column_to_update, "id_materie") == 0) {
        //     fprintf(stderr, "Cannot update id column\n");
        //     exit(EXIT_FAILURE);
        // }
        for (int i = 0; i < bigboi->nr_inrolari; i++) {
            // First check if the condition is met
            conditions_met = true;

            for (int j = 0; j < conditions_count; j++) {
                // We need to copy the condition because strtok modifies the string
                char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                #ifdef DEBUG
                    printf("INSIDE HANDLE UPDATE. CONDITION READ: %s\n", condition);
                #endif

                char *condition_column = strtok(condition, " ");
                char *condition_operator = strtok(NULL, " ");
                char *condition_value = strtok(NULL, "\0");

                #ifdef DEBUG
                    printf(
                    "INSIDE HANDLE UPDATE. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                    condition_column, condition_operator, condition_value);
                #endif

                bool curr_conditions_met = check_conditions(condition_column, condition_operator, condition_value,
                ENROLLMENTS_TABLE, bigboi->inrolari[i]);
                conditions_met = curr_conditions_met && conditions_met;
                free(condition);
            }

            if (strcmp(column_to_update, "note") == 0) {
                if (conditions_met) {
                    // First get the grades from the value_to_assign string
                    float *grades = malloc(GRADE_COUNT * sizeof(float));
                    // Also, we need a copy of the value_to_assign string so we can use strtok
                    char *value_to_assign_copy = malloc(MAX_VALUE_LENGTH);
                    memcpy(value_to_assign_copy, value_to_assign, MAX_VALUE_LENGTH);
                    grades[NOTA_LABORATOR] = (float)atof(strtok(value_to_assign_copy, " "));
                    grades[NOTA_PARTIAL] = (float)atof(strtok(NULL, " "));
                    grades[NOTA_FINAL] = (float)atof(strtok(NULL, "\0"));

                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Grades gotten from value_to_assign: %.2f %.2f %.2f\n",
                        grades[NOTA_LABORATOR], grades[NOTA_PARTIAL], grades[NOTA_FINAL]);
                    #endif

                    bigboi->inrolari[i].note[NOTA_LABORATOR] = grades[NOTA_LABORATOR];
                    bigboi->inrolari[i].note[NOTA_PARTIAL] = grades[NOTA_PARTIAL];
                    bigboi->inrolari[i].note[NOTA_FINAL] = grades[NOTA_FINAL];

                    #ifdef DEBUG
                        printf("INSIDE HANDLE UPDATE. Student %d now has grades %f %f %f for course %d\n",
                        bigboi->inrolari[i].id_student, bigboi->inrolari[i].note[NOTA_LABORATOR],
                        bigboi->inrolari[i].note[NOTA_PARTIAL], bigboi->inrolari[i].note[NOTA_FINAL],
                        bigboi->inrolari[i].id_materie);
                    #endif

                    free(grades);
                    free(value_to_assign_copy);

                    // Now we need to update the average for the student whose enrollment was updated
                    for (int j = 0; j < bigboi->nr_studenti; j++) {
                        float grades = 0;
                        int courses_count = 0;
                        for (int k = 0; k < bigboi->nr_inrolari; k++) {
                            if (bigboi->inrolari[k].id_student == bigboi->studenti[j].id) {
                                grades += bigboi->inrolari[k].note[NOTA_LABORATOR] +
                                bigboi->inrolari[k].note[NOTA_PARTIAL] + bigboi->inrolari[k].note[NOTA_FINAL];
                                courses_count++;
                            }
                        }
                        if (courses_count > 0) {
                            float avg = grades / (float)courses_count;
                            int rounded = (int)(avg * ROUNDING_PRECISION + INCREMENT);
                            bigboi->studenti[j].medie_generala = ((float)rounded / ROUNDING_PRECISION);

                            #ifdef DEBUG
                            printf("STUDENT %d: AVG: %f ROUNDED AVG: %d Value to insert: %f\n",
                            bigboi->studenti[i].id, avg, rounded, (float)rounded / ROUNDING_PRECISION);
                            #endif
                        }
                    }
                }
            } else if (strcmp(column_to_update, "id_student") == 0) {
                if (conditions_met) {
                    bigboi->inrolari[i].id_student = atoi(value_to_assign);
                }
            } else if (strcmp(column_to_update, "id_materie") == 0) {
                if (conditions_met) {
                    bigboi->inrolari[i].id_materie = atoi(value_to_assign);
                }
            } else {
                fprintf(stderr, "Invalid column name.");
                exit(EXIT_FAILURE);
            }
        }
    } else {
        fprintf(stderr, "Invalid table name.");
        exit(EXIT_FAILURE);
    }
}

void handle_delete(secretariat *bigboi, char *table, int conditions_count, char **conditions) {
    #ifdef DEBUG
        printf("INSIDE HANDLE DELETE\n");
    #endif

    bool conditions_met = true;

    if (strcmp(table, "studenti") == 0) {
        for (int i = 0; i < bigboi->nr_studenti; i++) {
            conditions_met = true;

            // First check if the conditions are met
            for (int j = 0; j < conditions_count; j++) {
                // We need to copy the condition because strtok modifies the string
                char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                #ifdef DEBUG
                    printf("INSIDE HANDLE DELETE. CONDITION READ: %s\n", condition);
                #endif

                char *condition_column = strtok(condition, " ");
                char *condition_operator = strtok(NULL, " ");
                char *condition_value = strtok(NULL, "\0");

                #ifdef DEBUG
                    printf(
                    "INSIDE HANDLE DELETE. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                    condition_column, condition_operator, condition_value);
                #endif

                bool curr_condition_met = check_conditions(condition_column, condition_operator, condition_value,
                STUDENTS_TABLE, bigboi->studenti[i]);

                conditions_met = curr_condition_met && conditions_met;
                free(condition);
            }
            if (conditions_met) {
                // First remove the student's enrollments
                for (int j = 0; j < bigboi->nr_inrolari; j++) {
                    #ifdef DEBUG
                        printf("PROBLEMATIC ZONE: i = %d, j = %d\n", i, j);
                        printf("Student %d: %d %s %d %c %.2f\n", bigboi->studenti[i].id, bigboi->studenti[i].id,
                        bigboi->studenti[i].nume, bigboi->studenti[i].an_studiu, bigboi->studenti[i].statut,
                        bigboi->studenti[i].medie_generala);
                        printf("Enrollment %d: %d %d %.2f %.2f %.2f\n", bigboi->inrolari[j].id_student,
                        bigboi->inrolari[j].id_student, bigboi->inrolari[j].id_materie,
                        bigboi->inrolari[j].note[NOTA_LABORATOR], bigboi->inrolari[j].note[NOTA_PARTIAL],
                        bigboi->inrolari[j].note[NOTA_FINAL]);
                    #endif

                    if (bigboi->inrolari[j].id_student == bigboi->studenti[i].id) {
                        // Could have called handle_delete here but it would be much more expensive
                        #ifdef DEBUG
                            printf("ANOTHER PROBLEMATIC ZONE. i = %d, j = %d\n", i, j);
                            printf("INSIDE HANDLE DELETE. Deleting enrollment %d %d %.2f %.2f %2.f\n",
                            bigboi->inrolari[j].id_student, bigboi->inrolari[j].id_materie,
                            bigboi->inrolari[j].note[NOTA_LABORATOR], bigboi->inrolari[j].note[NOTA_PARTIAL],
                            bigboi->inrolari[j].note[NOTA_FINAL]);
                        #endif

                        for (int k = j; k < bigboi->nr_inrolari - 1; k++) {
                            bigboi->inrolari[k] = bigboi->inrolari[k + 1];
                        }
                        bigboi->nr_inrolari--;

                        #ifdef DEBUG
                            printf("Enrollments count: %d\n", bigboi->nr_inrolari);
                        #endif

                        inrolare *temp = NULL;
                        temp = realloc(bigboi->inrolari, bigboi->nr_inrolari * sizeof(inrolare));
                        if (temp == NULL && bigboi->nr_inrolari > 0) {
                            fprintf(stderr, "Error reallocating memory for enrollments.");
                            exit(EXIT_FAILURE);
                        }
                        bigboi->inrolari = temp;
                        j--;  // We need to decrement j because we just deleted an enrollment
                    }
                }

                // Now delete the student
                #ifdef DEBUG
                    printf("Deleting student %d %s %d %c %.2f\nCurrent student count: %d\n", bigboi->studenti[i].id,
                    bigboi->studenti[i].nume, bigboi->studenti[i].an_studiu, bigboi->studenti[i].statut,
                    bigboi->studenti[i].medie_generala, bigboi->nr_studenti);
                #endif

                for (int j = i; j < bigboi->nr_studenti - 1; j++) {
                    bigboi->studenti[j] = bigboi->studenti[j + 1];
                }
                bigboi->nr_studenti--;

                #ifdef DEBUG
                    printf("Updated student count: %d\n", bigboi->nr_studenti);
                #endif

                student *temp = NULL;
                temp = realloc(bigboi->studenti, bigboi->nr_studenti * sizeof(student));
                if (temp == NULL) {
                    fprintf(stderr, "Error reallocating memory for students.");
                    exit(EXIT_FAILURE);
                } else {
                    bigboi->studenti = temp;
                }
            }
            // i--;  // We need to decrement i because we just deleted a student(or do we?)
        }
    } else if (strcmp(table, "materii") == 0) {
        for (int i = 0; i < bigboi->nr_materii; i++) {
            conditions_met = true;

            // First check if the conditions are met
            for (int j = 0; j < conditions_count; j++) {
                // We need to copy the condition because strtok modifies the string
                char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                #ifdef DEBUG
                    printf("INSIDE HANDLE DELETE. CONDITION READ: %s\n", condition);
                #endif

                char *condition_column = strtok(condition, " ");
                char *condition_operator = strtok(NULL, " ");
                char *condition_value = strtok(NULL, "\0");

                #ifdef DEBUG
                    printf(
                    "INSIDE HANDLE DELETE. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                    condition_column, condition_operator, condition_value);
                #endif

                bool curr_condition_met = check_conditions(condition_column, condition_operator, condition_value,
                COURSES_TABLE, bigboi->materii[i]);

                conditions_met = curr_condition_met && conditions_met;
                free(condition);
            }
            if (conditions_met) {
                // First we need to delete the enrollments associated with this course
                for (int j = 0; j < bigboi->nr_inrolari; j++) {
                    if (bigboi->inrolari[j].id_materie == bigboi->materii[i].id) {
                        #ifdef DEBUG
                            printf("INSIDE HANDLE DELETE. Deleting enrollment %d %d %.2f %.2f %.2f\n",
                            bigboi->inrolari[j].id_student, bigboi->inrolari[j].id_materie,
                            bigboi->inrolari[j].note[NOTA_LABORATOR], bigboi->inrolari[j].note[NOTA_PARTIAL],
                            bigboi->inrolari[j].note[NOTA_FINAL]);
                        #endif

                        for (int k = j; k < bigboi->nr_inrolari - 1; k++) {
                            bigboi->inrolari[k] = bigboi->inrolari[k + 1];
                        }
                        bigboi->nr_inrolari--;

                        if (bigboi->nr_inrolari > 0) {
                            inrolare *temp = NULL;
                            temp = realloc(bigboi->inrolari, bigboi->nr_inrolari * sizeof(inrolare));
                            if (temp == NULL) {
                                fprintf(stderr, "Error reallocating memory for enrollments.");
                                exit(EXIT_FAILURE);
                            } else {
                                bigboi->inrolari = temp;
                            }
                        } else {
                            free(bigboi->inrolari);
                            bigboi->inrolari = NULL;
                        }
                        j--;  // We need to decrement j because we just deleted an enrollment
                    }
                }
                // First free the names in the course
                free(bigboi->materii[i].nume);
                bigboi->materii[i].nume = NULL;
                free(bigboi->materii[i].nume_titular);
                bigboi->materii[i].nume_titular = NULL;
                // Delete the course by shifting the rest of the courses to the left
                for (int j = i; j < bigboi->nr_materii - 1; j++) {
                    bigboi->materii[j] = bigboi->materii[j + 1];
                }
                bigboi->nr_materii--;

                if (bigboi->nr_materii > 0) {
                    materie *temp = NULL;
                    temp = realloc(bigboi->materii, bigboi->nr_materii * sizeof(materie));
                    if (temp == NULL) {
                        fprintf(stderr, "Error reallocating memory for courses.");
                        exit(EXIT_FAILURE);
                    } else {
                        bigboi->materii = temp;
                    }
                } else {
                    free(bigboi->materii);
                    bigboi->materii = NULL;
                }
                i--;  // We need to decrement i because we just deleted a course
            }
        }
    } else if (strcmp(table, "inrolari") == 0) {
        for (int i = 0; i < bigboi->nr_inrolari; i++) {
            conditions_met = true;

            // First check if the conditions are met
            for (int j = 0; j < conditions_count; j++) {
                // We need to copy the condition because strtok modifies the string
                char *condition = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                snprintf(condition, MAX_CONDITION_LENGTH, "%s", conditions[j]);

                #ifdef DEBUG
                    printf("INSIDE HANDLE DELETE. CONDITION READ: %s\n", condition);
                #endif

                char *condition_column = strtok(condition, " ");
                char *condition_operator = strtok(NULL, " ");
                char *condition_value = strtok(NULL, "\0");

                #ifdef DEBUG
                    printf(
                    "INSIDE HANDLE DELETE. CONDITION TO BE PASSED TO CHECK_CONDITIONS: %s %s %s\n",
                    condition_column, condition_operator, condition_value);
                #endif

                bool curr_condition_met = check_conditions(condition_column, condition_operator, condition_value,
                ENROLLMENTS_TABLE, bigboi->inrolari[i]);

                conditions_met = curr_condition_met && conditions_met;
                free(condition);
            }
            if (conditions_met) {
                // Delete the enrollment
                for (int j = i; j < bigboi->nr_inrolari - 1; j++) {
                    bigboi->inrolari[j] = bigboi->inrolari[j + 1];
                }
                bigboi->nr_inrolari--;
                inrolare *temp = NULL;
                temp = realloc(bigboi->inrolari, bigboi->nr_inrolari * sizeof(inrolare));
                if (temp == NULL) {
                    fprintf(stderr, "Error reallocating memory for enrollments.");
                    exit(EXIT_FAILURE);
                } else {
                    bigboi->inrolari = temp;
                }
                i--;  // We need to decrement i because we just deleted an enrollment
            }
        }
    } else {
        fprintf(stderr, "Invalid table name.");
        exit(EXIT_FAILURE);
    }
    // Recalculate the students' GPAs
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
        if (courses_count > 0) {
            float avg = grades / (float)courses_count;

            int rounded = (int)(avg * ROUNDING_PRECISION + INCREMENT);
            bigboi->studenti[i].medie_generala = ((float)rounded / ROUNDING_PRECISION);

            #ifdef DEBUG
                printf("STUDENT %d: AVG: %f ROUNDED AVG: %d Value to insert in medie_generala: %f\n",
                bigboi->studenti[i].id, avg, rounded, (float)rounded / ROUNDING_PRECISION);
            #endif
        } else {
            bigboi->studenti[i].medie_generala = 0;
        }
    }
}

void process_command(secretariat *bigboi, char command[]) {
    char *table = malloc(sizeof(char) * MAX_TABLE_NAME_LENGTH);

    // We need to split the command into words
    // The first word is the command type and is separated by a space
    char *word_in_command = strtok(command, " ");
    char command_type[MAX_COMAMND_TYPE_LENGTH];
    snprintf(command_type, MAX_COMAMND_TYPE_LENGTH, "%s", word_in_command);
    if (strcmp(command_type, "SELECT") == 0) {
        // we are in the SELECT command

        // The selected columns will be represented by a vector (**selected)columns) of strings (*selected_columns)
        int selected_columns_count = 0;
        char **selected_columns = malloc(sizeof(char*));

        // Get columns until FROM
        while (word_in_command != NULL && strcmp(word_in_command, "FROM") != 0) {
            // Found a column, add it to the vector
            selected_columns_count++;

            if (selected_columns_count == 1) {
                // For the first column we change the separator (" " -> ", ")
                word_in_command = strtok(NULL, ", ");
            }

            // If there are more words, we need to allocate more memory

            // Sanity check
            char **temp = NULL;
            temp = realloc(selected_columns, (selected_columns_count + 1) * sizeof(char**));
            if (temp) {
                selected_columns = temp;
                selected_columns[selected_columns_count - 1] = malloc(MAX_COLUMN_NAME_LENGTH * sizeof(char));
            } else {
                fprintf(stderr, "Error reallocating memory for a new selected column\n");
                exit(EXIT_FAILURE);
            }

            // Add the column name to the vector
            snprintf(selected_columns[selected_columns_count - 1], MAX_COLUMN_NAME_LENGTH, "%s", word_in_command);
            word_in_command = strtok(NULL, ", ");
        }

        #ifdef DEBUG
            printf("INSIDE PROCESS COMMAND. Selected columns:\n");
            for (int i = 0; i < selected_columns_count; i++) {
                printf("%s\n", selected_columns[i]);
            }
        #endif

        // Read the table from which we will select
        if (word_in_command == NULL) {  // Little syntax checking
            fprintf(stderr, "Expected 'FROM' after column names\n");
            exit(EXIT_FAILURE);
        } else if (strcmp(word_in_command, "FROM") == 0) {
            word_in_command = strtok(NULL, " ");  // Consume the 'FROM'
        }

        // At this point, "word_in_command" is the table name
        word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon (;) if present
        snprintf(table, MAX_TABLE_NAME_LENGTH, "%s", word_in_command);

        // If there are no more words in the command, we print the selected columns
        word_in_command = strtok(NULL, " ");
        if (word_in_command == NULL) {
            handle_select(bigboi, table, selected_columns, selected_columns_count, 0, NULL);
        } else if (strcmp(word_in_command, "WHERE") == 0) {
            #ifdef DEBUG
                printf("INSIDE PROCESS COMMAND. BEGIN FILTERED SELECT\n");
            #endif

            // If the next word in the command is "WHERE", we need to call the function for a filtered SELECT

            char *condition_column = malloc(MAX_COLUMN_NAME_LENGTH * sizeof(char));
            char *condition_operator = malloc(MAX_OPERATOR_LENGTH * sizeof(char));
            char *condition_value = malloc(MAX_VALUE_LENGTH * sizeof(char));

            //  Creating an array to store the conditions
            char **conditions = NULL;
            int conditions_count = 0;

            word_in_command = strtok(NULL, " ");  // Consume the 'WHERE'

            while (word_in_command != NULL) {
                conditions_count++;

                // If this isn't the first condition, check the presence of the AND operator
                if (conditions_count > 1) {
                    if (strcmp(word_in_command, "AND") != 0) {
                        fprintf(stderr, "Error: Invalid syntax. Expected 'AND' after a condition.\n");
                        exit(EXIT_FAILURE);
                    } else {
                        word_in_command = strtok(NULL, " ");  // Consume the 'AND'
                    }
                }

                // For each condition, we need to allocate more memory
                if (conditions_count == 1) {
                    conditions = malloc(sizeof(char*));
                    conditions[0] = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                } else {
                    // Sanity check
                    char **temp = NULL;
                    temp = realloc(conditions, (conditions_count + 1) * sizeof(char*));
                    if (temp) {
                        conditions = temp;
                        conditions[conditions_count - 1] = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                        if (!conditions[conditions_count - 1]) {  // Sanity check :)))))
                            fprintf(stderr, "Error allocating memory for a new condition\n");
                            exit(EXIT_FAILURE);
                        }
                    } else {
                        fprintf(stderr, "Error reallocating memory for a new condition\n");
                        exit(EXIT_FAILURE);
                    }
                }

                // Add the condition to the array
                snprintf(condition_column, MAX_COLUMN_NAME_LENGTH, "%s", word_in_command);
                word_in_command = strtok(NULL, " ");  // Get the operator
                snprintf(condition_operator, MAX_OPERATOR_LENGTH, "%s", word_in_command);

                // Get the value. This one is tricky because the value can be multiple words
                if ((strcmp(condition_column, "nume") == 0 && strcmp(table, "studenti") == 0) ||
                strcmp(condition_column, "nume_titular") == 0) {
                    // Reading two words

                    #ifdef DEBUG
                        printf("INSIDE PROCESS COMMAND. READING TWO WORDS\n");
                    #endif

                    char *name_word1 = malloc(MAX_VALUE_LENGTH * sizeof(char));
                    char *name_word2 = malloc(MAX_VALUE_LENGTH * sizeof(char));

                    if (!name_word1 || !name_word2) {  // Sanity check :)))))
                        fprintf(stderr, "Error allocating memory for a name words\n");
                        exit(EXIT_FAILURE);
                    }

                    word_in_command = strtok(NULL, " ");  // First word
                    snprintf(name_word1, MAX_VALUE_LENGTH, "%s", word_in_command);
                    word_in_command = strtok(NULL, " ");  // Second word

                    // Remove the semicolon (;) if present, otherwise proceed (with an AND)
                    char *semicolon_pos = strchr(word_in_command, ';');
                    if (semicolon_pos) {
                        *semicolon_pos = '\0';
                    }
                    snprintf(name_word2, MAX_VALUE_LENGTH, "%s", word_in_command);
                    snprintf(condition_value, MAX_VALUE_LENGTH, "%s %s", name_word1, name_word2);

                    free(name_word1);
                    free(name_word2);

                    // Advance if didn't find a semicolon
                    if (!semicolon_pos) {
                        word_in_command = strtok(NULL, " ");
                    }
                } else if (strcmp(condition_column, "note") == 0) {
                    // Reading three numbers (words)

                    #ifdef DEBUG
                        printf("INSIDE PROCESS COMMAND. READING THREE WORDS\n");
                    #endif

                    char *nota_laborator = malloc(MAX_GRADE_LENGTH * sizeof(char));
                    char *nota_partial = malloc(MAX_GRADE_LENGTH * sizeof(char));
                    char *nota_final = malloc(MAX_GRADE_LENGTH * sizeof(char));

                    word_in_command = strtok(NULL, " ");  // First grade
                    snprintf(nota_laborator, MAX_GRADE_LENGTH, "%s", word_in_command);
                    word_in_command = strtok(NULL, " ");  // Second grade
                    snprintf(nota_partial, MAX_GRADE_LENGTH, "%s", word_in_command);
                    word_in_command = strtok(NULL, " ");  // Third grade

                    // Remove the semicolon (;) if present, otherwise proceed (with an AND)
                    char *semicolon_pos = strchr(word_in_command, ';');
                    if (semicolon_pos) {
                        *semicolon_pos = '\0';
                    }

                    snprintf(nota_final, MAX_GRADE_LENGTH, "%s", word_in_command);
                    snprintf(condition_value, MAX_VALUE_LENGTH, "%.2f %.2f %.2f", atof(nota_laborator),
                    atof(nota_partial), atof(nota_final));

                    free(nota_laborator);
                    free(nota_partial);
                    free(nota_final);

                    // Advance if didn't find a semicolon
                    if (!semicolon_pos) {
                        word_in_command = strtok(NULL, " ");
                    }
                } else {
                    // Reading one word
                    word_in_command = strtok(NULL, " ");
                    word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon (;) if present
                    snprintf(condition_value, MAX_VALUE_LENGTH, "%s", word_in_command);
                }

                snprintf(conditions[conditions_count - 1], MAX_CONDITION_LENGTH, "%s %s %s",
                condition_column, condition_operator, condition_value);
                // Get the next condition or NULL if there are no more conditions
                word_in_command = strtok(NULL, " ");

                #ifdef DEBUG
                    printf("Condition %d: %s\n", conditions_count, conditions[conditions_count - 1]);
                #endif
            }
            #ifdef DEBUG
                printf("INSIDE PROCESS SELECT. Conditions:\n");
                for (int i = 0; i < conditions_count; i++) {
                    printf("%s\n", conditions[i]);
                }
            #endif
            handle_select(bigboi, table, selected_columns, selected_columns_count, conditions_count, conditions);

            // Free the memory allocated for the conditions
            for (int i = 0; i < conditions_count; i++) {
                free(conditions[i]);
            }
            free(conditions);
            free(condition_column);
            free(condition_operator);
            free(condition_value);
        }
        // Free the memory allocated for the selected columns
        for (int i = 0; i < selected_columns_count; i++) {
            free(selected_columns[i]);
        }
        free(selected_columns);

    } else if (strcmp(command_type, "UPDATE") == 0) {
        #ifdef DEBUG
            printf("INSIDE PROCESS COMMAND. COMMAND IS UPDATE\n");
        #endif

        word_in_command = strtok(NULL, " ");  // Get the table name
        snprintf(table, MAX_TABLE_NAME_LENGTH, "%s", word_in_command);

        #ifdef DEBUG
            printf("Table to be updated: %s\n", table);
        #endif

        word_in_command = strtok(NULL, " ");  // Get the SET keyword
        if (strcmp(word_in_command, "SET") != 0) {
            fprintf(stderr, "Error: Expected SET keyword after table name.\n");
            exit(EXIT_FAILURE);
        }

        word_in_command = strtok(NULL, " ");  // Consume the SET keyword. Get the column to be updated
        char *column_to_update = malloc(MAX_COLUMN_NAME_LENGTH * sizeof(char));
        snprintf(column_to_update, MAX_COLUMN_NAME_LENGTH, "%s", word_in_command);

        #ifdef DEBUG
            printf("Column to be updated: %s\n", column_to_update);
        #endif

        word_in_command = strtok(NULL, " ");  // Get the assignment operator (=)
        if (strcmp(word_in_command, "=") != 0) {
            fprintf(stderr, "Error: Expected assignment operator (=) after column name.\n");
            exit(EXIT_FAILURE);
        }

        char *value_to_assign = malloc(MAX_VALUE_LENGTH * sizeof(char));
        if ((strcmp(column_to_update, "nume") == 0 && strcmp(table, "studenti") == 0) ||
        strcmp(column_to_update, "nume_titular") == 0) {
            // Reading two words
            char *surname = malloc(MAX_VALUE_LENGTH * sizeof(char));
            char *name = malloc(MAX_VALUE_LENGTH * sizeof(char));
            word_in_command = strtok(NULL, " ");  // Get the surname
            if (strcspn(word_in_command, "\"") == 0) {  // If the word starts with a quotation mark (")
                snprintf(surname, MAX_VALUE_LENGTH, "%s", word_in_command + 1);  // Remove it
            } else {
                snprintf(surname, MAX_VALUE_LENGTH, "%s", word_in_command);
            }

            word_in_command = strtok(NULL, " ");  // Get the name
            word_in_command[strcspn(word_in_command, "\"")] = '\0';  // Remove the quotation marks (") if present

            snprintf(name, MAX_VALUE_LENGTH, "%s", word_in_command);

            // Concatenate the words into a single string and store it in value_to_assign
            snprintf(value_to_assign, MAX_VALUE_LENGTH, "%s %s", surname, name);

            free(surname);
            free(name);
        } else if (strcmp(column_to_update, "note") == 0) {
            // Reading three numbers(words)
            char *lab_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));
            word_in_command = strtok(NULL, " ");  // Get the first grade
            snprintf(lab_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

            char *midterm_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));
            word_in_command = strtok(NULL, " ");  // Get the second grade
            snprintf(midterm_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

            char *final_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));
            word_in_command = strtok(NULL, " ");  // Get the third grade
            snprintf(final_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

            // Concatenate the grades into a single string and store it in value_to_assign
            snprintf(value_to_assign, MAX_VALUE_LENGTH, "%.2f %.2f %.2f", (float)atof(lab_grade),
            (float)atof(midterm_grade), (float)atof(final_grade));

            free(lab_grade);
            free(midterm_grade);
            free(final_grade);
        } else {
            // Reading one word
            word_in_command = strtok(NULL, " ");  // Get the value to be assigned
            snprintf(value_to_assign, MAX_VALUE_LENGTH, "%s", word_in_command);
        }

        #ifdef DEBUG
            printf("Value to be assigned: %s\n", value_to_assign);
        #endif

        word_in_command = strtok(NULL, " ");  // Get the WHERE keyword
        if (strcmp(word_in_command, "WHERE") != 0) {
            fprintf(stderr, "Error: Expected WHERE keyword after assignment.\n");
            exit(EXIT_FAILURE);
        }
        word_in_command = strtok(NULL, " ");  // Consume the WHERE keyword

        char **conditions = NULL;
        int conditions_count = 0;

        while (word_in_command != NULL) {
            conditions_count++;
            if (conditions_count > 1) {  // Expected AND keyword
                if (strcmp(word_in_command, "AND") != 0) {
                    fprintf(stderr, "Error: Expected AND keyword after condition.\n");
                    exit(EXIT_FAILURE);
                } else {
                    word_in_command = strtok(NULL, " ");  // Consume the AND
                    char **temp = NULL;
                    temp = realloc(conditions, (conditions_count) * sizeof(char *));
                    if (temp != NULL) {
                        conditions = temp;
                        conditions[conditions_count - 1] = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                    } else {
                        fprintf(stderr, "Failed reallocating memory for the conditions.\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }

            if (conditions_count == 1) {
                // For the first condition allocate memory
                conditions = malloc(sizeof(char *));
                conditions[0] = malloc(MAX_CONDITION_LENGTH * sizeof(char));
            }

            char *condition_column = malloc(MAX_COLUMN_NAME_LENGTH * sizeof(char));
            char *condition_operator = malloc(MAX_OPERATOR_LENGTH * sizeof(char));
            char *condition_value = malloc(MAX_VALUE_LENGTH * sizeof(char));
            // Get the condition
            snprintf(condition_column, MAX_COLUMN_NAME_LENGTH, "%s", word_in_command);  // Column name
            word_in_command = strtok(NULL, " ");  // Operator
            snprintf(condition_operator, MAX_OPERATOR_LENGTH, "%s", word_in_command);

            // Get the value
            if ((strcmp(condition_column, "nume") == 0 && strcmp(table, "studenti") == 0) ||
            strcmp(condition_column, "nume_titular") == 0) {
                // Reading two words
                char *surname = malloc(MAX_VALUE_LENGTH * sizeof(char));
                char *name = malloc(MAX_VALUE_LENGTH * sizeof(char));
                word_in_command = strtok(NULL, " ");  // Get the surname
                snprintf(surname, MAX_VALUE_LENGTH, "%s", word_in_command);

                word_in_command = strtok(NULL, " ");  // Get the name
                word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon if present
                snprintf(name, MAX_VALUE_LENGTH, "%s", word_in_command);

                // Concatenate the surname and name into a single string and store it in condition_value
                snprintf(condition_value, MAX_VALUE_LENGTH, "%s %s", surname, name);
            } else if (strcmp(condition_column, "note") == 0) {
                // Reading three numbers(words)
                char *lab_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));
                char *midterm_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));
                char *final_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));

                word_in_command = strtok(NULL, " ");  // Get the first grade
                snprintf(lab_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

                word_in_command = strtok(NULL, " ");  // Get the second grade
                snprintf(midterm_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

                word_in_command = strtok(NULL, " ");  // Get the third grade
                word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon if present
                snprintf(final_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

                // Concatenate the grades into a single string and store it in condition_value
                snprintf(condition_value, MAX_VALUE_LENGTH, "%.2f %.2f %.2f", (float)atof(lab_grade),
                (float)atof(midterm_grade), (float)atof(final_grade));
            } else {
                // Reading one word
                word_in_command = strtok(NULL, " ");
                word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon (;) if present
                snprintf(condition_value, MAX_VALUE_LENGTH, "%s", word_in_command);
            }

            word_in_command = strtok(NULL, " ");  // Get the next word or NULL

            // Concatenate the condition into a single string and store it in conditions
            snprintf(conditions[conditions_count - 1], MAX_CONDITION_LENGTH, "%s %s %s", condition_column,
            condition_operator, condition_value);

            #ifdef DEBUG
                printf("Condition for UPDATE: %s %s %s\n", condition_column, condition_operator, condition_value);
            #endif
            free(condition_column);
            free(condition_operator);
            free(condition_value);
        }

        handle_update(bigboi, table, column_to_update, value_to_assign, conditions_count, conditions);

        free(column_to_update);
        free(value_to_assign);
        for (int i = 0; i < conditions_count; i++) {
            free(conditions[i]);
        }
        free(conditions);
    } else if (strcmp(command_type, "DELETE") == 0) {
        #ifdef DEBUG
            printf("INSIDE PROCESS COMMAND. COMMAND IS DELETE\n");
        #endif

        word_in_command = strtok(NULL, " ");  // Must be FROM
        if (strcmp(word_in_command, "FROM") != 0) {
            fprintf(stderr, "Error: Expected FROM keyword after DELETE.\n");
            exit(EXIT_FAILURE);
        }
        word_in_command = strtok(NULL, " ");  // Get the table name
        snprintf(table, MAX_TABLE_NAME_LENGTH, "%s", word_in_command);

        #ifdef DEBUG
            printf("Table name: %s\n", table);
        #endif

        word_in_command = strtok(NULL, " ");  // Get the WHERE keyword
        if (strcmp(word_in_command, "WHERE") != 0) {
            fprintf(stderr, "Error: Expected WHERE keyword after DELETE.\n");
            exit(EXIT_FAILURE);
        }

        word_in_command = strtok(NULL, " ");  // Consume the WHERE keyword. Get the conditions

        char **conditions = NULL;
        int conditions_count = 0;

        while (word_in_command != NULL) {
            conditions_count++;
            if (conditions_count > 1) {  // Expected AND keyword
                if (strcmp(word_in_command, "AND") != 0) {
                    fprintf(stderr, "Error: Expected AND keyword after condition.\n");
                    exit(EXIT_FAILURE);
                } else {
                    word_in_command = strtok(NULL, " ");  // Consume the AND
                    char **temp = NULL;
                    temp = realloc(conditions, (conditions_count) * sizeof(char *));
                    if (temp != NULL) {
                        conditions = temp;
                        conditions[conditions_count - 1] = malloc(MAX_CONDITION_LENGTH * sizeof(char));
                    } else {
                        fprintf(stderr, "Failed reallocating memory for the conditions.\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }

            if (conditions_count == 1) {
                // For the first condition allocate memory
                conditions = malloc(sizeof(char *));
                conditions[0] = malloc(MAX_CONDITION_LENGTH * sizeof(char));
            }

            char *condition_column = malloc(MAX_COLUMN_NAME_LENGTH * sizeof(char));
            char *condition_operator = malloc(MAX_OPERATOR_LENGTH * sizeof(char));
            char *condition_value = malloc(MAX_VALUE_LENGTH * sizeof(char));
            // Get the condition
            snprintf(condition_column, MAX_COLUMN_NAME_LENGTH, "%s", word_in_command);  // Column name
            word_in_command = strtok(NULL, " ");  // Operator
            snprintf(condition_operator, MAX_OPERATOR_LENGTH, "%s", word_in_command);

            // Get the value
            if ((strcmp(condition_column, "nume") == 0 && strcmp(table, "studenti") == 0) ||
            strcmp(condition_column, "nume_titular") == 0) {
                // Reading two words
                char *surname = malloc(MAX_VALUE_LENGTH * sizeof(char));
                char *name = malloc(MAX_VALUE_LENGTH * sizeof(char));
                word_in_command = strtok(NULL, " ");  // Get the surname
                snprintf(surname, MAX_VALUE_LENGTH, "%s", word_in_command);

                word_in_command = strtok(NULL, " ");  // Get the name
                word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon if present
                snprintf(name, MAX_VALUE_LENGTH, "%s", word_in_command);

                // Concatenate the surname and name into a single string and store it in condition_value
                snprintf(condition_value, MAX_VALUE_LENGTH, "%s %s", surname, name);
            } else if (strcmp(condition_column, "note") == 0) {
                // Reading three numbers(words)
                char *lab_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));
                char *midterm_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));
                char *final_grade = malloc(MAX_GRADE_LENGTH * sizeof(char));

                word_in_command = strtok(NULL, " ");  // Get the first grade
                snprintf(lab_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

                word_in_command = strtok(NULL, " ");  // Get the second grade
                snprintf(midterm_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

                word_in_command = strtok(NULL, " ");  // Get the third grade
                word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon if present
                snprintf(final_grade, MAX_GRADE_LENGTH, "%s", word_in_command);

                // Concatenate the grades into a single string and store it in condition_value
                snprintf(condition_value, MAX_VALUE_LENGTH, "%.2f %.2f %.2f", (float)atof(lab_grade),
                (float)atof(midterm_grade), (float)atof(final_grade));
            } else {
                // Reading one word
                word_in_command = strtok(NULL, " ");
                word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon (;) if present
                snprintf(condition_value, MAX_VALUE_LENGTH, "%s", word_in_command);
            }

            word_in_command = strtok(NULL, " ");  // Get the next word or NULL

            // Concatenate the condition into a single string and store it in conditions
            snprintf(conditions[conditions_count - 1], MAX_CONDITION_LENGTH, "%s %s %s", condition_column,
            condition_operator, condition_value);

            #ifdef DEBUG
                printf("Condition for DELETE: %s %s %s\n", condition_column, condition_operator, condition_value);
            #endif

            free(condition_column);
            free(condition_operator);
            free(condition_value);
        }
        handle_delete(bigboi, table, conditions_count, conditions);
        for (int i = 0; i < conditions_count; i++) {
            free(conditions[i]);
        }
        free(conditions);
    }

    // Free the memory allocated for the table name
    free(table);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    secretariat *bigboi = citeste_secretariat(argv[1]);

    int command_count = 0;
    scanf("%d", &command_count);
    getchar();  // Consume the newline character left by scanf (really annoying)

    for (int i = 0; i < command_count; i++) {
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0;  // remove trailing newline
        process_command(bigboi, command);
    }
    elibereaza_secretariat(&bigboi);
    return 0;
}
