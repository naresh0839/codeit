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
// This is for Ancestor Checking
int entry[200005], exiit[200005];
int timer=0;
void pre_cal(vector<int> vec[], int i){
	entry[i]=timer;	timer++;
	for(auto j: vec[i-1]){
		if(j!=dad[i]){
			dad[j]=i;
			depth[j]=depth[i]+1;
			pre_cal(vec, j);
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
	int n, root_node;
	cin >> n >> root_node;
	vector<int> edge[n];
	depth[root_node]=0;
	dad[root_node]=root_node;
	rep(i,0,n-1){
		int u, v;
		cin >> u >> v;
		edge[u-1].pb(v);
		edge[v-1].pb(u);	
	}
	pre_cal(edge, root_node);
	rep(i,1,n+1){
		cout << entry[i] << " " << exiit[i] << " " << depth[i] << endl;
	}
	return 0;
}
signed main()
{
	boostIO 
	idiot();
	return 0;	
}
