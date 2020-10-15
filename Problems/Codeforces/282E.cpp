#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define all(v) (v.begin(), v.end())
#define sz(v) (int)v.size()
#define fi first
#define se second
#define maxn 100005
#define int long long
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef pair<int, int> pii;

int a[maxn];
int trie[42 * maxn][2], nid;
void add(int n) {
    int N = 0;
    for (int i = 40, j; i >= 0; i--) {
        j = (n >> i) & 1;
        if (!trie[N][j]) trie[N][j] = ++nid;
        N = trie[N][j];
    }
}
int gmax(int n) {
    int ans = 0, N = 0;
    for (int i = 40, j; i >= 0; i--) {
        j = (n >> i) & 1;
        if (trie[N][!j]) {
            ans += (1LL << i);
            j ^= 1;
        }
        N = trie[N][j];
    }
    return ans;
}
signed main() {
    boostIO;
    int n;
    cin >> n;
    int xorall = 0, curr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xorall ^= a[i];
    }
    int ans = xorall;
    add(0);
    for (int i = n; i >= 0; i--) {
        curr ^= a[i];
        add(curr);
        ans = max(ans, gmax(xorall ^ curr));
    }
    cout << ans << endl;
    return 0;
}
// XD