#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    float percentage;
};

void sortByName(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByPercentage(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].percentage > students[j + 1].percentage) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void printStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %.2f%%\n", students[i].name, students[i].percentage);
    }
}

int main() {
    int n, choice;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name);
        printf("Enter percentage of student %d: ", i + 1);
        scanf("%f", &students[i].percentage);
    }

    printf("Sort by:\n1. Name\n2. Percentage\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        sortByName(students, n);
    } else if (choice == 2) {
        sortByPercentage(students, n);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Sorted list of students:\n");
    printStudents(students, n);

    return 0;
}
