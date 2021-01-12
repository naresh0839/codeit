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
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define popcount(x) __builtin_popcountll(x)
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define maxn 100005
#define int long long
typedef pair<int, int> pii;

void quicksort(int a[], int start, int end) {
	if (start >= end) return;
	
    int pivot = a[end], pidx = start;
	for (int i = start; i < end; i++) {
		if (a[i] <= pivot) {
			swap(a[pidx++], a[i]);
		}
	}
	swap(a[pidx], a[end]);

	quicksort(a, start, pidx - 1);
	quicksort(a, pidx + 1, end);
}
signed main() {
    boostIO;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
    	cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
// XD