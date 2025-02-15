#include <stdio.h>
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if it's safe to place a number
int isSafe(int grid[N][N], int row, int col, int num) {
    // Check row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return 0;
        }
    }

    // Check column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return 0;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku using backtracking
int solveSudoku(int grid[N][N]) {
    int row, col, found = 0;
    
    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }
    
    // If no empty cell is found, Sudoku is solved
    if (!found) return 1;
    
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) return 1;
            grid[row][col] = 0; // Backtrack
        }
    }
    return 0;
}

// Function to validate the initial Sudoku grid
int isValidSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] != 0) {
                int num = grid[row][col];
                grid[row][col] = 0;
                if (!isSafe(grid, row, col, num)) {
                    return 0;
                }
                grid[row][col] = num;
            }
        }
    }
    return 1;
}

// Function to input a Sudoku grid from the user
void inputGrid(int grid[N][N]) {
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
}

int main() {
    int grid[N][N];
    inputGrid(grid);
    
    if (!isValidSudoku(grid)) {
        printf("Invalid Sudoku puzzle!\n");
        return 1;
    }
    
    if (solveSudoku(grid)) {
        printf("Solved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("No solution exists\n");
    }
    
    return 0;
}
