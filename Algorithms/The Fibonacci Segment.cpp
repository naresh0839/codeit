#include <bits/stdc++.h> 
using namespace std; 
 
#define rep(i, a, b) for(int i=a; i<b; i++)
#define mp make_pair
#define pb push_back
#define ll long long
#define desc greater<int>()
#define boostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define L length()
#define vs size()
#define eif else if
#define F first
#define S second
#define mod 1000000007
 
int idiot()
{
	int n;
	cin >> n;
	if(n==1 || n==2)
	{
		cout << n;
		return 0;
	}
	ll a[n];
	rep(i, 0, n)
	cin >> a[i];
	int max=0, ct=0;
	rep(i, 2, n)
	{
		if(a[i]==a[i-1]+a[i-2] && i!=n-1)
			ct++;
		eif(a[i]==a[i-1]+a[i-2] && i==n-1)
		{
			ct++;
			if(ct+2>max) max=ct+2;
		}
		else
		{
			if(ct+2>max) max=ct+2;
			ct=0;
		}
	}
	cout << max << endl;
 
	return 0;
}
int main()
{
 	boostIO
 	
 	int t=1;
 	//cin >> t;
 	while(t--)idiot();
	return 0;	
}
