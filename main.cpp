#include "matrix_operations.h"

int main() {
    int N;
    Matrix matrixA, matrixB;
    std::string filename;

    // Prompt user for filename
    std::cout << "Enter the name of the input file: ";
    std::cin >> filename;

    // --- Q1: Load and Print ---
    // This function call handles all of Q1
    if (!loadMatricesFromFile(filename, N, matrixA, matrixB)) {
        return 1; // Exit if file loading failed
    }

    // --- Q2: Addition ---
    addMatrices(matrixA, matrixB);

    // --- Q3: Multiplication ---
    multiplyMatrices(matrixA, matrixB);

    // --- Q4: Diagonal Sums ---
    // Let's run this on both matrices
    std::cout << "\n(For Matrix A)";
    printDiagonalSums(matrixA);
    std::cout << "\n(For Matrix B)";
    printDiagonalSums(matrixB);

    // --- Q5: Swap Rows ---
    // We will modify matrixA for the remaining operations
    // Let's swap rows 0 and 1 as an example
    swapRows(matrixA, 0, 1);

    // --- Q6: Swap Columns ---
    // Let's swap columns 1 and 2 on the *modified* matrixA
    swapCols(matrixA, 1, 2);

    // --- Q7: Update Element ---
    // Let's update element (0, 0) to 99 on the *modified* matrixA
    updateElement(matrixA, 0, 0, 99);

    std::cout << "\n--- All operations complete. ---" << std::endl;

    return 0; // Success
}