#include <stdio.h>
#include <string.h>

// Define a structure for student information
struct Student {
    char name[50];
    char srn[15];
    float percentage;
};

// Function to search for a student by SRN
int searchBySRN(struct Student students[], int n, char srn[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].srn, srn) == 0) {
            return i; // Return index if SRN is found
        }
    }
    return -1; // Return -1 if SRN is not found
}

int main() {
    int n;
    char srnToSearch[15];

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("SRN: ");
        scanf(" %[^\n]", students[i].srn);
        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    // Input SRN to search
    printf("\nEnter the SRN to search: ");
    scanf(" %[^\n]", srnToSearch);

    // Search for the SRN
    int index = searchBySRN(students, n, srnToSearch);

    // Display the result
    if (index != -1) {
        printf("\nStudent found:\n");
        printf("Name: %s\n", students[index].name);
        printf("SRN: %s\n", students[index].srn);
        printf("Percentage: %.2f\n", students[index].percentage);
    } else {
        printf("\nStudent with SRN '%s' not found!\n", srnToSearch);
    }

    return 0;
}
