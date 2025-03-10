#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int target = (rand() % 100) + 1;
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "You have to guess the number." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > target) {
            cout << "Too high! Try again." << endl;
        } else if (guess < target) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number." << endl;
        }

    } while (guess != target);

    cout << "Thanks for playing!" << endl;

    return 0;
}
