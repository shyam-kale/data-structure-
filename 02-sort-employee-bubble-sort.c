#include <stdio.h>
#include <string.h>

// Define a structure for employee information
struct Employee {
    char name[50];
    float salary;
};

// Function to sort employees by name using insertion sort
void sortByName(struct Employee employees[], int n) {
    for (int i = 1; i < n; i++) {
        struct Employee key = employees[i];
        int j = i - 1;

        while (j >= 0 && strcmp(employees[j].name, key.name) > 0) {
            employees[j + 1] = employees[j];
            j--;
        }
        employees[j + 1] = key;
    }
}

// Function to sort employees by salary using insertion sort
void sortBySalary(struct Employee employees[], int n) {
    for (int i = 1; i < n; i++) {
        struct Employee key = employees[i];
        int j = i - 1;

        while (j >= 0 && employees[j].salary > key.salary) {
            employees[j + 1] = employees[j];
            j--;
        }
        employees[j + 1] = key;
    }
}

// Function to display employee information
void printEmployees(struct Employee employees[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %.2f\n", employees[i].name, employees[i].salary);
    }
}

int main() {
    int n, choice;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("Enter name of employee %d: ", i + 1);
        scanf(" %[^\n]", employees[i].name);
        printf("Enter salary of employee %d: ", i + 1);
        scanf("%f", &employees[i].salary);
    }

    // Choose sorting criterion
    printf("\nSort by:\n1. Name\n2. Salary\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        sortByName(employees, n);
    } else if (choice == 2) {
        sortBySalary(employees, n);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    // Display sorted employee list
    printf("\nSorted employee list:\n");
    printEmployees(employees, n);

    return 0;
}
