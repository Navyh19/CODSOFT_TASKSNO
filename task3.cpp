#include <iostream>
#include <vector>

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---|---|---\n";
    }
    std::cout << "\n";
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][02] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void playGame() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    std::cout << "=================================\n";
    std::cout << "         TIC-TAC-TOE GAME        \n";
    std::cout << "=================================\n";

    while (!gameOver) {
        displayBoard(board);
        int row, col;
        
        std::cout << "Player " << currentPlayer << ", enter your move (row 1-3 and column 1-3 separated by space): ";
        std::cin >> row >> col;
        
        // Adjusting inputs to 0-indexed vectors
        row--; col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                std::cout << "The game is a draw!\n";
                gameOver = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            std::cout << "Invalid move. The slot is either taken or out of bounds. Try again.\n";
        }
    }
}

int main() {
    char playAgain;
    do {
        playGame();
        std::cout << "Do you want to play another game? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
