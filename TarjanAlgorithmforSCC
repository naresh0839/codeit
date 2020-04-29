#include <bits/stdc++.h>
using namespace std;
#define max 100005
#define mod 1000000007
#define int long long
// Tarjan Algorithm //////////////////////////////////////////////
int v, e, a, b;
vector<int> g[max], gt[max];
vector<bool> visit;
vector<int> seq, scc;
void dfs1(int i){
	visit[i]=true;
	for(auto j: g[i]){
		if(!visit[j]) dfs1(j);
	}
	seq.push_back(i);
}
void dfs2(int i){
	visit[i]=true;
	scc.push_back(i);
	for(auto j: gt[i]){
		if(!visit[j]) dfs2(j);
	}
}
/////////////////////////////////////////////////////////////////
signed main(){
    cin >> v >> e;
    for(int i=0; i<e; i++){
    	cin >> a >> b;
    	a--; b--;
    	g[a].push_back(b); // g represenets original graph
    	gt[b].push_back(a); // gt represents transpose of g
    }
    visit.assign(n, false);
    for(int i=0; i<n; i++){
    	if(!visit[i]) dfs1(i);
    }
    visit.assign(n, false);
    for(int i=n-1; i>=0; i--){
    	int x=seq[i];
    	if(!visit[x]){
    		dfs2(x);
    		// scc is filled with component
    		scc.clear(); // clear to fill new component
    	}
    }
}

ALGORITHM::::::::::

1st step. Run sequence of depth first search of graph G which will return vertices with increasing exit
time tout, i.e. some list order.

2nd step. Build transposed graph GT. Run a series of depth (breadth) first searches in the order determined
by list order (to be exact in reverse order, i.e. in decreasing order of exit times). Every set of vertices,
reached after the next search, will be the next strongly connected component.

Algorithm asymptotic is O(n+m), because it is just two depth (breadth) first searches.
