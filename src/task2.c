#include "task2.h"
#include <stdarg.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_COMAMND_TYPE_LENGTH 10
#define MAX_COLUMN_NAME_LENGTH 15
#define STUDENTS_TABLE_COLUMNS 5
#define COURSES_TABLE_COLUMNS 3
#define ENROLLMENTS_TABLE_COLUMNS 3

/*
    Pentru task-ul 2, baza de date va fi citită dintr-un fișier primit ca argument în linia de comandă,
    iar comenzile vor fi introduse de la tastatură în următorul format:
    numărul_de_comenzi
    comanda1
    comanda2
    ...
*/

void handle_select(secretariat *bigboi, char *table, char **selected_columns, int selected_columns_count, ...) {
    if (strcmp(table, "studenti") == 0) {
        for (int i = 0; i < bigboi->nr_studenti; i++) {
            if (strcmp(selected_columns[0], "*") == 0) {
                // Print all columns
                printf("%d %s %d %c %.2f\n", bigboi->studenti[i].id, bigboi->studenti[i].nume,
                bigboi->studenti[i].an_studiu, bigboi->studenti[i].statut, bigboi->studenti[i].medie_generala);
                continue;
            }
            for (int j = 0; j < selected_columns_count; j++) {
                if (strcmp(selected_columns[j], "id") == 0) {
                    printf("%d", bigboi->studenti[i].id);
                } else if (strcmp(selected_columns[j], "nume") == 0) {
                    printf("%s", bigboi->studenti[i].nume);
                } else if (strcmp(selected_columns[j], "an_studiu") == 0) {
                    printf("%d", bigboi->studenti[i].an_studiu);
                } else if (strcmp(selected_columns[j], "statut") == 0) {
                    printf("%c", bigboi->studenti[i].statut);
                } else if (strcmp(selected_columns[j], "medie_generala") == 0) {
                    printf("%.2f", bigboi->studenti[i].medie_generala);
                }

                // Print a space after each column, except for the last one
                if (j != selected_columns_count - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    } else if (strcmp(table, "materii") == 0) {
        for (int i = 0; i < bigboi->nr_materii; i++) {
            if (strcmp(selected_columns[0], "*") == 0) {
                // Print all columns
                printf("%d %s %s\n", bigboi->materii[i].id, bigboi->materii[i].nume, bigboi->materii[i].nume_titular);
                continue;
            }
            for (int j = 0; j < selected_columns_count; j++) {
                if (strcmp(selected_columns[j], "id") == 0) {
                    printf("%d", bigboi->materii[i].id);
                } else if (strcmp(selected_columns[j], "nume") == 0) {
                    printf("%s", bigboi->materii[i].nume);
                } else if (strcmp(selected_columns[j], "nume_titular") == 0) {
                    printf("%s", bigboi->materii[i].nume_titular);
                }

                // Print a space after each column, except for the last one
                if  (j != selected_columns_count - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    } else if (strcmp(table, "inrolari") == 0) {
        for (int i = 0; i < bigboi->nr_inrolari; i++) {
            if (strcmp(selected_columns[0], "*") == 0) {
                // Print all columns
                printf("%d %d %.2f %.2f %.2f\n", bigboi->inrolari[i].id_student, bigboi->inrolari[i].id_materie,
                bigboi->inrolari[i].note[NOTA_LABORATOR], bigboi->inrolari[i].note[NOTA_PARTIAL],
                bigboi->inrolari[i].note[NOTA_FINAL]);
                continue;
            }
            for (int j = 0; j < selected_columns_count; j++) {
                if (strcmp(selected_columns[j], "id_student") == 0) {
                    printf("%d", bigboi->inrolari[i].id_student);
                } else if (strcmp(selected_columns[j], "id_materie") == 0) {
                    printf("%d", bigboi->inrolari[i].id_materie);
                } else if (strcmp(selected_columns[j], "note") == 0) {
                    printf("%.2f %.2f %.2f", bigboi->inrolari[i].note[NOTA_LABORATOR],
                    bigboi->inrolari[i].note[NOTA_PARTIAL],
                    bigboi->inrolari[i].note[NOTA_FINAL]);
                }
                // Print a space after each column, except for the last one
                if (j != selected_columns_count - 1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

void handle_update(char *table, char *column, char *value, char *where) {
}

void handle_delete(char *table, char *where) {
}

void process_command(secretariat *bigboi, char command[]) {
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

        // Read the table from which we will select
        word_in_command = strtok(NULL, " ");  // Consume the 'FROM'
        word_in_command[strcspn(word_in_command, ";")] = '\0';  // Remove the semicolon (;)

        // At this point, "word_in_command" is the table name
        handle_select(bigboi, word_in_command, selected_columns, selected_columns_count);

        // Free the memory allocated for the selected columns
        for (int i = 0; i < selected_columns_count; i++) {
            free(selected_columns[i]);
        }
        free(selected_columns);
    } else if (strcmp(command_type, "UPDATE") == 0) {
        // UPDATE
        printf("COMMAND IS UPDATE\n");
    } else if (strcmp(command_type, "DELETE") == 0) {
        // DELETE
        printf("COMMAND IS DELETE\n");
    }
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
