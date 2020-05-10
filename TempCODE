#include <bits/stdc++.h>
using namespace std;
#define boostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,a,b) for(int i=a; i<b; i++)
#define MAXN 1000005
#define int long long
string s, t;
int arr[MAXN][2];
void Z_func(string &s, int p){
	int n = s.length();
	int l = 0, r = -1;
	rep(i, 1, n){
		arr[i][p] = (i > r ? 0 : min(r - i + 1, arr[i - l][p]));
		while(i + arr[i][p] < n && s[i + arr[i][p]] == s[arr[i][p]]){
			arr[i][p]++;
		}
		if(i + arr[i][p] - 1 > r){
			l = i;
			r = i + arr[i][p] - 1;
		}
	}
}
signed main(){
	boostIO
	cin >> s;
	t = s;
	reverse(t.begin() , t.end());
	Z_func(s , 0);
	Z_func(t , 1);

	return 0;
} 

// mod(s) <= 10^6
// ans = substring t of s such that it is prefix, suffix and
//       not an (prefix and suffix)
// ans = max length (for all such answers)
// XD 
