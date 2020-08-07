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
#define siz(v) (v.empty() ? 0 : v.size())
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define fi first
#define se second
#define int long long
#define mod 1000000007
#define maxn 100005
const int INF = 1e18;
typedef pair<int, int> pii;
void rewind() {
    string s;
    cin >> s;
    s.pb('$');
    int n = s.length();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int> > v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {s[i], i};
        }
        sort(all(v));
        for (int i = 0; i < n; i++)
            p[i] = v[i].se;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c[p[i]] = c[p[i - 1]];
            if (v[i].fi != v[i - 1].fi) c[p[i]]++;
        }
    }
    int k = 0;
    vector<pair<pii, int> > v(n);
    while ((1 << k) < n) {
        for (int i = 0; i < n; i++) {
            v[i] = {{c[i], c[i + (1 << k)]}, i};
        }
        sort(all(v));
        for (int i = 0; i < n; i++) {
            p[i] = v[i].se;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            c[p[i]] = c[p[i - 1]];
            if (v[i].fi != v[i - 1].fi) c[p[i]]++;
        }
        k++;
    }
    trav(i, p) {
        cout << i << " " << s.substr(i, n - i) << endl;
        ;
    }
}
signed main() {
    boostIO;
    rewind();
    return 0;
}
// XD