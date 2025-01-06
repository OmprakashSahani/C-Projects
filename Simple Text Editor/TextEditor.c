#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile();
void readFile();
void editFile();

int main() {
    int choice;
    while (1) {
        printf("\nText Editor\n");
        printf("1. Create a New File\n");
        printf("2. Read an Existing File\n");
        printf("3. Edit a File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: editFile(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void createFile() {
    char filename[100];
    printf("Enter the name of the file to create: ");
    scanf("%s", filename);
    getchar(); // Consume newline character

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file!\n");
        return;
    }

    printf("Enter text (type 'exit' on a new line to save and close):\n");
    char line[256];
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "exit\n") == 0) break;
        fputs(line, fp);
    }
    fclose(fp);
    printf("File '%s' created successfully.\n", filename);
}

void readFile() {
    char filename[100];
    printf("Enter the name of the file to read: ");
    scanf("%s", filename);
    getchar(); // Consume newline character

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file! File may not exist.\n");
        return;
    }

    printf("Contents of '%s':\n", filename);
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void editFile() {
    char filename[100];
    printf("Enter the name of the file to edit: ");
    scanf("%s", filename);
    getchar(); // Consume newline character

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file! File may not exist.\n");
        return;
    }

    printf("Enter text to append (type 'exit' on a new line to save and close):\n");
    char line[256];
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "exit\n") == 0) break;
        fputs(line, fp);
    }
    fclose(fp);
    printf("File '%s' edited successfully.\n", filename);
}
