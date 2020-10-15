#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, b, a) for (int i = b; i >= a; i--)
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
#define mem(a, val) memset(a, val, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
#define mod 1000000007
#define maxn 100005
#define int long long
typedef pair<int, int> pii;

int seg[4 * maxn][20], lazy[4 * maxn][20];
int A[maxn][20];

int operate(int len, int val, int times) {
    if (times & 1) return (len - val);
    return val;
}
void build(int node, int start, int end, int tn) {
    if (start == end) {
        seg[node][tn] = A[start][tn];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, tn);
    build(2 * node + 1, mid + 1, end, tn);
    seg[node][tn] = seg[2 * node][tn] + seg[2 * node + 1][tn];
}
void update(int node, int start, int end, int l, int r, int val, int tn) {
    if (lazy[node][tn] != 0) {
        seg[node][tn] = operate(end - start + 1, seg[node][tn], lazy[node][tn]);
        if (start != end) {
            lazy[node * 2][tn] += lazy[node][tn];
            lazy[node * 2 + 1][tn] += lazy[node][tn];
        }
        lazy[node][tn] = 0;
    }
    if (start > end or start > r or end < l)
        return;
    if (start >= l and end <= r) {
        seg[node][tn] = operate(end - start + 1, seg[node][tn], val);
        if (start != end) {
            lazy[node * 2][tn] += val;
            lazy[node * 2 + 1][tn] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, val, tn);
    update(node * 2 + 1, mid + 1, end, l, r, val, tn);
    seg[node][tn] = seg[node * 2][tn] + seg[node * 2 + 1][tn];
}
int query(int node, int start, int end, int l, int r, int tn) {
    if (start > end or start > r or end < l)
        return 0;
    if (lazy[node][tn] != 0) {
        seg[node][tn] = operate(end - start + 1, seg[node][tn], lazy[node][tn]);
        if (start != end) {
            lazy[node * 2][tn] += lazy[node][tn];
            lazy[node * 2 + 1][tn] += lazy[node][tn];
        }
        lazy[node][tn] = 0;
    }
    if (start >= l and end <= r)
        return seg[node][tn];
    int mid = (start + end) / 2;
    int p1 = query(node * 2, start, mid, l, r, tn);
    int p2 = query(node * 2 + 1, mid + 1, end, l, r, tn);
    return (p1 + p2);
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 0; j < 20; j++) {
            if ((x >> j) & 1) A[i][j] = 1;
        }
    }
    for (int i = 0; i < 20; i++) {
        build(1, 0, n - 1, i);
    }
    int m, qt, l, r;
    cin >> m;
    while (m--) {
        cin >> qt >> l >> r;
        l--, r--;
        if (qt == 1) {
            // sum from l to r
            int sum = 0;
            for (int i = 0; i < 20; i++) {
                sum += (query(1, 0, n - 1, l, r, i) << i);
            }
            cout << sum << endl;
        } else {
            int x;
            cin >> x;
            // we need to convert a[i] = a[i] ^ x; for l <= i <= r
            for (int i = 0; i < 20; i++) {
                if ((x >> i) & 1) {
                    update(1, 0, n - 1, l, r, 1, i);
                }
            }
        }
    }
}

signed main() {
    boostIO;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
// XD