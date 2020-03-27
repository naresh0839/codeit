#include <bits/stdc++.h> 
using namespace std; 

#define rep(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second
#define L length()
#define eif else if
#define mp make_pair
#define sz(x) (int)x.size()
#define pb push_back
//#define int long long
#define endl '\n'
#define srt(v) v.begin(),v.end()
#define boostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
int depth[200005], dad[200005];
int dep=0;
void node_depth(vector<int> vec[], int i){
	dep=depth[i]+1;
	for(auto j: vec[i-1]){
		if(j!=dad[i]){
			depth[j]=dep;
		}
	}
	for(auto j: vec[i-1]){
		if(j!=dad[i]){
			node_depth(vec, j);
		}	
	}  
}
// This is for Ancestor Checking
int entry[200005], exiit[200005];
int timer=0;
void ancestor(vector<int> vec[], int i){
	entry[i]=timer;	timer++;
	for(auto j: vec[i-1]){
		if(j!=dad[i]){
			dad[j]=i;
			ancestor(vec, j);
		}
	}
	exiit[i]=timer;	timer++;
}
bool isParent(int a, int b){
	return (entry[a]<=entry[b] && exiit[a]>=exiit[b]);
}
// This is for Ancestor Checking
signed idiot()
{
	depth[1]=0;
	int n;
	cin >> n;
	vector<int> edge[n];
	dad[1]=1;
	rep(i,0,n-1){
		int u, v;
		cin >> u >> v;
		edge[u-1].pb(v);
		edge[v-1].pb(u);	
	}
	ancestor(edge, 1);
	node_depth(edge, 1);
	return 0;
}
signed main()
{
	boostIO 
	int test_case=1;
	//cin >> t;
	while(test_case--)idiot();
	return 0;	
}
