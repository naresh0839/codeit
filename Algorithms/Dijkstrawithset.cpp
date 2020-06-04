#define MAXN 100005
typedef pair<int, int> pii;
const int INF = 1000000000;
int n;
set<pii> adj[MAXN];
vector<int> d, p;
void dijkstra(int s) {
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pii> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}