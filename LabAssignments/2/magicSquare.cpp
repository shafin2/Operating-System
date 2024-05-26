// SHAFIN-UZ-ZAMAN
// SP22-BCS-063
// A magic square matrix is matrix in which each row,column,diagonal sum is same

// for input/output
#include <iostream>
// for process management, waiting for child
#include <sys/wait.h>
// provide access to OS api functions like pipe(), fork()
#include <unistd.h>

using namespace std;

int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

string is_magic(int n, int matrix[][10])
{
    // pipe 1 is dedicated for row sum, and pipe 2 is for col sum
    // we create array of 2 pipes that is one for reading like pipe[0] and one for writing pipe[1]
    int pipe1[2], pipe2[2];

    // create pipes
    pipe(pipe1);
    pipe(pipe2);

    pid_t pid;

    // for first child
    pid = fork();

    if (pid < 0)
    {
        return "didn't create 1st child";
    }
    else if (pid == 0)
    {
        // 1st child proces ...

        int first_row_sum = 0, row[n];

        // run loop for no of rows in matrix
        for (int r = 0; r < n; r++)
        {
            // build array of row data
            for (int i = 0; i < n; i++)
            {
                row[i] = matrix[r][i];
            }
            // get sum can row
            int row_sum = sum(row, n);

            // for first row result will be 0, so save sum and continue
            if (first_row_sum == 0)
            {
                first_row_sum = row_sum;
                continue;
            }
            // for 2nd,3rd and other if sum is not equal to 1st one then write -1 and exit
            if (first_row_sum != row_sum)
            {
                int neg = -1;
                // will use pipe[1] to write as tell before, it take pointer var so &neg, and 4 is n of var type that is int
                write(pipe1[1], &neg, 4);
                exit(EXIT_SUCCESS);
            }
        }

        // otherwise write sum value
        write(pipe1[1], &first_row_sum, 4);

        exit(EXIT_SUCCESS);
    }
    else
    {

        pid = fork();

        if (pid < 0)
        {
            return "didn't create 2nd child";
        }
        else if (pid == 0)
        {
            // 2nd child process ...

            int first_col_sum = 0, col[n];

            // run loop for no of cols in matrix
            for (int c = 0; c < n; c++)
            {
                // Build array of column data
                for (int i = 0; i < n; i++)
                {
                    col[i] = matrix[i][c];
                }

                // sum of the current column
                int col_sum = sum(col, n);

                // For the first column, store the sum and continue to the next column
                if (first_col_sum == 0)
                {
                    first_col_sum = col_sum;
                    continue;
                }

                // for 2nd,3rd and other if sum is not equal to 1st one then write -1 and exit
                if (first_col_sum != col_sum)
                {
                    int neg = -1;
                    // Write -1 to the pipe
                    write(pipe2[1], &neg, 4);
                    // Exit the child process
                    exit(EXIT_SUCCESS);
                }
            }

            write(pipe2[1], &first_col_sum, 4);

            exit(EXIT_SUCCESS);
        }
        else
        {

            // waiting for row and col output
            wait(NULL);
            wait(NULL);

            int row, col;

            // get results
            read(pipe1[0], &row, 4);
            read(pipe2[0], &col, 4);


            if (row == -1 || col == -1 || row != col)
                return "It is not magix matrix";


            // now check for main and trailing diagonal
            int diagonal[n], result =0;
            for (int i = 0; i < n; i++)
            {
                diagonal[i] = matrix[i][i];
            }

            result = sum(diagonal, n);

            if (row != result)
                return "It is not magix matrix";

            // For Trailing Diagnol
            for (int i = 0; i < n; i++)
            {
                diagonal[i] = matrix[i][n - 1 - i];
            }

            result = sum(diagonal, n);

            if (row != result)
                return "It is not magix matrix";

            return "It is a magix matrix";
        }
    }
}

int main()
{
    int matrixSize;

    cout << "Enter the size of the square matrix (should be between 1-10): ";
    cin >> matrixSize;

    if (matrixSize <= 0 || matrixSize > 10)
    {
        cout << "Invalid matrix size!" << endl;
        return 1;
    }

    int matrix[10][10];

    for (int row = 0; row < matrixSize; row++)
    {
        for (int col = 0; col < matrixSize; col++)
        {
            cout << "Enter the value at position [" << row << "][" << col << "]: ";
            cin >> matrix[row][col];
        }
    }

    cout << is_magic(matrixSize, matrix) << endl;

    return 0;
}
