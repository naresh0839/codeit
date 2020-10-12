struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    void build(vector<int> &a) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }
    void update(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }
    void range_update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};