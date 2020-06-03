// https://codeforces.com/contest/160/problem/D
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define MAXN 100005
typedef pair<int, int> pii;
int n, m;

struct Edge {
    int u, v, weight, id;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
} edg[MAXN];

// DSU Data Structure
int parent[MAXN], size[MAXN];
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[b] < size[a])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

// TARJAN
vector<int> adj[MAXN];
map<int, int> used, tin, low;
set<pii> any;
int timer;
void dfs(int v, int p = -1) {
    used[v] = true;
    tin[v] = low[v] = timer++;
    for (auto to : adj[v]) {
        if (to == p) continue;
        if (used[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                any.insert({v, to}), any.insert({to, v});
        }
    }
}
void reset() {
    timer = 1;
    used.clear();
    tin.clear();
    low.clear();
}
// END :: Tarjan to find the bridge

int main() {
    boostIO;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> edg[i].u >> edg[i].v >> edg[i].weight;
        edg[i].id = i;
    }
    sort(edg, edg + m);
    // DSU initialization
    for (int i = 1; i <= n; ++i) {
        make_set(i);
    }
    int ans[m];  // 0 - any , 1 - at least one, 2 - none

    // for processing same weight components
    int j;
    for (int i = 0; i < m; i = j) {
        j = i;
        while (j < m and (edg[j].weight == edg[i].weight)) {
            ++j;
        }
        for (int k = i; k < j; k++) {
            Edge& e = edg[k];
            int a = find_set(e.u), b = find_set(e.v);
            if (a == b) {
                ans[e.id] = 2;
            } else {
                ans[e.id] = 1;
            }
            adj[a].clear();
            adj[b].clear();
        }
        for (int k = i; k < j; k++) {
            Edge& e = edg[k];
            int a = find_set(e.u), b = find_set(e.v);
            if (a != b) {
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
            }
        }

        reset();

        for (int k = i; k < j; k++) {
            Edge& e = edg[k];
            int a = find_set(e.u), b = find_set(e.v);
            if (a != b) {
                if (!used[e.u]) {
                    dfs(e.u);
                }
                if (!used[e.v]) {
                    dfs(e.v);
                }
            }
        }
        for (int k = i; k < j; k++) {
            Edge& e = edg[k];
            if (any.count({e.u, e.v}) || any.count({e.v, e.u})) {
                ans[e.id] = 0;
            }
        }
        for (int k = i; k < j; k++) {
            int a = find_set(edg[k].u), b = find_set(edg[k].v);
            union_set(a, b);
        }
    }

    for (int i = 0; i < m; i++) {
        if (ans[i] == 0) {
            cout << "any" << endl;
        } else if (ans[i] == 1) {
            cout << "at least one" << endl;
        } else {
            cout << "none" << endl;
        }
    }
    return 0;
}
