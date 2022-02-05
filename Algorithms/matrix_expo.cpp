struct matrix_expo {
    typedef vector<vector<int> > matrix_t;
    matrix_t tr;
    int m;
    matrix_expo(int _size) {
        m = _size;
        tr = vector<vector<int> > (m, vector<int>(m));
    }
    void setTranspose(int x, int y, int val) {
        tr[x][y] = val;
    }
    matrix_t mult(matrix_t a, matrix_t b) {
        matrix_t r(m, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                r[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    r[i][j] += a[i][k] * b[k][j];
                    r[i][j] %= MOD;
                }
            }
        }
        return r;
    }
    matrix_t matrixExpo(int p) { // p >= 1
        if (p == 1) return tr;
        matrix_t half = matrixExpo(p / 2);
        half = mult(half, half);
        if (p & 1) half = mult(half, tr);
        return half;
    }
};