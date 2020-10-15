#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, b, a) for (int i = b; i >= a; i--)
#define F first
#define S second
#define int long long
#define maxn 300005
#define MOD 1000000007

struct DSU {
    int parent[maxn], siz[maxn];
    void make(int v) {
        parent[v] = v;
        siz[v] = 1;
    }
    int head(int v) {
        if (v == parent[v]) return v;
        return parent[v] = head(parent[v]);
    }
    void combine(int a, int b) {
        a = head(a), b = head(b);
        if (a != b) {
            if (siz[b] < siz[a]) swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
};

signed main() {
    boostIO;

    return 0;
}
// XD