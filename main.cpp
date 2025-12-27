#include <iostream>
using namespace std;

// Structure to store student data
struct Student {
    int id;
    string name;
    int age;
};

// Function declarations
void addStudent(Student students[], int &count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void deleteStudent(Student students[], int &count);

int main() {
    Student students[100];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                deleteStudent(students, count);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

// Add student
void addStudent(Student students[], int &count) {
    cout << "Enter ID: ";
    cin >> students[count].id;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, students[count].name);

    cout << "Enter Age: ";
    cin >> students[count].age;

    count++;
    cout << "Student added successfully!\n";
}

// Display students
void displayStudents(Student students[], int count) {
    if (count == 0) {
        cout << "No students found.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age << endl;
    }
}

// Search student
void searchStudent(Student students[], int count) {
    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;

    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            cout << "Student Found!\n";
            cout << "Name: " << students[i].name
                 << ", Age: " << students[i].age << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

// Delete student
void deleteStudent(Student students[], int &count) {
    int deleteId;
    cout << "Enter ID to delete: ";
    cin >> deleteId;

    for (int i = 0; i < count; i++) {
        if (students[i].id == deleteId) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
