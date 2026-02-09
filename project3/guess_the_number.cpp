/**
 * @file guess_the_number.cpp
 * @brief Implements a number guessing game using random number generation.
 *
 * @details
 * This program generates a random number between 1 and 100 and prompts the user
 * to guess the number. The user continues guessing until the correct number is
 * entered. After each guess, the program provides feedback indicating whether
 * the guess is too high, too low, or correct. Once the correct number is guessed,
 * the program displays a success message along with the total number of attempts.
 * This program demonstrates the use of random number generation, loops,
 * conditional logic, user input, and basic counting mechanisms in C++.
 *
 * @author Ahmed Lotfey
 * @class CS2150-A1 C++ Programming
 * @professor Dr. Richard Lesh
 * @department Computer Science, Baker College
 * @date 02/08/2026
 * @version 1.0
 *
 * @input
 * - User guesses (integer values between 1 and 100)
 *
 * @output
 * - Feedback indicating whether the guess is too high or too low
 * - Success message when the correct number is guessed
 * - Total number of attempts taken
 *
 * @note
 * This program assumes valid numeric input from the user and does not include
 * input validation for non-numeric values.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {
    // Seed the random number generator with the current time.
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "Guess the number between 1 and 100." << endl;
    cout << "Enter your guess: ";
    while (userGuess != randomNumber) {
        cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again: ";
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Congratulations! You have won!" << endl;
            cout << "Total attempts: " << attempts << endl;
        }
    }
    cout << "Thank you for playing!" << endl;
    return 0;
}