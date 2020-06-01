#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, b, a) for (int i = b; i >= a; i--)
#define F first
#define S second
#define int long long
#define MAXN 300005
#define MOD 1000000007

int n;                  // number of nodes
vector<int> edg[MAXN];  // adjacency list

vector<int> tin, low;
vector<bool> used;
int timer;

void IS_BRIDGE(int l, int r) {
    cout << l << " " << r << endl;
}
void dfs(int at, int fr = -1) {
    used[at] = true;
    tin[at] = low[at] = timer++;
    for (auto to : edg[at]) {
        if (to == fr) continue;
        if (used[to]) {
            low[at] = min(low[at], tin[to]);
        } else {
            dfs(to, at);
            low[at] = min(low[at], low[to]);
            if (low[to] > tin[at]) {
                IS_BRIDGE(to, at);
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    tin.assign(n, -1);
    low.assign(n, -1);
    used.assign(n, false);
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        dfs(i);
    }
}

signed main() {
    boostIO;

    return 0;
}
// XD
