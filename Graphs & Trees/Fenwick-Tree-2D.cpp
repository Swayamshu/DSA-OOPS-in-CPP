#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
    vector<vector<int>> BIT2D;
    vector<vector<int>> matrix;
    int n, m;

    // 1 based indexing
    void add(int r, int c, int delta) {
        int i = r;
        while (i <= n) {
            int j = c;
            while (j <= m) {
                BIT2D[i][j] += delta;
                j += j & (-j);
            }
            i += i & (-i);
        }
    }

    // 1 based indexing
    int query (int r, int c) {
        int i = r, sum = 0;
        while (i > 0) {
            int j = c;
            while (j > 0) {
                sum += BIT2D[i][j];
                j -= j & (-j);
            }
            i -= i & (-i);
        }
        return sum;
    }
public:
    NumMatrix(vector<vector<int>> matrix) {
        n = matrix.size();
        m = matrix[0].size();
        this->matrix = matrix;
        BIT2D = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                add(r + 1, c + 1, matrix[r][c]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        add(row + 1, col + 1, val - matrix[row][col]);
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2+1, col2+1) - query(row1, col2+1) - query(row2+1, col1) + query(row1, col1);
    }
};

class FenwickTree2D {
    vector<vector<int>> BIT2D;
    vector<vector<int>> matrix;
    int n, m;

    // 1 based indexing
    void add(int r, int c, int delta) {
        while (r <= n) {
            while (c <= m) {
                BIT2D[r][c] += delta;
                c += c & (-c);
            }
            r += r & (-r);
        }
    }

    // 1 based indexing
    int query (int r, int c) {
        int sum = 0;
        while (r <= n) {
            while (c <= m) {
                sum += BIT2D[r][c];
                c -= c & (-c);
            }
            r -= r & (-r);
        }
        return sum;
    }
public:
    FenwickTree2D(vector<vector<int>> &matrix) {
        n = matrix.size();
        m = matrix[0].size();
        this->matrix = matrix;
        BIT2D = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                add(r + 1, c + 1, matrix[r][c]);
            }
        }
    }

    void update(int r, int c, int val) {
        add(r + 1, c + 1, val - matrix[r][c]);
        matrix[r][c] = val;
    }

    int rangeSum2D (int r1, int c1, int r2, int c2) {
        return query(r1 + 1, c1 + 1) - query(r2, c2); 
    }
};

int main() {
    return 0;
}