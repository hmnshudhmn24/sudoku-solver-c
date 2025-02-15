# Sudoku Solver (C)

A C program that solves a **9x9 Sudoku puzzle** using recursion and backtracking.

## Features
- Solves a Sudoku puzzle using **backtracking**.
- Allows users to **input a Sudoku grid**.
- **Validates the input grid** before solving.
- Displays the solved Sudoku in a **formatted output**.

## How to Compile & Run
```sh
gcc sudoku_solver.c -o sudoku_solver
./sudoku_solver
```

## Usage
- Enter the Sudoku grid as input (use `0` for empty cells).
- The program will solve the puzzle and print the solution.
- If no solution exists, it will display an appropriate message.

## Example Input
```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

## Example Output
```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

## License
This project is licensed under the MIT License.
