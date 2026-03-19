#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function declarations
void displayMenu();
void calculateCGPA();
void convertGPA();
void aboutProgram();
void saveToFile(float cgpa);

int main() {
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: calculateCGPA(); break;
            case 2: convertGPA(); break;
            case 3: aboutProgram(); break;
            case 4: cout << "Exiting the program. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    cout << "\n=== CGPA Calculator By Eman Hassan ===\n";
    cout << "1. Calculate CGPA\n";
    cout << "2. GPA Conversion\n";
    cout << "3. About\n";
    cout << "4. Exit\n";
}

// Function to calculate CGPA
void calculateCGPA() {
    int numSubjects;
    float totalPoints = 0, totalCreditHours = 0;

    cout << "\n-- Calculate CGPA --\n";
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    string grade;
    float creditHours;

    for (int i = 0; i < numSubjects; i++) {
        cout << "Enter grade for subject " << i + 1 << " (A, B, C, D, F): ";
        cin >> grade;
        cout << "Enter credit hours for subject " << i + 1 << ": ";
        cin >> creditHours;

        // Convert grade to grade points
        float gradePoints = 0;
        if (grade == "A") gradePoints = 4.0;
        else if (grade == "B") gradePoints = 3.0;
        else if (grade == "C") gradePoints = 2.0;
        else if (grade == "D") gradePoints = 1.0;
        else if (grade == "F") gradePoints = 0.0;
        else {
            cout << "Invalid grade entered! Defaulting to 0.0 points.\n";
            gradePoints = 0.0;
        }

        totalPoints += gradePoints * creditHours;
        totalCreditHours += creditHours;
    }

    float cgpa = totalPoints / totalCreditHours;
    cout << "Your CGPA is: " << cgpa << "\n";

    // Save the result to a file
    saveToFile(cgpa);
}

// Function to convert CGPA to other systems
void convertGPA() {
    float cgpa;
    cout << "\n-- GPA Conversion --\n";
    cout << "Enter your CGPA: ";
    cin >> cgpa;

    float percentage = cgpa * 25;  // Example: 4.0 CGPA = 100%
    cout << "Equivalent Percentage: " << percentage << "%\n";

    float gpa5Scale = (cgpa / 4.0) * 5.0;  // Convert to 5.0 scale
    cout << "Equivalent GPA (5.0 scale): " << gpa5Scale << "\n";
}

// Function to display program details
void aboutProgram() {
    cout << "\n-- About CGPA Calculator Developed By Muhammad Shahbaz Khan --\n";
    cout << "This program calculates your CGPA based on grades and credit hours.\n";
    cout << "You can also convert your CGPA to other grading systems.\n";
    cout << "Thanks for using.\n";
}

// Function to save CGPA result to a file
void saveToFile(float cgpa) {
    ofstream file("cgpa_records.txt", ios::app);
    if (file.is_open()) {
        file << "CGPA: " << cgpa << "\n";
        file.close();
        cout << "Result saved to file successfully!\n";
    } else {
        cout << "Error saving to file.\n";
    }
}

