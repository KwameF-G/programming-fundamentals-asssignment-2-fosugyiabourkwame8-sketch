// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_SIZE = 10;

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string matrixName = "");
void transposeMatrix(const int original[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, string matrixName) {
    if (!matrixName.empty()) {
        cout << "\n--- Enter values for matrix " << matrixName << " ---" << endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

    //PART A — Transpose a Matrix
    void transposeMatrix(const int original[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed[j][i] = original[i][j];
            }
        }
    }

void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "===Matrix OPERATIONS===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int M, N;
        cout << "Enter number of rows (M): ";
        cin >> M;
        cout << "Enter number of columns (N): ";
        cin >> N;

        int matrix[MAX_SIZE][MAX_SIZE];
        int transposed[MAX_SIZE][MAX_SIZE];

        readMatrix(matrix, M, N);
        transposeMatrix(matrix, transposed, M, N);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, M, N);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(transposed, N, M);
    }
    else if (choice == 2) {
        int M, N;
        cout << "Enter number of rows (M): ";
        cin >> M;
        cout << "Enter number of columns (N): ";
        cin >> N;

        int matrixA[MAX_SIZE][MAX_SIZE];
        int matrixB[MAX_SIZE][MAX_SIZE];
        int sum[MAX_SIZE][MAX_SIZE];

        readMatrix(matrixA, M, N, "A");
        readMatrix(matrixB, M, N, "B");

        addMatrices(matrixA, matrixB, sum, M, N);

        cout << "\nMatrix A + Matrix B Result:" << endl;
        printMatrix(sum, M, N);
    }
    else if (choice == 3) {
        int M, N, P;
        cout << "For Matrix A (M x N):" << endl;
        cout << "Enter number of rows (M): ";
        cin >> M;
        cout << "Enter number of columns (N): ";
        cin >> N;

        cout << "For Matrix B (N x P):" << endl;
        cout << "Enter number of columns (P): ";
        cin >> P;

        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int product[MAX_SIZE][MAX_SIZE];

        readMatrix(A, M, N, "A");
        readMatrix(B, N, P, "B");

        multiplyMatrices(A, B, product, M, N, P);

        cout << "\nMatrix A x Matrix B Result:" << endl;
        printMatrix(product, M, P);
    }
    else {
        cout << "Invalid choice. Please select 1, 2, or 3." << endl;
    }

    return 0;
}