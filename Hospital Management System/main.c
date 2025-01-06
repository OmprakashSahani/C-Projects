#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LENGTH 50

struct Patient {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char disease[MAX_NAME_LENGTH];
    char appointment[MAX_NAME_LENGTH];
};

void add_patient(struct Patient *patients, int *count);
void view_patients(struct Patient *patients, int count);
void search_patient(struct Patient *patients, int count, char *search_name);
void book_appointment(struct Patient *patients, int count);

int main() {
    struct Patient patients[MAX_PATIENTS];
    int patient_count = 0;
    int choice;

    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient\n");
        printf("4. Book Appointment\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                add_patient(patients, &patient_count);
                break;
            case 2:
                view_patients(patients, patient_count);
                break;
            case 3:
                {
                    char search_name[MAX_NAME_LENGTH];
                    printf("Enter patient's name to search: ");
                    fgets(search_name, MAX_NAME_LENGTH, stdin);
                    search_name[strcspn(search_name, "\n")] = 0;  // Remove newline
                    search_patient(patients, patient_count, search_name);
                }
                break;
            case 4:
                book_appointment(patients, patient_count);
                break;
            case 5:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void add_patient(struct Patient *patients, int *count) {
    struct Patient new_patient;
    printf("Enter patient ID: ");
    scanf("%d", &new_patient.id);
    getchar();  // Consume newline

    printf("Enter patient name: ");
    fgets(new_patient.name, MAX_NAME_LENGTH, stdin);
    new_patient.name[strcspn(new_patient.name, "\n")] = 0;  // Remove newline

    printf("Enter patient age: ");
    scanf("%d", &new_patient.age);
    getchar();  // Consume newline

    printf("Enter disease: ");
    fgets(new_patient.disease, MAX_NAME_LENGTH, stdin);
    new_patient.disease[strcspn(new_patient.disease, "\n")] = 0;  // Remove newline

    // Assign an appointment date (for simplicity, we set a placeholder date)
    printf("Enter appointment date: ");
    fgets(new_patient.appointment, MAX_NAME_LENGTH, stdin);
    new_patient.appointment[strcspn(new_patient.appointment, "\n")] = 0;  // Remove newline

    patients[*count] = new_patient;
    (*count)++;
    printf("Patient added successfully!\n");
}

void view_patients(struct Patient *patients, int count) {
    if (count == 0) {
        printf("No patients found.\n");
        return;
    }

    printf("\nList of Patients:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s, Appointment: %s\n",
               patients[i].id, patients[i].name, patients[i].age,
               patients[i].disease, patients[i].appointment);
    }
}

void search_patient(struct Patient *patients, int count, char *search_name) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(patients[i].name, search_name) == 0) {
            printf("Patient found: ID: %d, Name: %s, Age: %d, Disease: %s, Appointment: %s\n",
                   patients[i].id, patients[i].name, patients[i].age,
                   patients[i].disease, patients[i].appointment);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
}

void book_appointment(struct Patient *patients, int count) {
    int id;
    printf("Enter patient ID to book an appointment: ");
    scanf("%d", &id);
    getchar();  // Consume newline

    for (int i = 0; i < count; i++) {
        if (patients[i].id == id) {
            printf("Enter appointment date for patient %s: ", patients[i].name);
            fgets(patients[i].appointment, MAX_NAME_LENGTH, stdin);
            patients[i].appointment[strcspn(patients[i].appointment, "\n")] = 0;  // Remove newline
            printf("Appointment booked successfully!\n");
            return;
        }
    }

    printf("Patient with ID %d not found.\n", id);
}

