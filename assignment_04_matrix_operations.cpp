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

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include <iostream>
#include <vector>

using namespace std;

// Function to transpose matrices
void Matrix(vector<vector<float>> m1, vector<vector<float>> m2,
            vector<vector<float>> &line_m1,
            vector<vector<float>> &line_m2)
{
    int rows1 = m1.size();
    int cols1 = m1[0].size();

    for (int j = 0; j < cols1; j++)
    {
        vector<float> newRow;
        for (int i = 0; i < rows1; i++)
        {
            newRow.push_back(m1[i][j]);
        }
        line_m1.push_back(newRow);
    }

    int rows2 = m2.size();
    int cols2 = m2[0].size();

    for (int j = 0; j < cols2; j++)
    {
        vector<float> newRow;
        for (int i = 0; i < rows2; i++)
        {
            newRow.push_back(m2[i][j]);
        }
        line_m2.push_back(newRow);
    }
}

// Function to add matrices
vector<vector<float>> add_matrix(vector<vector<float>> m1, vector<vector<float>> m2)
{
    vector<vector<float>> sum;

    for (int i = 0; i < m1.size(); i++)
    {
        vector<float> row;
        for (int j = 0; j < m1[0].size(); j++)
        {
            row.push_back(m1[i][j] + m2[i][j]);
        }
        sum.push_back(row);
    }

    return sum;
}

// Function to multiply matrices
vector<vector<float>> multiply_matrix(vector<vector<float>> m1, vector<vector<float>> m2)
{
    int rows1 = m1.size();
    int cols1 = m1[0].size();
    int cols2 = m2[0].size();

    vector<vector<float>> product(rows1, vector<float>(cols2, 0));

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                product[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return product;
}

int main()
{
    int rows1, cols1, rows2, cols2;

    cout << "\nFor Matrix 1" << endl;
    cout << "Enter number of rows: ";
    cin >> rows1;
    cout << "Enter number of columns: ";
    cin >> cols1;

    cout << "\nFor Matrix 2" << endl;
    cout << "Enter number of rows: ";
    cin >> rows2;
    cout << "Enter number of columns: ";
    cin >> cols2;

    if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0)
    {
        cout << "Invalid input. Dimensions must be positive." << endl;
        return 0;
    }

    vector<vector<float>> m1(rows1, vector<float>(cols1));
    vector<vector<float>> m2(rows2, vector<float>(cols2));

    cout << "\n--Input Matrix 1 values--" << endl;
    for (int i = 0; i < rows1; i++)
    {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < cols1; j++)
        {
            cin >> m1[i][j];
        }
    }

    cout << "\n--Input Matrix 2 values--" << endl;
    for (int i = 0; i < rows2; i++)
    {
        cout << "Enter row " << i + 1 << ": ";
        for (int j = 0; j < cols2; j++)
        {
            cin >> m2[i][j];
        }
    }

    vector<vector<float>> transpose1;
    vector<vector<float>> transpose2;

    Matrix(m1, m2, transpose1, transpose2);

    // Matrix Addition
    if (rows1 == rows2 && cols1 == cols2)
    {
        vector<vector<float>> added = add_matrix(m1, m2);

        cout << "\nMatrix Addition (m1 + m2):" << endl;
        for (int i = 0; i < added.size(); i++)
        {
            for (int j = 0; j < added[i].size(); j++)
            {
                cout << added[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\nMatrix Addition skipped: Dimensions must be identical." << endl;
    }

    // Matrix Multiplication
    if (cols1 == rows2)
    {
        vector<vector<float>> multiplied = multiply_matrix(m1, m2);

        cout << "\nMatrix Multiplication (m1 * m2):" << endl;
        for (int i = 0; i < multiplied.size(); i++)
        {
            for (int j = 0; j < multiplied[i].size(); j++)
            {
                cout << multiplied[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\nMatrix Multiplication impossible: Columns of Matrix 1 must equal rows of Matrix 2." << endl;
    }

    // Display transpose of Matrix 1
    cout << "\nTranspose of Matrix 1:" << endl;
    for (int i = 0; i < transpose1.size(); i++)
    {
        for (int j = 0; j < transpose1[i].size(); j++)
        {
            cout << transpose1[i][j] << " ";
        }
        cout << endl;
    }

    // Display transpose of Matrix 2
    cout << "\nTranspose of Matrix 2:" << endl;
    for (int i = 0; i < transpose2.size(); i++)
    {
        for (int j = 0; j < transpose2[i].size(); j++)
        {
            cout << transpose2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
