#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARS 100
#define MAX_VAR_NAME 20

// Define structure to hold variable information
struct Variable {
    char name[MAX_VAR_NAME];
    int value;
};

// Global list of variables
struct Variable variables[MAX_VARS];
int var_count = 0;

// Function to find a variable by name
int find_var(const char *name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;  // Return index of the variable
        }
    }
    return -1;  // Variable not found
}

// Function to add a new variable
void add_var(const char *name, int value) {
    if (var_count < MAX_VARS) {
        strcpy(variables[var_count].name, name);
        variables[var_count].value = value;
        var_count++;
    } else {
        printf("Error: Cannot add more variables.\n");
    }
}

// Function to evaluate an expression (supports +, -, *, /)
int evaluate_expression(char *expr) {
    int result = 0;
    int current_num = 0;
    char operator = '+';

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            current_num = current_num * 10 + (ch - '0');  // Build number
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (operator == '+') {
                result += current_num;
            } else if (operator == '-') {
                result -= current_num;
            } else if (operator == '*') {
                result *= current_num;
            } else if (operator == '/') {
                result /= current_num;
            }

            operator = ch;  // Update operator
            current_num = 0;  // Reset current number
        }
    }

    // Apply the last operator to the remaining current_num
    if (operator == '+') {
        result += current_num;
    } else if (operator == '-') {
        result -= current_num;
    } else if (operator == '*') {
        result *= current_num;
    } else if (operator == '/') {
        result /= current_num;
    }

    return result;
}

// Function to process and execute the command
void process_command(char *command) {
    char var_name[MAX_VAR_NAME];
    char expression[100];

    // Check if the command is an assignment
    if (sscanf(command, "%s = %99[^\n]", var_name, expression) == 2) {
        // Evaluate the expression
        int result = evaluate_expression(expression);

        // Check if the variable exists
        int var_index = find_var(var_name);
        if (var_index != -1) {
            // If variable exists, update its value
            variables[var_index].value = result;
        } else {
            // If variable doesn't exist, add it
            add_var(var_name, result);
        }
        printf("%s = %d\n", var_name, result);
    } else {
        // Otherwise, the command is an invalid statement
        printf("Invalid command.\n");
    }
}

int main() {
    char command[200];

    printf("Mini Interpreter for Simple Expressions\n");
    printf("Supported operations: +, -, *, / (e.g., x = 5 + 3, y = x * 2)\n");
    printf("Type 'exit' to quit the interpreter.\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);

        // Remove newline character at the end
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        process_command(command);
    }

    printf("Exiting interpreter. Goodbye!\n");
    return 0;
}
