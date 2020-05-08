#include <bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long

// Variables
#define MAXN 100005
#define K 26
int n;
int st[MAXN][K];
int a[MAXN];

int fx(int x, int y){
	return x + y;
}
void sparse_build(){
	for(int i = 0; i < n; i++){
		st[i][0] = fx(a[i], 0);
	}
	for(int j = 1; j < K; j++){
		for(int i = 0; i + (1 << j) <= n; i++){
			st[i][j] = fx(st[i][j-1], st[i + (1 << (j-1))][j-1]);
		}
	}
}
int sparse_query(int l, int r){
	int sum = 0;
	for(int j=K; j>=0; j--){
		if((1 << j) <= r - l + 1){
			sum += (st[l][j]);
			l += (1 << j);
		}
	}
	return sum;
}
signed main(){
	boostIO
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sparse_build();
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << sparse_query(l, r) << endl;
	}
	return 0;
}
// XD
