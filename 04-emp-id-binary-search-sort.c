#include <stdio.h>
#include <string.h>

// Define a structure for employee information
struct Employee {
    int id;
    char name[50];
    char address[100];
    float salary;
};

// Function to sort employees by ID (needed for binary search)
void sortByID(struct Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].id > employees[j + 1].id) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search for an employee by ID
int binarySearchByID(struct Employee employees[], int n, int idToSearch) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (employees[mid].id == idToSearch) {
            return mid; // ID found
        } else if (employees[mid].id < idToSearch) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // ID not found
}

int main() {
    int n, idToSearch;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    // Input employee details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name);
        printf("Address: ");
        scanf(" %[^\n]", employees[i].address);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // Sort employees by ID
    sortByID(employees, n);

    // Input ID to search
    printf("\nEnter the employee ID to search: ");
    scanf("%d", &idToSearch);

    // Perform binary search
    int index = binarySearchByID(employees, n, idToSearch);

    // Display the result
    if (index != -1) {
        printf("\nEmployee found:\n");
        printf("ID: %d\n", employees[index].id);
        printf("Name: %s\n", employees[index].name);
        printf("Address: %s\n", employees[index].address);
        printf("Salary: %.2f\n", employees[index].salary);
    } else {
        printf("\nEmployee with ID '%d' not found!\n", idToSearch);
    }

    return 0;
}
