# Mini-Interpreter-Compiler-for-Simple-Expressions
Simple command-line-based interpreter/compiler that evaluates basic mathematical expressions and supports variable assignments.

Mini Interpreter for Simple Expressions

Overview:
This program is a simple command-line-based interpreter that evaluates basic mathematical expressions and supports variable assignments. 
It uses basic operators (+, -, *, /) and allows users to assign and reuse variables in subsequent commands.

Features:
1. Basic Arithmetic: Supports addition (+), subtraction (-), multiplication (*), and division (/).
2. Variable Assignment: Allows assigning values or expressions to variables (e.g., x = 5 + 3).
3. Reusing Variables: Previously defined variables can be used in expressions.
4. Interactive Interface: Runs in a loop allowing users to enter commands until the keyword exit is entered.

Usage:

Running the Program
1. Compile the program:
   gcc mini_interpreter.c -o mini_interpreter

2. Run the program:

   ./mini_interpreter


Commands:

Assign a variable:

variable_name = expression

Example:

x = 10 + 5

y = x * 2

Exit the interpreter:

exit

Example Session:

Mini Interpreter for Simple Expressions
Supported operations: +, -, *, / (e.g., x = 5 + 3, y = x * 2)
Type 'exit' to quit the interpreter.

Enter command: x = 5 + 3

x = 8

Enter command: y = x * 2

y = 16

Enter command: z = y / 4

z = 4

Enter command: exit
Exiting interpreter. Goodbye!

Limitations:
1. No support for parentheses in expressions (e.g., x = (5 + 3) * 2 will not work).
2. Only integer operations are supported; division truncates to an integer.
3. Variable names are case-sensitive and must not exceed 19 characters.
4. Limited to a maximum of 100 variables.


File Structure:
mini_interpreter.c: Source code for the interpreter.

License:

This program is provided as-is with no warranty. 
You are free to use, modify, and distribute it. 
Attribution is appreciated but not required.
