#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solveNQueens(int n, int first_queen_col) {
    set<int> col, posDiag, negDiag;
    vector<vector<string>> res;
    vector<vector<string>> board(n, vector<string>(n, "."));

    function<void(int)> backtrack = [&](int r) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = "Q";

            backtrack(r + 1);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = ".";
        }
    };

    col.insert(first_queen_col);
    posDiag.insert(0 + first_queen_col);
    negDiag.insert(0 - first_queen_col);
    board[0][first_queen_col] = "Q";

    backtrack(1);

    return res;
}

int main() {
    int n = 8;
    int first_queen_col = 0;
    vector<vector<string>> boards = solveNQueens(n, first_queen_col);

    for (auto& board : boards) {
        for (auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
