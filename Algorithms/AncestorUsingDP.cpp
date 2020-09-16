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
#define siz(v) (v.empty() ? 0 : v.size())
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define fi first
#define se second
#define int long long
#define mod 1000000007
#define rem 998244353
#define maxn 300005
const int INF = 1e18;
typedef pair<int, int> pii;

int n;
int depth[maxn];
vector<int> adj[maxn];
int dp[maxn][20];

void dfs(int at, int fr) {
    dp[at][0] = fr;
    for (int i : adj[at]) {
        if (i == fr) continue;
        depth[i] = depth[at] + 1;
        dfs(i, at);
    }
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

void rewind() {
    cin >> n;
    int u, v;
    repn(i, n - 1) {
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(1, 1);
    // lca calculation
    repn(j, 19)
        repn(i, n)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    
    int x, y;
    cin >> x >> y;
    cout << lca(x, y) << endl;  // lca of x and y
}
signed main() {
    boostIO;
    rewind();
    return 0;
}
// XD