#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool isSafe(int board[], int row, int col, int boardsize) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == (row - i))
            return false; // same diagonal or same column
    }
    return true;
}

int queens(int board[], int row, int boardsize) {
    if (row == boardsize) {
        return 1; // 1 => true
    }
    int solutions = 0;
    for (int col = 0; col < boardsize; col++) {
        if (isSafe(board, row, col, boardsize)) {
            board[row] = col;
            solutions += queens(board, row + 1, boardsize);
        }
    }
    return solutions;
}

int main() {
    int totalsolutions = 0;
    printf("Enter the size of the board: ");
    int boardsize;
    scanf("%d", &boardsize);
    int board[boardsize];

    clock_t start_time = clock(); 

    totalsolutions = queens(board, 0, boardsize);

    clock_t end_time = clock(); 
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Total solutions: %d\n", totalsolutions);
    printf("Time taken: %fs\n", time_taken);
    return 0;
}
