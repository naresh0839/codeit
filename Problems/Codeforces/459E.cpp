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

int n, m;
int dp[maxn], tmp[maxn];
vector<pii> v[maxn];

void solve() {
    cin >> n >> m;
    for (int i = 0, w, a, b; i < m; i++) {
        cin >> a >> b >> w;
        v[w].push_back({a, b});
    }
    for (int i = maxn; i >= 0; i--) {
        for (pii it : v[i]) {
            tmp[it.fi] = 0;
        }
        for (pii it : v[i]) {
            tmp[it.fi] = max(tmp[it.fi], dp[it.se] + 1);
        }
        for (pii it : v[i]) {
            dp[it.fi] = max(dp[it.fi], tmp[it.fi]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
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