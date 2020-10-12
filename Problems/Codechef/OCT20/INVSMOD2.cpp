#pragma GCC optimize("Ofast")
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define mod 2
#define int long long
int ncrmod2(int n, int p) {
    int mm = n - p, nn = p;
    if (mm & nn) return 0;
    return 1;
}
signed main() {
    boostIO;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        int lim = (1 + sqrtl(1 + 24 * k)) / 6 + 10;
        int ans = ncrmod2(n + k - 1, k), i = 1;
        while ((k - (i * (3 * i - 1) / 2)) >= 0 and i <= lim) {
            int var = k - (i * (3 * i - 1) / 2);
            var = ncrmod2(n - 1 + var, var);
            if (i & 1)
                ans = (ans - var + mod) % mod;
            else
                ans = (ans + var) % mod;
            i++;
        }
        i = 1;
        while ((k - (i * (3 * i - 1) / 2) - i) >= 0 and i <= lim) {
            int var = k - (i * (3 * i - 1) / 2) - i;
            var = ncrmod2(n - 1 + var, var);
            if (i & 1)
                ans = (ans - var + mod) % mod;
            else
                ans = (ans + var) % mod;
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}