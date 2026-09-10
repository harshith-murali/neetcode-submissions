class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;
        return backtrack(0, n, cols, diag1, diag2);
    }

    int backtrack(int row, int n, unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        if (row == n) {
            return 1;
        }

        int count = 0;
        for (int col = 0; col < n; col++) {
            int d1 = row - col;
            int d2 = row + col;

            if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) {
                continue;
            }

            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);

            count += backtrack(row + 1, n, cols, diag1, diag2);

            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }

        return count;
    }
};