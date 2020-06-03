#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long
#define MAXN1 50005
#define MAXN2 505

int n, k;
vector<int> edg[MAXN1];
int dad[MAXN1];
int dp[MAXN1][MAXN2];
int answer = 0;

void dfs1(int node) {
    for (auto i : edg[node]) {
        if (i != dad[node]) {
            dad[i] = node;
            dfs1(i);
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] == 0) break;
                dp[node][j + 1] += dp[i][j];
            }
        }
    }
}
void dfs2(int node) {
    for (auto i : edg[node]) {
        if (i != dad[node]) {
            for (int j = 0; j <= k - 2; j++) {
                if (dp[i][j] == 0) break;
                answer += (dp[i][j] * (dp[node][k - j - 1] - dp[i][k - j - 2]));
            }
        }
    }
    for (auto i : edg[node]) {
        if (i != dad[node]) {
            dfs2(i);
        }
    }
}
signed main() {
    boostIO;
    cin >> n >> k;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    dad[1] = -1;
    dfs1(1);
    dfs2(1);
    answer /= 2;
    for (int i = 1; i <= n; ++i) {
        answer += dp[i][k];
    }
    printf("%I64d\n", answer);
    return 0;
}
// XD