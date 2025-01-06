#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress_file(FILE *input, FILE *output);
void decompress_file(FILE *input, FILE *output);

int main() {
    int choice;
    FILE *input, *output;

    printf("File Compression Tool\n");
    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // to consume newline

        if (choice == 1) {
            char input_filename[100], output_filename[100];
            printf("Enter input file name: ");
            fgets(input_filename, 100, stdin);
            input_filename[strcspn(input_filename, "\n")] = 0;  // Remove newline

            printf("Enter output file name: ");
            fgets(output_filename, 100, stdin);
            output_filename[strcspn(output_filename, "\n")] = 0;  // Remove newline

            input = fopen(input_filename, "r");
            if (input == NULL) {
                printf("Error opening input file!\n");
                continue;
            }

            output = fopen(output_filename, "w");
            if (output == NULL) {
                printf("Error opening output file!\n");
                fclose(input);
                continue;
            }

            compress_file(input, output);
            printf("File compressed successfully.\n");

            fclose(input);
            fclose(output);
        } else if (choice == 2) {
            char input_filename[100], output_filename[100];
            printf("Enter input file name: ");
            fgets(input_filename, 100, stdin);
            input_filename[strcspn(input_filename, "\n")] = 0;  // Remove newline

            printf("Enter output file name: ");
            fgets(output_filename, 100, stdin);
            output_filename[strcspn(output_filename, "\n")] = 0;  // Remove newline

            input = fopen(input_filename, "r");
            if (input == NULL) {
                printf("Error opening input file!\n");
                continue;
            }

            output = fopen(output_filename, "w");
            if (output == NULL) {
                printf("Error opening output file!\n");
                fclose(input);
                continue;
            }

            decompress_file(input, output);
            printf("File decompressed successfully.\n");

            fclose(input);
            fclose(output);
        } else if (choice == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void compress_file(FILE *input, FILE *output) {
    char current_char, prev_char;
    int count;

    prev_char = fgetc(input);
    while ((current_char = fgetc(input)) != EOF) {
        count = 1;
        while (current_char == prev_char) {
            count++;
            current_char = fgetc(input);
        }
        fprintf(output, "%c%d", prev_char, count);
        prev_char = current_char;
    }
    fprintf(output, "%c1", prev_char);  // Write the last character with count 1
}

void decompress_file(FILE *input, FILE *output) {
    char current_char;
    int count;

    while ((current_char = fgetc(input)) != EOF) {
        count = fgetc(input) - '0';  // Convert character digit to integer
        for (int i = 0; i < count; i++) {
            fputc(current_char, output);
        }
    }
}
