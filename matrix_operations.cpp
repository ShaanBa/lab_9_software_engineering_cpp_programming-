#include "matrix_operations.h"

// --- Helper Function ---

void printMatrix(const Matrix& mat) {
    if (mat.empty()) return;
    
    int N = mat.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // std::setw(5) sets the width for the next item, ensuring alignment
            std::cout << std::setw(5) << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// --- Lab Questions ---

// (Q1) Read values from a file into the matrix
bool loadMatricesFromFile(const std::string& filename, int& N, Matrix& matA, Matrix& matB) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return false;
    }

    // Read size N
    inFile >> N;

    // Resize matrices to be N x N
    matA.resize(N, std::vector<int>(N));
    matB.resize(N, std::vector<int>(N));

    // Read Matrix A
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inFile >> matA[i][j];
        }
    }

    // Read Matrix B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inFile >> matB[i][j];
        }
    }

    inFile.close();

    // As per Q1, print matrices after reading
    std::cout << "--- Matrix A (from file) ---" << std::endl;
    printMatrix(matA);
    std::cout << "\n--- Matrix B (from file) ---" << std::endl;
    printMatrix(matB);
    
    return true;
}

// (Q2) Add two matrices and display the result
void addMatrices(const Matrix& matA, const Matrix& matB) {
    int N = matA.size();
    Matrix result(N, std::vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }

    std::cout << "\n--- Q2: Matrix A + Matrix B ---" << std::endl;
    printMatrix(result);
}

// (Q3) Multiply two matrices and display the result
void multiplyMatrices(const Matrix& matA, const Matrix& matB) {
    int N = matA.size();
    // Initialize result matrix with all zeros
    Matrix result(N, std::vector<int>(N, 0)); 

    for (int i = 0; i < N; ++i) {     // Result row
        for (int j = 0; j < N; ++j) { // Result column
            for (int k = 0; k < N; ++k) { // Inner product
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    std::cout << "\n--- Q3: Matrix A * Matrix B ---" << std::endl;
    printMatrix(result);
}

// (Q4) Get the sum of matrix diagonal elements
void printDiagonalSums(const Matrix& mat) {
    int N = mat.size();
    int mainDiagSum = 0;
    int secDiagSum = 0;

    for (int i = 0; i < N; ++i) {
        mainDiagSum += mat[i][i];         // Main diagonal (top-left to bottom-right)
        secDiagSum += mat[i][N - 1 - i];  // Secondary diagonal (top-right to bottom-left)
    }

    std::cout << "\n--- Q4: Diagonal Sums ---" << std::endl;
    std::cout << "Main diagonal sum: " << mainDiagSum << std::endl;
    std::cout << "Secondary diagonal sum: " << secDiagSum << std::endl;
}

// (Q5) Swap matrix rows and display the result
void swapRows(Matrix& mat, int r1, int r2) {
    int N = mat.size();
    // Check for valid indices
    if (r1 < 0 || r1 >= N || r2 < 0 || r2 >= N) {
        std::cerr << "Error: Invalid row indices for swap." << std::endl;
        return;
    }

    // Swapping rows in a vector-of-vectors is easy!
    std::swap(mat[r1], mat[r2]);

    std::cout << "\n--- Q5: Matrix after swapping rows " << r1 << " and " << r2 << " ---" << std::endl;
    printMatrix(mat);
}

// (Q6) Swap matrix columns and display the result
void swapCols(Matrix& mat, int c1, int c2) {
    int N = mat.size();
    // Check for valid indices
    if (c1 < 0 || c1 >= N || c2 < 0 || c2 >= N) {
        std::cerr << "Error: Invalid column indices for swap." << std::endl;
        return;
    }

    // Must swap one element at a time, down the column
    for (int i = 0; i < N; ++i) {
        std::swap(mat[i][c1], mat[i][c2]);
    }

    std::cout << "\n--- Q6: Matrix after swapping columns " << c1 << " and " << c2 << " ---" << std::endl;
    printMatrix(mat);
}

// (Q7) Update matrix element and display the result
void updateElement(Matrix& mat, int r, int c, int newValue) {
    int N = mat.size();
    // Check for valid indices
    if (r < 0 || r >= N || c < 0 || c >= N) {
        std::cerr << "Error: Invalid indices for update." << std::endl;
        return;
    }

    mat[r][c] = newValue;

    std::cout << "\n--- Q7: Matrix after updating (" << r << ", " << c << ") to " 
              << newValue << " ---" << std::endl;
    printMatrix(mat);
}