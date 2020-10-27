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
#define mem(a, val) memset(a, val, sizeof(a))
#define all(v) (v.begin(), v.end())
#define sz(v) (int)v.size()
#define fi first
#define se second
#define pb push_back
#define maxn 200005
#define int long long
const int mod = 1e9 + 7;

struct edge {
    int v, c, i, d;
    edge(int vv, int cc, int ii, int dd) {
        v = vv, c = cc, i = ii, d = dd;
    }
};
vector<edge> adj[maxn];
int n, m;
int d[maxn], f[maxn];

signed main() {
    boostIO;
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        adj[a].pb(edge(b, c, i, 0));
        adj[b].pb(edge(a, c, i, 1));
        f[a] += c, f[b] += c;
    }
    for (int i = 0; i < n; i++) {
        f[i] /= 2;
    }
    mem(d, -1);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto it : adj[u]) {
            if(d[it.i] != -1) continue;
            d[it.i] = it.d;
            f[it.v] -= it.c;
            if(it.v != n - 1 and !f[it.v]) Q.push(it.v);
        }
    }
    for (int i = 0; i < m; i++) {
        cout << d[i] << endl;
    }  
    return 0;
}
// XD