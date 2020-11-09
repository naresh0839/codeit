#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, b) for (int i = 0; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define rrep(i, b, a) for (int i = b; i >= a; i--)
#define sz(v) (v.empty() ? 0 : v.size())
#define all(v) v.begin(), v.end()
#define mem(a, val) memset(a, val, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define int long long
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
#define maxn 500005
#define mod 1000000007
#define N 1005
const int INF = 1e18;
typedef pair<int, int> pii;

signed main() {
    boostIO;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> inc;
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(all(inc), a[i]);
        // lower bound for strictly increasing
        // upper bound for simply increasing
        if (pos == end(inc))
            inc.push_back(a[i]);
        else
            *pos = a[i];
    }
    cout << sz(inc) << endl;
    return 0;
}
// XD