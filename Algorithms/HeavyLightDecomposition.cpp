// Refer below for hld of sum on u to v

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
#define sz(v) (v.empty() ? 0 : v.size())
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define int long long
#define mod 1000000007
#define rem 998244353
#define maxn 100005
const int INF = 1e18;
typedef pair<int, int> pii;

int A[maxn], init[maxn];

struct SegmentTree {
    vector<int> tree;
    SegmentTree(int n) {
        tree.assign(4 * n, 0);
    }
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = init[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    void update(int node, int start, int end, int ind, int upd) {
        if (start == end && start == ind) {
            init[ind] = tree[node] = upd;
        } else {
            int mid = (start + end) / 2;
            if (ind >= start && ind <= mid) {
                update(2 * node, start, mid, ind, upd);
            } else if (ind >= mid + 1 && ind <= end) {
                update(2 * node + 1, mid + 1, end, ind, upd);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node];
        }
    }
    int query(int node, int start, int end, int l, int r) {
        if (start >= l && end <= r) {
            return tree[node];
        }
        if ((end < l) or (start > r)) {
            return 0;
        }
        int mid = (start + end) / 2;
        int q1 = query(2 * node, start, mid, l, r);
        int q2 = query(2 * node + 1, mid + 1, end, l, r);
        return q1 + q2;
    }
} seg(maxn);

struct HLD {
    vector<int> dad, depth, heavy, head, pos;
    vector<vector<int> > adj, dp;
    int cur_pos = 0, N;

    HLD(int n) {
        N = n;
        n++;
        depth.resize(n);
        dad.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        adj.resize(n);
        dp.resize(n, vector<int>(20, 0));
        cur_pos = 0;
    }
    // initializer
    void add(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dfs(int at, int fr) {
        dad[at] = fr, dp[at][0] = fr, depth[at] = depth[fr] + 1;
        int siz = 1, max_siz = 0;
        for (int to : adj[at]) {
            if (to == fr) continue;
            int csiz = dfs(to, at);
            siz += csiz;
            if (csiz > max_siz) {
                max_siz = csiz;
                heavy[at] = to;
            }
        }
        return siz;
    }
    // heavy edges calculation
    void decompose(int at, int fr) {
        head[at] = fr, pos[at] = cur_pos++;
        if (heavy[at] != -1) {
            decompose(heavy[at], fr);
        }
        for (int to : adj[at]) {
            if (to != dad[at] and to != heavy[at])
                decompose(to, to);
        }
    }
    // head and pos calcalutor
    void lca_seg_cal() {
        repn(j, 19) repn(i, N) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
        repn(i, N) init[pos[i]] = A[i];
    }
    int lca(int x, int y) {
        if (depth[x] < depth[y]) swap(x, y);
        rrep(i, 19, 0) {
            if (depth[dp[x][i]] >= depth[y]) x = dp[x][i];
        }
        if (x == y) return x;
        rrep(i, 19, 0) {
            if (dp[x][i] != dp[y][i]) {
                x = dp[x][i], y = dp[y][i];
            }
        }
        return dp[x][0];
    }
    // lca calculator
    int query(int a, int b) {
        int res = 0;
        while (head[a] != head[b]) {
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            int result_headb_b = seg.query(1, 0, N - 1, pos[head[b]], pos[b]);
            res += result_headb_b;
            b = dad[head[b]];
        }
        // now both a & b are in same paths so we need to query for pos[a] -> pos[b]
        if (depth[a] > depth[b]) swap(a, b);
        int result_a_b = seg.query(1, 0, N - 1, pos[a], pos[b]);
        res += result_a_b;
        return res;
    }
    void solve(int tt) {
        if (tt) {
            int u, val;
            cin >> u >> val;
            seg.update(1, 0, N - 1, pos[u], val);
        } else {
            int l, r;
            cin >> l >> r;
            int baap = lca(l, r);
            int ans = query(l, baap) + query(r, baap) - init[pos[baap]];
            cout << ans << endl;
        }
    }
};

signed main() {
    boostIO;
    int n;
    cin >> n;
    repn(i, n) cin >> A[i];

    HLD hld(n);  // heavy light decomposition

    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        hld.add(u, v);
    }

    hld.dfs(1, 1);
    hld.decompose(1, 1);
    hld.lca_seg_cal();
    seg.build(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int tt;
        cin >> tt;
        hld.solve(tt);
    }
    return 0;
}
// XD