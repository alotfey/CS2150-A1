/**
* @file tip_calculator.cpp
* @brief Calculates a restaurant tip and final bill total based on user input.
*
* @details
* This program prompts the user to enter a restaurant bill amount and a desired
* tip percentage (entered as a decimal). It calculates the tip amount and the
* final bill total, then displays a formatted summary of the bill details.
* The program demonstrates basic C++ programming concepts including user input,
* arithmetic operations, and console output formatting.
*
* @author Ahmed Lotfey
* @class CS2150-A1 C++ Programming
* @professor Dr. Richard Lesh
* @department Computer Science, Baker College
* @date 01/25/2026
* @version 1.0
*
* @input
* - Bill amount (double)
* - Tip percentage as a decimal value (double, example: 0.15)
*
* @output
* - Bill amount
* - Tip percentage
* - Tip amount
* - Final bill amount
*
* @note
* This program assumes valid numeric input from the user and does not include
* input validation.
*/
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    double billAmount;
    double tipPercentage;
    double tipAmount;
    double finalBillAmount;


    cout << "Enter the bill amount and tip percentage to calculate your total." << endl;
    cout << "Enter bill amount: ";
    cin >> billAmount;


    cout << "Enter tip percentage as a decimal (example: 0.15): ";
    cin >> tipPercentage;


    tipAmount = billAmount * tipPercentage;
    finalBillAmount = billAmount + tipAmount;


    cout << fixed << setprecision(2);
    cout << "###############################################" << endl;
    cout << "###### Bill Details ######" << endl;
    cout << "Bill Amount: $" << billAmount << endl;
    cout << "Tip Percentage: " << tipPercentage * 100 << "%" << endl;
    cout << "Tip Amount: $" << tipAmount << endl;
    cout << "##### Final Bill Details #####" << endl;
    cout << "Final Bill Amount: $" << finalBillAmount << endl;
    cout << "###############################################" << endl;


    return 0;
}