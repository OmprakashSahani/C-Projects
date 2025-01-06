#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void display_menu() {
    printf("\n=== Simple Text Editor ===\n");
    printf("1. Open a file\n");
    printf("2. Edit the file\n");
    printf("3. Save the file\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

void open_file(FILE **file, char *filename) {
    *file = fopen(filename, "r+");
    if (*file == NULL) {
        printf("Error opening file. It might not exist.\n");
        *file = fopen(filename, "w+");
        if (*file == NULL) {
            printf("Error creating file.\n");
            exit(1);
        }
    }
}

void read_file(FILE *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
}

void write_to_file(FILE *file, char *text) {
    fseek(file, 0, SEEK_END);  // Move the file pointer to the end
    fprintf(file, "%s", text);
}

void edit_file(FILE *file) {
    char text[MAX_LINE_LENGTH];
    printf("\nEnter text to append to the file (Ctrl+D to stop):\n");
    while (fgets(text, sizeof(text), stdin)) {
        if (strcmp(text, "Ctrl+D\n") == 0) break;  // Exit edit on Ctrl+D
        write_to_file(file, text);
        printf("Text added: %s", text);
    }
}

void save_file(FILE *file, char *filename) {
    fclose(file);
    printf("File saved successfully: %s\n", filename);
}

int main() {
    FILE *file = NULL;
    char filename[100];
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the filename to open: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0';  // Remove newline character
                open_file(&file, filename);
                printf("File opened successfully: %s\n", filename);
                break;

            case 2:
                if (file == NULL) {
                    printf("No file opened. Please open a file first.\n");
                } else {
                    printf("Editing the file...\n");
                    edit_file(file);
                }
                break;

            case 3:
                if (file == NULL) {
                    printf("No file opened. Please open a file first.\n");
                } else {
                    save_file(file, filename);
                }
                break;

            case 4:
                if (file != NULL) {
                    save_file(file, filename);
                }
                printf("Exiting the text editor. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
