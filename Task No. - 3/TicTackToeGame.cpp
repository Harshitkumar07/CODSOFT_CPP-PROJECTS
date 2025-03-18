#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

void resetBoard() {
    char cellNumber = '1';
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = cellNumber++;
        }
    }
    currentPlayer = 'X';
}

void displayBoard() {
    cout << "\nTIC-TAC-TOE BOARD\n";
    for (int row = 0; row < 3; row++) {
        cout << " " << board[row][0] << " | " << board[row][1] << " | "
             << board[row][2] << " \n";
        if (row < 2) cout << "---|---|---\n";
    }
    cout << endl;
}

bool isValidMove(char move) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == move) return true;
        }
    }
    return false;
}

void makeMove(char move) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == move) {
                board[row][col] = currentPlayer;
                return;
            }
        }
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}

bool checkDraw() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] >= '1' && board[row][col] <= '9') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char move;
    char playAgain;

    do {
        resetBoard();
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (!isValidMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(move);

            if (checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}