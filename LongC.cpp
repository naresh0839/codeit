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
#define maxn 500005
const int INF = 1e18;
typedef pair<int, int> pii;

signed main() {
    boostIO;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n;
        for (k = 1; k <= n; k++) {
            int x = 0;
            while (x + ((n - x) / 2) != k) {
                x++;
                if (x > n) break;
            }
            int cnt = 0;
            vector<int> v;
            for (int i = 1; i <= n; i++) {
                if (cnt < n - x and i % 2 == 1) {
                    v.pb(-i);
                    cnt++;
                    continue;
                }
                cnt++;
                v.pb(i);
            }  // cout << endl;
            int res = 0;
            cnt = 0;
            for (int i = 0; i < n; i++) {
                res += v[i];
                if (res > 0) cnt++;
            }
            if (cnt != k) {
                cout << k << endl;
            }
        }
    }
    return 0;
}
// XD