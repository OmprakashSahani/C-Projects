# Projects-Using-C-Language

Text Editor Program in C

This program provides a basic text editor functionality using the C programming language. 
It allows users to:
1. Create a new file and write content to it.
2. Read the content of an existing file.
3. Append content to an existing file.
4. Exit the program.

Features:
1. Create a New File:

Prompts the user to enter the file name.
Allows the user to write content line by line.
Saves the file once the user types exit on a new line.

2. Read an Existing File:

Prompts the user to enter the file name.
Displays the contents of the specified file.

3. Edit a File:
Prompts the user to enter the file name.
Appends new content to the existing file.
Saves the file once the user types exit on a new line.

4. Exit:
Exits the program.

How to Use:
1. Compile the Program: Use a C compiler such as gcc:
   gcc -o text_editor text_editor.c

2. Run the Program: Execute the compiled program:
   ./text_editor

3. Follow the Menu:

The program displays a menu with options to create, read, edit files, or exit.

Enter the corresponding number to choose an option.

Code Structure:

main Function:

Displays the menu and handles user input.

Calls the appropriate functions based on the user's choice.

createFile Function:

Handles creating a new file and writing content to it.

readFile Function:

Handles reading and displaying the contents of an existing file.

editFile Function:

Handles appending new content to an existing file.

Example Usage:

1. Creating a New File:

Enter your choice: 1

Enter the name of the file to create: example.txt

Enter text (type 'exit' on a new line to save and close):

This is a new file.

exit

File 'example.txt' created successfully.

2. Reading a File:

Enter your choice: 2

Enter the name of the file to read: example.txt

Contents of 'example.txt':

This is a new file.

3. Editing a File:

Enter your choice: 3

Enter the name of the file to edit: example.txt

Enter text to append (type 'exit' on a new line to save and close):

Appending more text.

exit

File 'example.txt' edited successfully.

4. Exiting the Program:

Enter your choice: 4

Notes:
Ensure the program has permission to create, read, and write files in the directory where it is executed.
Type exit on a new line to save and close the file while creating or editing it.
The program uses simple text file operations and does not support advanced text editing features.

License:

This program is open-source and can be modified or distributed as needed. Use it as a starting point for building more advanced text editors.
