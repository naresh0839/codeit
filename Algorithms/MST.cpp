#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
} edges[MAXN];
//

int n, m, cost = 0;
vector<int> tree_id(MAXN);
vector<Edge> result;

// HELP OF DSU DATA STRUCTURE
int parent[MAXN], size[MAXN];
void make_set(int v) {
    parent[v] = v;
    size[v] = 0;
}
int find_set(int v) {
    return (parent[v] == v ? v : parent[v] = find_set(parent[v]));
}
void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[b] < size[a]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    cin >> n >> m;
    // n == number of vertices
    // m == no of edges in graph
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++) {
        tree_id[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int a = edges[i].u, b = edges[i].v;
        if (find_set(a) == find_set(b)) continue;
        result.push_back(edges[i]);
        union_set(a, b);
    }
<<<<<<< HEAD
    // commit
=======

>>>>>>> fb67aa84c2b7385b90ee401db9748380f0dc8b13
    return 0;
}
