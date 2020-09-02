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
#define MAXN 300005
#define MOD 1000000007

struct DSU {
    int parent[MAXN], siz[MAXN];
    void make_set(int v) {
        parent[v] = v;
        siz[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (siz[b] < siz[a])
                swap(a, b);
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