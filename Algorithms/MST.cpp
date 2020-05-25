#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
}edges[MAXN];

int n, m, cost = 0; 
vector<int> tree_id(MAXN);
vector<Edge> result;

int main(){
    cin >> n >> m;
    // n == number of vertices
    // m == no of edges in graph
    for(int i = 0; i < m; ++i){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    sort(edges, edges + m);
    for (int i = 0; i < n; i++){
        tree_id[i] = i;
    }
    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);
            
            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }    
    return 0;
}





