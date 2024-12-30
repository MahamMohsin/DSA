#include <iostream>
using namespace std;

const int MAX = 100;  // Maximum grid size

// Function to check if the current position is within bounds and matches the character in the word
bool isValid(char grid[MAX][MAX], int n, int m, int row, int col, int index, string word) {
    return (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == word[index]);
}

// Recursive backtracking function to search the word in the grid
bool backtrackSearch(char grid[MAX][MAX], int n, int m, string word, int index, int row, int col) {
    // Base case: If all characters in the word are matched
    if (index == word.size()) {
        return true;
    }

    // Boundary check and character mismatch check
    if (!isValid(grid, n, m, row, col, index, word)) {
        return false;
    }

    // Temporarily mark the cell as visited by changing it to a non-character (e.g., '*')
    char temp = grid[row][col];
    grid[row][col] = '*';  // Mark as visited

    // Explore in all 4 directions: up, down, left, and right
    bool found = backtrackSearch(grid, n, m, word, index + 1, row - 1, col) ||  // Up
                 backtrackSearch(grid, n, m, word, index + 1, row + 1, col) ||  // Down
                 backtrackSearch(grid, n, m, word, index + 1, row, col - 1) ||  // Left
                 backtrackSearch(grid, n, m, word, index + 1, row, col + 1);    // Right

    // Restore the original character after exploring
    grid[row][col] = temp;

    return found;
}

// Function to check if the word exists in the grid
bool existsInGrid(char grid[MAX][MAX], int n, int m, string word) {
    // Try to match the word starting from each cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (backtrackSearch(grid, n, m, word, 0, i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    char grid[MAX][MAX];
    string word;

    // Input grid dimensions
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    // Input the grid characters
    cout << "Enter the grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Input the word to search
    cout << "Enter the word to search: ";
    cin >> word;

    // Check if the word exists in the grid
    if (existsInGrid(grid, n, m, word)) {
        cout << "Word found in the grid!" << endl;
    } else {
        cout << "Word not found in the grid!" << endl;
    }

    return 0;
}
