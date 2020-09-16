#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define F first
#define S second
#define elif else if
#define mp make_pair
#define pb push_back
//#define int long long
#define endl '\n'
#define mpii map<int, int>
#define vpii vector<pair<int, int> >
#define srt(v) v.begin(), v.end()
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
int tree[100005], A[100005];
void seg_build(int node, int start, int end) {
    if (start == end) {
        tree[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        seg_build(2 * node, start, mid);
        seg_build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
void seg_update(int node, int start, int end, int ind, int upd) {
    if (start == end && start == ind) {
        A[ind] = upd;
        tree[node] = A[ind];
    } else {
        int mid = (start + end) / 2;
        if (ind >= start && ind <= mid) {
            seg_update(2 * node, start, mid, ind, upd);
        }
        else if (ind >= mid + 1 && ind <= end) {
            seg_update(2 * node + 1, mid + 1, end, ind, upd);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node];
    }
}
int seg_query(int node, int start, int end, int l, int r) {
    if (start >= l && end <= r) {
        return tree[node];
    }
    if ((end < l) or (start > r)) {
        return 0;
    }
    int mid = (start + end) / 2;
    int q1 = seg_query(2 * node, start, mid, l, r);
    int q2 = seg_query(2 * node + 1, mid + 1, end, l, r);
    return q1 + q2;
}
signed idiot() {
    int n, q;
    cin >> n >> q;
    rep(i, 0, n) {
        cin >> A[i];
    }
    seg_build(1, 0, n - 1);
    seg_update(1, 0, n - 1, 3, 10);
    cout << seg_query(1, 0, n - 1, 0, 3);
    return 0;
}
signed main() {
    boostIO
    idiot();
    return 0;
}
// Naresh Chaudhary
// naresh0839
