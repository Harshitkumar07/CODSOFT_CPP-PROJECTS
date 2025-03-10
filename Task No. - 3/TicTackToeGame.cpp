#include <iostream>

using namespace std;

char board[3][3];
char currPlayer;
void resetBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
    currPlayer = 'X';
}

void displayBoard() {
    cout << "\nTIC-TAC-TOE BOARD\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << endl;
}

bool isValidMove(char move) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == move) return true;
        }
    }
    return false;
}

void makeMove(char move) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == move) {
                board[i][j] = currPlayer;
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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() {
    currPlayer = (currPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char move;
    char playAgain;

    do {
        resetBoard();
        bool gameOver = false;

        while (!gameOver) {
            displayBoard();

            cout << "Player " << currPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (!isValidMove(move)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            makeMove(move);
            if (checkWin()) {
                displayBoard();
                cout << "Player " << currPlayer << " wins! \n";
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw! \n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye! \n";

    return 0;
}
