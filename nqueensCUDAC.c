%%writefile Cuda.cu
#include <stdio.h>
#include <sys/time.h>

#define N 11

_device_ int totalsolutions = 0;

_device_ bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == (row - i))
            return false; // same diagonal or same column
    }
    return true;
}

_device_ void solve(int board[], int row, int queenValue);

_global_ void queens() {
    int board[N];

    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int queenValue = tid;
    if (tid < N) {
        board[0] = queenValue;
        solve(board, 1, queenValue);
    }
}

_device_ void solve(int board[], int row, int queenValue) {
    if (row == N) {
        atomicAdd(&totalsolutions, 1);
    } else {
        for (int col = 0; col < N; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                solve(board, row + 1, queenValue);
            }
        }
    }
}

int main() {
    int total_solutions_host = 0;
    struct timeval start, end;
    double total_time;

    // Start timer
    gettimeofday(&start, NULL);

    // Launch kernel with one thread per queen position for the first row
    queens<<<1, N>>>();

    // Retrieve the total solutions
    cudaMemcpyFromSymbol(&total_solutions_host, totalsolutions, sizeof(int), 0, cudaMemcpyDeviceToHost);

    // End timer
    gettimeofday(&end, NULL);
    total_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("\nTotal Solutions: %d\n", total_solutions_host);
    printf("Total Execution Time: %lf seconds\n", total_time);

    return 0;
}