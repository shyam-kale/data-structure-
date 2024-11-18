#include <stdio.h>

#define FILENAME "sample.txt"  // Name of the file

// Function to create and write to a file
void createFile() {
    FILE *file = fopen(FILENAME, "w");  // Open the file in write mode

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write some data to the file
    fprintf(file, "Hello, this is a sample file.\n");
    fprintf(file, "C programming is fun!\n");
    fprintf(file, "This file contains some text data.\n");

    // Close the file after writing
    fclose(file);

    printf("File created and data written successfully.\n");
}

// Function to read and display contents of the file
void displayFileContents() {
    FILE *file = fopen(FILENAME, "r");  // Open the file in read mode

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char ch;

    // Read and display the contents of the file character by character
    printf("\nFile Contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Close the file after reading
    fclose(file);
}

int main() {
    // Create the file and write some data to it
    createFile();

    // Display the contents of the file
    displayFileContents();

    return 0;
}
