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
#define fi first
#define se second
#define pb push_back
#define int long long
#define mod 1000000007
#define rem 998244353
#define maxn 1000005
const int INF = 1e18;
typedef pair<int, int> pii;

signed main() {
    boostIO;
    int n;
    cin >> n;
    int fac[maxn];
    fac[0] = 1;
    for(int i = 1; i < maxn; i++){
        fac[i] = fac[i - 1] * i % mod;
    }
    int num = 1;
    repn(i, n - 1){
        num *= 2;
        num %= mod;
    }
    int ans = (fac[n] - num + mod) % mod;
    cout << ans << endl;
    return 0;
}
// XD