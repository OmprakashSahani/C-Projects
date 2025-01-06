#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 100

// Struct to represent a patient
struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char disease[MAX_NAME_LENGTH];
    char contact[MAX_NAME_LENGTH];
};

// Global array to store patients
struct Patient patients[MAX_PATIENTS];
int patient_count = 0;  // Keeps track of the number of patients

// Function to display the menu
void display_menu() {
    printf("\n=== Hospital Management System ===\n");
    printf("1. Add Patient Record\n");
    printf("2. View All Patient Records\n");
    printf("3. Search Patient by ID\n");
    printf("4. Delete Patient Record\n");
    printf("5. Exit\n");
    printf("Please choose an option: ");
}

// Function to add a patient record
void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Patient list is full. Cannot add more patients.\n");
        return;
    }

    struct Patient new_patient;
    new_patient.id = patient_count + 1;  // Automatically assign an ID

    printf("\nEnter patient name: ");
    fgets(new_patient.name, sizeof(new_patient.name), stdin);
    new_patient.name[strcspn(new_patient.name, "\n")] = '\0';  // Remove newline

    printf("Enter patient age: ");
    scanf("%d", &new_patient.age);

    getchar();  // Consume newline left by scanf

    printf("Enter patient's disease: ");
    fgets(new_patient.disease, sizeof(new_patient.disease), stdin);
    new_patient.disease[strcspn(new_patient.disease, "\n")] = '\0';  // Remove newline

    printf("Enter patient contact number: ");
    fgets(new_patient.contact, sizeof(new_patient.contact), stdin);
    new_patient.contact[strcspn(new_patient.contact, "\n")] = '\0';  // Remove newline

    patients[patient_count] = new_patient;  // Add new patient to the array
    patient_count++;
    printf("Patient record added successfully.\n");
}

// Function to view all patient records
void view_patients() {
    if (patient_count == 0) {
        printf("No patient records found.\n");
        return;
    }

    printf("\n--- All Patient Records ---\n");
    for (int i = 0; i < patient_count; i++) {
        printf("ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Disease: %s\n", patients[i].disease);
        printf("Contact: %s\n", patients[i].contact);
        printf("--------------------------\n");
    }
}

// Function to search for a patient by ID
void search_patient_by_id() {
    int id;
    printf("\nEnter patient ID to search: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("\n--- Patient Found ---\n");
            printf("ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            printf("Contact: %s\n", patients[i].contact);
            printf("---------------------\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient with ID %d not found.\n", id);
    }
}

// Function to delete a patient record
void delete_patient() {
    int id;
    printf("\nEnter patient ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            // Shift all records after the deleted patient
            for (int j = i; j < patient_count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patient_count--;  // Decrease the patient count
            printf("Patient record with ID %d deleted successfully.\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient with ID %d not found.\n", id);
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                view_patients();
                break;
            case 3:
                search_patient_by_id();
                break;
            case 4:
                delete_patient();
                break;
            case 5:
                printf("Exiting the Hospital Management System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
