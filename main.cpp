#include <iostream>
#include <string>
#include <iomanip>

using std::string;
using std::endl;
using std::cout;
using std::cin;

const int MAX_SIZE = 5;
struct Student {
    string name{};
    int ID{ 0 };
    double grade{ 0.0 };

};

void printStudent(const Student& student) {
	cout << std::left << std::setw(13) << "Name: " + student.name
    << std::setw(10) << "ID: " + std::to_string(student.ID)
    << std::setw(10) << "Grade: " + std::to_string(student.grade) << endl;
    
}
// Display all students
void displayStudentInfo(Student students[], int size) {
    cout << std::left << std::setw(20) << "Name"
        << std::setw(10) << "ID"
        << std::setw(10) << "Grade" << endl;
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < size; i++)
        printStudent(students[i]);
}

// Highest grade
void highestGrade(Student students[], int size) {
    if (size == 0) { cout << "No students in the array." << endl; return; }

    int index = 0;
    for (int i = 1; i < size; i++)
        if (students[i].grade > students[index].grade)
            index = i;

    cout << "Student with the highest grade:\n-------------------------------\n";
    printStudent(students[index]);
}

// Lowest grade
void lowestGrade(Student students[], int size) {
    if (size == 0) { cout << "No students in the array." << endl; return; }

    int index = 0;
    for (int i = 1; i < size; i++)
        if (students[i].grade < students[index].grade)
            index = i;

    cout << "Student with the lowest grade:\n------------------------------\n";
    printStudent(students[index]);
}

// Average grade
void averageGrade(Student students[], int size) {
    if (size == 0) { cout << "No students in the array." << endl; return; }

    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += students[i].grade;

    cout << "Average grade: " << std::fixed << std::setprecision(2) << (sum / size) << endl;
}

// Print all student IDs
void printStudentIds(Student students[], int size) {
    if (size == 0) { cout << "No students in the record." << endl; return; }

    cout << "Student IDs:\n";
    for (int i = 0; i < size; i++)
        cout << students[i].ID << endl;
}

// Print all student names
void printStudentNames(Student students[], int size) {
    if (size == 0) { cout << "No students in the record." << endl; return; }

    cout << "Student Names:\n";
    for (int i = 0; i < size; i++)
        cout << students[i].name << endl;
}


void printMenu() {
	cout << "                             " << endl;
	cout << "Menu:" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. Display all students" << endl;
	cout << "2. Student with the highest grade" << endl;
	cout << "3. Student with the lowest grade" << endl;
	cout << "4. Average grade of the class" << endl;
	cout << "5. Student IDs" << endl;
	cout << "6. Student names" << endl;
	cout << "7. Exit" << endl;
}

int main () {
	Student students[MAX_SIZE] = {
		{"Madison", 1001, 85.5},
		{"Ethan", 1002, 92.3},
		{"Olivia", 1003, 78.7},
		{"Liam", 1004, 88.5},
		{"Sophia", 1005, 91.2}
	};

	int count = 5; // Number of students in the array
	int choice;
	do {
		printMenu();
		cout << "Enter your choice: ";
		cout << std::flush; // Ensure the prompt is displayed before input
		cin >> choice;

        switch (choice) {
            case 1:
                displayStudentInfo(students, count);
                break;
            case 2:
                highestGrade(students, count);
                break;
            case 3:
                lowestGrade(students, count);
                break;
            case 4:
                averageGrade(students, count);
                break;
            case 5:
                printStudentIds(students, count);
                break;
            case 6:
                printStudentNames(students, count);
                break;
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
	} while (choice != 7);

	return 0;
}
