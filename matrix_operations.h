#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>   // For std::vector
#include <string>   // For std::string
#include <iostream> // For std::cout, std::cerr
#include <fstream>  // For std::ifstream
#include <iomanip>  // For std::setw (output formatting)

// Type alias for clarity. 'Matrix' is now a shortcut for 'std::vector<std::vector<int>>'
using Matrix = std::vector<std::vector<int>>;

/**
 * @brief Prints a matrix to the console with aligned columns.
 * @param mat The matrix to print.
 */
void printMatrix(const Matrix& mat);

/**
 * @brief (Q1) Reads N and two NxN matrices from a file.
 * @param filename The name of the input file.
 * @param N Output parameter for the matrix size.
 * @param matA Output parameter for the first matrix.
 * @param matB Output parameter for the second matrix.
 * @return true on success, false if file cannot be opened.
 */
bool loadMatricesFromFile(const std::string& filename, int& N, Matrix& matA, Matrix& matB);

/**
 * @brief (Q2) Adds two matrices and prints the result.
 * @param matA The first matrix.
 * @param matB The second matrix.
 */
void addMatrices(const Matrix& matA, const Matrix& matB);

/**
 * @brief (Q3) Multiplies two matrices and prints the result.
 * @param matA The first matrix.
 * @param matB The second matrix.
 */
void multiplyMatrices(const Matrix& matA, const Matrix& matB);

/**
 * @brief (Q4) Calculates and prints the sums of the main and secondary diagonals.
 * @param mat The matrix to analyze.
 */
void printDiagonalSums(const Matrix& mat);

/**
 * @brief (Q5) Swaps two rows in a matrix and prints the result.
 * @param mat The matrix to modify (will be changed).
 * @param r1 The index of the first row to swap.
 * @param r2 The index of the second row to swap.
 */
void swapRows(Matrix& mat, int r1, int r2);

/**
 * @brief (Q6) Swaps two columns in a matrix and prints the result.
 * @param mat The matrix to modify (will be changed).
 * @param c1 The index of the first column to swap.
 * @param c2 The index of the second column to swap.
 */
void swapCols(Matrix& mat, int c1, int c2);

/**
 * @brief (Q7) Updates a single element in the matrix and prints the result.
 * @param mat The matrix to modify (will be changed).
 * @param r The row index of the element.
 * @param c The column index of the element.
 * @param newValue The new value to insert.
 */
void updateElement(Matrix& mat, int r, int c, int newValue);


#endif // MATRIX_OPERATIONS_H