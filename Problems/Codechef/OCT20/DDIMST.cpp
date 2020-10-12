#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repn(i, n) for (int i = 1; i <= n; i++)
#define all(v) (v.begin(), v.end())
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) for (long blockTime = 0; (blockTime == 0 ? (blockTime = clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef pair<int, int> pii;
const int INF = 1e6;

int n, d;
int dp[maxn][32], per[5];
vector<pii> v[32];
int vis[maxn];

signed main() {
    time__("solve") {
        cin >> n >> d;
        int dd = (1 << d);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                cin >> per[j];
            }
            for (int j = 0; j < dd; j++) {
                for (int k = 0; k < d; k++) {
                    if ((j >> k) & 1) {
                        dp[i][j] += per[k];
                    } else {
                        dp[i][j] -= per[k];
                    }
                }
            }
        }

        for (int j = 0; j < dd; j++) {
            for (int i = 1; i < n; i++) {
                v[j].push_back({dp[i][j], i});
            }
        }

        for (int j = 0; j < dd; j++) {
            sort(v[j].begin(), v[j].end());
        }

        set<int> used;

        int plz[dd][2];
        for (int i = 0; i < dd; i++) {
            plz[i][0] = 0;      // pointing on minimum
            plz[i][1] = n - 2;  // pointing on maximum
        }

        ll ans = 0;

        // array for the mst included vertices
        int cmst[2][dd];  // 0 is minimum and 1 is maximum
        for (int i = 0; i < dd; i++) {
            cmst[0][i] = cmst[1][i] = dp[0][i];
        }

        int var, val, ii;
        repn(_, n - 1) {
            val = -INF, ii = -1;
            for (int i = 0; i < dd; i++) {
                while (vis[v[i][plz[i][0]].se]) {
                    plz[i][0]++;
                }
                while (vis[v[i][plz[i][1]].se]) {
                    plz[i][1]--;
                }
                int res1 = cmst[1][i] - v[i][plz[i][0]].fi;
                int res2 = v[i][plz[i][1]].fi - cmst[0][i];
                int res = max(res1, res2);
                if (res > val) {
                    val = res;
                    ii = i;
                }
            }
            ans += val;
            int res1 = cmst[1][ii] - v[ii][plz[ii][0]].fi;
            int res2 = v[ii][plz[ii][1]].fi - cmst[0][ii];
            int idx = (res1 > res2 ? v[ii][plz[ii][0]].se : v[ii][plz[ii][1]].se);
            vis[idx] = 1;
            for (int i = 0; i < dd; i++) {
                cmst[1][i] = max(cmst[1][i], dp[idx][i]);
                cmst[0][i] = min(cmst[0][i], dp[idx][i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
// XD