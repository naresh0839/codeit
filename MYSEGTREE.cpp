#define MAX 200005
int A[MAX]; 
struct segtree{
	int tree[4*MAX];
	void seg_build(int node, int start, int end){
		if(start==end){
			tree[node]=A[start];
		}
		else{
			int mid=(start+end)/2;
			seg_build(2*node, start, mid);
			seg_build(2*node+1, mid+1, end);
			tree[node]=tree[2*node]+tree[2*node+1];
		}
	}
	void seg_update(int node, int start, int end, int ind, int upd){
		if(start==end && start==ind){
			A[ind]=upd;
			tree[node]=A[ind];
		}
		else{
			int mid=(start+end)/2;
			if(ind>=start && ind<=mid){
				seg_update(2*node, start, mid, ind, upd);
			}
			else if(ind>=mid+1 && ind<=end){
				seg_update(2*node+1, mid+1, end, ind, upd);
			}
			tree[node]=tree[2*node+1]+tree[2*node];
		}
	}
	int seg_query(int node, int start, int end, int l, int r){
		if(start>=l && end<=r){
			return tree[node];
		}
		if((end<l) or (start>r)){
			return 0;
		}
		int mid=(start+end)/2;
		int q1=seg_query(2*node, start, mid, l, r);
		int q2=seg_query(2*node+1, mid+1, end, l, r);
		return q1+q2;
	}
	int query_fullrange(){
		return tree[1];
	}
};
