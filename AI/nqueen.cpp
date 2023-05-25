#include <bits/stdc++.h>

using namespace std;

// Function to check if placing a queen at a given position is safe
bool isSafe(int row, int col, vector<int> &board, int n)
{
    // Checking for conflicts with previously placed queens
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
            return false;
    }
    return true;
}

// Backtracking approach to solve the N-Queens problem
bool solveNQueensBacktracking(int row, vector<int> &board, int n)
{
    if (row == n)
    {
        return true; // All queens have been placed successfully
    }

    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, board, n))
        {
            // Place the queen at the current position
            board[row] = col;

            // Recursively try placing queens in the next row
            if (solveNQueensBacktracking(row + 1, board, n))
                return true;

            // If placing the queen at the current position does not lead to a solution,
            // backtrack and remove the queen from the current position
            board[row] = -1;
        }
    }

    return false; // No solution found
}

// Function to display the board configuration
void displayBoard(const vector<int> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

// Branch and Bound approach to solve the N-Queens problem
void solveNQueensBranchAndBound(int row, vector<int> &board, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2, int n, bool &found)
{
    if (row == n)
    {
        found = true;
        cout << "Solution using Branch And Bound:\n";
        displayBoard(board);
        return;
    }

    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        if (cols[col] && diag1[row + col] && diag2[row - col + n - 1])
        {
            // Place the queen at the current position
            board[row] = col;
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;

            // Recursively try placing queens in the next row
            solveNQueensBranchAndBound(row + 1, board, cols, diag1, diag2, n, found);

            // If a solution is found, no need to explore further
            if (found)
                return;

            // If placing the queen at the current position does not lead to a solution,
            // backtrack and remove the queen from the current position
            board[row] = -1;
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the value of N : ";
    cin >> n;

    // Solve using Backtracking
    vector<int> boardBacktracking(n, -1);
    bool solutionBacktracking = solveNQueensBacktracking(0, boardBacktracking, n);

    if (solutionBacktracking)
    {
        cout << "Solution using Backtracking:\n";
        displayBoard(boardBacktracking);
    }
    else
    {
        cout << "No solution using Backtracking.\n";
    }

    // Solve using Branch and Bound
    vector<int> boardBranchAndBound(n, -1);
    vector<bool> cols(n, true);
    vector<bool> diag1(2 * n - 1, true);
    vector<bool> diag2(2 * n - 1, true);
    bool foundSolutionBranchAndBound = false;
    solveNQueensBranchAndBound(0, boardBranchAndBound, cols, diag1, diag2, n, foundSolutionBranchAndBound);

    if (!foundSolutionBranchAndBound)
    {
        cout << "No solution using Branch and Bound.";
    }
    return 0;
}

/*

Enter the value of N : 5
Solution using Backtracking:
Q - - - - 
- - Q - - 
- - - - Q 
- Q - - - 
- - - Q - 

Solution using Branch And Bound:
Q - - - - 
- - Q - - 
- - - - Q 
- Q - - - 
- - - Q - 

*/
