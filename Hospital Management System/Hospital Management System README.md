# Hospital-Management-System-Using-C-Language
Hospital Management System

Overview:
The Hospital Management System is a simple C program that allows the management of patients in a hospital. 

It supports the following functionalities:
1. Add new patients
2. View the list of all patients
3. Search for a patient by name
4. Book an appointment for a patient

The program stores information about each patient, including their ID, name, age, disease, and appointment date.

Features:
1. Add Patient: Adds a new patient to the system by entering details such as ID, name, age, disease, and appointment date.
2. View Patients: Displays a list of all patients in the system.
3. Search Patient: Searches for a patient by name and displays their details if found.
4. Book Appointment: Allows the user to book or update an appointment for an existing patient using their ID.

Files:

hospital_management_system.c: The main source file containing the implementation of the system.
README.md: This readme file.

How to Compile and Run

1. Compile the Program:

   Open a terminal and navigate to the directory where the program file (hospital_management_system.c) is located.

Use the following command to compile the program:

   gcc hospital_management_system.c -o hospital_management_system


2. Run the Program:

After compilation, run the program using the following command:

  ./hospital_management_system

Usage:

The program will display a menu with the following options:

1. Add Patient: Input the patient's details such as ID, name, age, disease, and appointment date.
2. View Patients: Display all patients stored in the system.
3. Search Patient: Enter the name of a patient to search for and display their details.
4. Book Appointment: Enter the patient ID and book or update their appointment date.
5. Exit: Exit the program.

Sample Menu:

Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Book Appointment
5. Exit
Enter choice:

Functions

add_patient

Adds a new patient to the system by prompting the user for the patient's ID, name, age, disease, and appointment date.

view_patients

Displays all the patients stored in the system, including their ID, name, age, disease, and appointment date.

search_patient

Searches for a patient by their name and displays their details if found.

book_appointment

Allows the user to book or update an appointment for an existing patient using their ID.


Dependencies:

The program uses the standard C libraries:

<stdio.h>

<stdlib.h>

<string.h>



License:

This program is licensed under the MIT License.

Author

Developed by Omprakash Sahani.
