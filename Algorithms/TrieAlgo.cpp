#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define maxn 100005
#define int long long

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
    return 0;
}
// XD