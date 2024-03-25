#include <iostream>
#include <fstream>

#define MAX_SIZE 20

using namespace std;

// 2. Function to print matrix
void printer(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int dim)
{
    cout << "Matrix A: " << endl;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << matA[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "Matrix B: " << endl;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << matB[i][j] << '\t';
        }
        cout << endl;
    }
}

// 3. Function to add matrix A and B
void adder(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int dim)
{

    cout << "3. Addition: Matrix A + Matrix B" << endl;
    int result[dim][dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            result[i][j] = matA[i][j] + matB[i][j];
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

// 4. Function to multiply matrix A and B
void multiplier(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int dim)
{
    cout << "4. Multiplication: Matrix A x Matrix B" << endl;
    int result[dim][dim];
    int addition = 0;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            addition = 0;
            for (int k = 0; k < dim; k++)
            {
                addition = addition + (matA[i][k] * matB[k][j]);
            }
            result[i][j] = addition;
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

// 5. Functions to subtract matrix B from A
void subtractor(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int dim)
{
    cout << "5. Subtraction: Matrix A - Matrix B" << endl;
    int result[dim][dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            result[i][j] = matA[i][j] - matB[i][j];
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

// 6. Update an element (taking row num and col num) in the first matrix
void updateElem(int mat[MAX_SIZE][MAX_SIZE], int i, int j, int val, int dim)
{
    mat[i][j] = val;
    cout << "6. Updated Matrix A:" << endl;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            cout << mat[i][j] << '\t';
        }
        cout << endl;
    }
}

// 7. Get the max value of first matrix.
void maxVal(int mat[MAX_SIZE][MAX_SIZE], int dim)
{
    int maxval = mat[0][0];
    cout << "7. Maximum Value of Matrix A:" << endl;
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (maxval < mat[i][j])
            {
                maxval = mat[i][j];
            }
        }
    }
    cout << "Maximum Value = " << maxval << endl;
}

// 8. Transpose the first matrix
void transpose(int mat[MAX_SIZE][MAX_SIZE], int dim)
{
    cout << "8. Transpose: Matrix A" << endl;
    int result[dim][dim];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            result[i][j] = mat[j][i];
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }
}

int main()
{
    // 1. Read from file and save it into matrix A and matrix B
    ifstream file("input.txt"); // Open the file
    if (!file.is_open())
    {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    int n;
    file >> n; // Read the dimension of the square matrix
    if (n > MAX_SIZE)
    {
        cerr << "Matrix size exceeds maximum allowed size" << endl;
        return 1;
    }

    int matA[MAX_SIZE][MAX_SIZE];
    int matB[MAX_SIZE][MAX_SIZE];

    // Read values into matrix a
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> matA[i][j];
        }
    }

    // Read values into matrix b
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file >> matB[i][j];
        }
    }

    // Close the file
    file.close();

    printer(matA, matB, n);
    cout << endl;
    adder(matA, matB, n);
    cout << endl;
    multiplier(matA, matB, n);
    cout << endl;
    subtractor(matA, matB, n);
    cout << endl;
    updateElem(matA, 2, 2, 40, n);
    cout << endl;
    maxVal(matA, n);
    cout << endl;
    transpose(matA, n);
    cout << endl;

    return 0;
};