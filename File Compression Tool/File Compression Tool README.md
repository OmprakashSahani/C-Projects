File Compression Tool

This C program provides a simple file compression and decompression tool using Run-Length Encoding (RLE). 
It allows users to compress files to reduce their size and decompress files back to their original content.

Features:
1. Compress File:
Compresses a file using Run-Length Encoding (RLE).
Replaces sequences of repeating characters with the character followed by the count of repetitions (e.g., "aaabb" becomes "a3b2").

2. Decompress File:
Decompresses a file that was previously compressed using RLE.
Restores the original file content from its compressed form.

3. Exit:
Exits the program.

How to Use:

Compilation:
1. Use a C compiler such as gcc to compile the program:
   gcc -o compression_tool compression_tool.c

Running the Program:
2. Execute the compiled program:
   ./compression_tool

Menu Options:
1. Compress File:

Enter the input file name (the file to compress).
Enter the output file name (where the compressed content will be saved).

2. Decompress File:

Enter the input file name (the compressed file).
Enter the output file name (where the decompressed content will be saved).

3. Exit:

Terminates the program.

Example Usage:
1. Compress a File

   Input File (example.txt):

   aaaabbbbcc

   Compressed File (compressed.txt):

   a4b4c2

Command Flow:

   Enter choice: 1

   Enter input file name: example.txt

   Enter output file name: compressed.txt

File compressed successfully.

2. Decompress a File

   Compressed File (compressed.txt):

   a4b4c2

   Decompressed File (decompressed.txt):

   aaaabbbbcc

Command Flow:

   Enter choice: 2
   
   Enter input file name: compressed.txt
   
   Enter output file name: decompressed.txt
   
   File decompressed successfully.


Code Explanation:

Functions:

1. compress_file(FILE *input, FILE *output)

Reads the input file character by character.

Counts consecutive repetitions of characters.

Writes each character and its count to the output file.

2. decompress_file(FILE *input, FILE *output)

Reads the compressed file character by character.

Decodes each character and its count.

Writes the expanded characters to the output file.


Main Program:

Displays a menu to the user.

Handles user choices for compression, decompression, and exit.

Validates file operations (e.g., opening input/output files).

Notes:
1. The program assumes the input file contains only characters and digits suitable for RLE.
2. Compressed files should not be manually edited, as incorrect formats can cause decompression errors.
3. The program uses basic RLE and does not handle edge cases like multi-digit counts (e.g., a12).

Limitations:

1. RLE is effective only for files with repetitive characters. Files without such patterns may not compress effectively.
2. This implementation supports single-digit counts for repetitions. It may not work correctly for sequences longer than 9 repetitions.

License:

This program is open-source and can be used or modified for educational and personal purposes.
