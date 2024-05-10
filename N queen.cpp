#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isSafe(vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void nQueensBacktracking(vector<int>& queens, int row, int n, int& count) {
    if (row == n) {
        ++count;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            nQueensBacktracking(queens, row + 1, n, count);
        }
    }
}

void nQueensBranchAndBound(vector<int>& queens, int row, int n, int& count) {
    if (row == n) {
        ++count;
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            nQueensBranchAndBound(queens, row + 1, n, count);
            queens[row] = -1; // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<int> queens(n, -1);
    int count_backtracking = 0;
    int count_branch_and_bound = 0;

    nQueensBacktracking(queens, 0, n, count_backtracking);
    nQueensBranchAndBound(queens, 0, n, count_branch_and_bound);

    cout << "Total solutions using Backtracking: " << count_backtracking << endl;
    cout << "Total solutions using Branch and Bound: " << count_branch_and_bound << endl;

    return 0;
}
