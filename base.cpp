#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
#define mem(a, val) memset(a, val, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define popcount(x) __builtin_popcountll(x)

template<typename T, typename U> static inline void amn(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static inline void amx(T &x, U y) { if(x < y) x = y; }

const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int N = 5e5 + 5;

void solve() {
    
}
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef SIEVE
        sieve();
    #endif
    int test_case = 1;
    cin >> test_case;
    while (test_case--) {
        solve();
    }
    return 0;
}