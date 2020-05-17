struct tree{
	int n;
	tree(int x){
		n=x;
	}
	vector<int> edg[sz];
	// int timer=0;
	// int tin[n+1], tout[n+1];
	int dad[sz], depth[sz];
	void add(int u, int v){
		edg[u].push_back(v);
		edg[v].push_back(u);
	}
	int leaf(){
		for(int i=1; i<=n; i++){
			if(edg[i].size()==1){
				return i;
			}
		}
	}
	void setup(int root){
		dad[root]=-1;
		depth[root]=0;
	}
	void dfs(int root){
		//tin[root]=timer; timer++;
		for(auto i: edg[root]){
			if(i!=dad[root]){
				dad[i]=root;
				depth[i]=depth[root]+1;
				dfs(i);
			}
		}
		//tout[root]=timer; timer++;
	}
	int parent(int node){
		return dad[node];
	}	
	int height(int node){
		return depth[node];
	}
};
