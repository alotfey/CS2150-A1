/**
* @file grade_calculator.cpp
 * @brief Determines a student's letter grade based on a numerical score.
 *
 * @details
 * This program prompts the user to enter a student's numerical grade and
 * determines the corresponding letter grade using a predefined grading scale.
 * The grading scale follows standard academic conventions:
 * A (90–100), B (80–89), C (70–79), D (60–69), and F (below 60).
 * The program demonstrates fundamental C++ concepts such as variable usage,
 * user input, conditional logic (if-else or switch statements), and console output.
 *
 * @author Ahmed Lotfey
 * @class CS2150-A1 C++ Programming
 * @professor Dr. Richard Lesh
 * @department Computer Science, Baker College
 * @date 02/01/2026
 * @version 1.0
 *
 * @input
 * - Student numerical grade (integer or double)
 *
 * @output
 * - Corresponding letter grade (A, B, C, D, or F)
 *
 * @note
 * This program assumes valid numeric input from the user and does not include
 * input validation for values outside the 0–100 range.
 */

#include <iostream>
using namespace std;

int main() {
    double studentGrade;

    cout << "Enter student grade: ";
    cin >> studentGrade;

    if (studentGrade < 0.0 || studentGrade > 100.0) {
        cout << "Wrong grade!" << endl;
    } else if (studentGrade >= 90.0) {
        cout << "A" << endl;
    } else if (studentGrade >= 80.0) {
        cout << "B" << endl;
    } else if (studentGrade >= 70.0) {
        cout << "C" << endl;
    } else if (studentGrade >= 60.0) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }

    return 0;
}
