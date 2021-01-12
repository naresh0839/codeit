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
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.id()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define idl '\n'
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define rem 998244353
#define maxn 200005
#define p 41
typedef pair<int, int> pii;

void quick_sort(int a[], int start, int end) {
    if (start >= end) return;
    int pivot = a[end], pidx = end; // pidx represents partition index
    // taking pivot as the end element of the current array
    swap(a[start], a[end]);
    for (int i = end; i > start; i--) {
        if (a[i] >= pivot) {
            swap(a[i], a[pidx--]);
        }
    }
    swap(a[start], a[pidx]);
    quick_sort(a, start, pidx - 1);
    quick_sort(a, pidx + 1, end);
}
signed main() {
    boostIO;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    } cout << endl;
    return 0;
}
// XD