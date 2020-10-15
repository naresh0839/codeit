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
#define maxn 300005
#define N 32
#define int long long
typedef pair<int, int> pii;

int n, m, q;
vector<int> adj[maxn], are[maxn];
int depth[maxn], dim[maxn];
int reg[maxn], used[maxn];

void dfs(int at, int fr, int prt) {
    used[at] = 1;
    reg[at] = prt;
    are[prt].push_back(at);
    depth[at] = depth[fr] + 1;
    for (int to : adj[at]) {
        if (used[to]) continue;
        dfs(to, at, prt);
    }
}

// BEGIN :: Disjoint Set Union
int parent[maxn], siz[maxn];
void make(int v) {
    parent[v] = v;
    siz[v] = 1;
}
int head(int v) {
    if (v == parent[v]) return v;
    return parent[v] = head(parent[v]);
}
void combine(int a, int b) {
    a = head(a), b = head(b);
    if (a != b) {
        if (siz[b] < siz[a]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
// END :: Disjoint Set Union

void solve() {
    cin >> n >> m >> q;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int prt = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        dfs(i, i, prt);
        prt++;
    }
    int root[prt];
    for (int i = 0; i < prt; i++) {
        int amx = 0, tmp = -1;
        for (int j : are[i]) {
            if (depth[j] > amx) {
                amx = depth[j];
                tmp = j;
            }
        }
        root[i] = tmp;
    }
    for (int i = 0; i < maxn; i++) {
        are[i].clear();
        depth[i] = used[i] = 0;
    }
    for (int i = 0; i < prt; i++) {
        make(i);
        dfs(root[i], root[i], i);
    }
    for (int i = 0; i < prt; i++) {
        for (int j : are[i]) {
            dim[head(i)] = max(dim[head(i)], depth[j] - 1);
        }
    }
    // query part done if earlier part goes well
    int h, x, y;
    while (q--) {
        cin >> h;
        if (h == 1) {
            cin >> x;
            x--;
            cout << dim[head(reg[x])] << endl;
        } else {
            cin >> x >> y;
            x--, y--;
            int hx = head(reg[x]), hy = head(reg[y]);
            if (hx != hy) {
                int da = dim[hx], db = dim[hy];
                // calculating diameter of the merged tree
                int pa[2] = {da / 2, (da + 1) / 2};
                int pb[2] = {db / 2, (db + 1) / 2};
                int fdim = max(pa[0] + pa[1], pb[0] + pb[1]);
                rep(i, 0, 2) rep(j, 0, 2) {
                    fdim = max(fdim, pa[i] + pb[j] + 1);
                }
                combine(hx, hy);
                int plz = head(reg[x]);
                dim[plz] = fdim;
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