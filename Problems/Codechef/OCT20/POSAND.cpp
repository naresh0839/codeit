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
#define mod 998244353
#define maxn 300005
const int INF = 1e18;
typedef pair<int, int> pii;

signed main() {
    boostIO;
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        int k = log2(n);
        int kk = (1 << k);
        if (kk == n) {
            cout << -1 << endl;
        } else {
            vector<int> v;
            for (int i = k - 1; i >= 0; i--) {
                int ll = (1 << i), rr = (1 << (i + 1));
                for (int j = ll; j < rr; j++) {
                    v.push_back(j);
                }
            }
            v.push_back(kk + 1);
            v.push_back(kk);
            for (int i = kk + 2; i <= n; i++) {
                v.push_back(i);
            }
            for (int i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// XD