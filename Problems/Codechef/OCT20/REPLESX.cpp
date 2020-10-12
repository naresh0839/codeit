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
#define maxn 400005
const int INF = 1e18;
typedef pair<int, int> pii;

int n, x, p, k;
int a[maxn];

void solve() {
    cin >> n >> x >> p >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[p] == x) {
        cout << "0\n";
        return;
    }
    if (p < k) {
        if (a[p] < x) {
            cout << "-1\n";
            return;
        }
        // i.e. a[p] > x
        int ans;
        for (int i = 1; i <= n; i++) {
            if (a[i] > x) {
                ans = p - i + 1;
                break;
            }
        }
        cout << ans << endl;
        return;
    }
    if (p == k) {
        int ans;
        if (a[p] < x) {
            for (int i = n; i >= 1; i--) {
                if (a[i] < x) {
                    ans = i - p + 1;
                    break;
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (a[i] > x) {
                    ans = p - i + 1;
                    break;
                }
            }
        }
        cout << ans << endl;
        return;
    }
    if (a[p] > x) {
        cout << "-1\n";
        return;
    }
    // i.e. a[p] < x
    int ans;
    for (int i = n; i >= 1; i--) {
        if (a[i] < x) {
            ans = i - p + 1;
            break;
        }
    }
    cout << ans << endl;
}
signed main() {
    boostIO;
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
// XD