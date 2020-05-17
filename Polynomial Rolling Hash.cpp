/****
author : naresh0839
Problem : https://codeforces.com/contest/1326/problem/D2
Algorithm : string compared using hash value
****/
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
#define int long long
#define endl '\n'
#define srt(v) v.begin(),v.end()
#define boostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define m 1000000007
#define p 41
 
int powe[1000005]={1};
void hashvalue(string s, int pref[], int suff[]){
	pref[0]=0;
	pref[1]=(s[0]-'a'+1);
	string t=s;
	reverse(t.begin(), t.end());
	suff[0]=0;
	suff[1]=(t[0]-'a'+1);
	rep(i,2,s.length()+1){
		pref[i]=(pref[i-1]+((s[i-1]-'a'+1)*(powe[i-1])))%m;
	}
	rep(i,2,t.length()+1){
		suff[i]=(suff[i-1]+((t[i-1]-'a'+1)*(powe[i-1])))%m;
	}
}
int max_PrefPalindrome(string mid){
	int len=mid.length();
	int pref[len+1];
	int suff[len+1];
	hashvalue(mid, pref, suff);
	int ans=0;
	int alpha;
	if(len%2==0){
		alpha=len/2;
	}
	else{
		alpha=len/2+1;
	}
	rep(i,0,alpha){
		int temp1, temp2;
		if(i==0){
			temp1=powe[len-(2*(i+1))];
			ans=1;
			if(((pref[i+1]*temp1)%m)==((suff[len-(i+1)]-suff[len-(2*(i+1))]+m)%m)){
				ans=2*(i+1);
			}
		}
		eif(i==len/2){
			temp2=powe[len-(2*i+1)];
			if(((pref[i]*temp2)%m)==((suff[len-(i+1)]-suff[len-(2*i+1)]+m)%m)){
				ans=2*i+1;
			}	
		}
		else{
			temp1=powe[len-(2*(i+1))];
			temp2=powe[len-(2*i+1)];
			if(((pref[i]*temp2)%m)==((suff[mid.L-(i+1)]-suff[len-(2*i+1)]+m)%m)){
				ans=2*i+1;
			}
			if(((pref[i+1]*temp1)%m)==((suff[len-(i+1)]-suff[len-(2*(i+1))]+m)%m)){
				ans=2*(i+1);
			}
		}
	}
	return ans;
}
signed idiot()
{
	string s;
	cin >> s;
	string local=s, first;
	reverse(srt(local));
	if(local==s){
		cout << s << endl; return 0;
	}
	int n=s.length(), j, alpha;
	if(n%2==1){
		alpha=n/2+1; j=n/2;	
	}
	else{
		alpha=n/2; j=n/2-1;	
	} 
	rep(i,0,alpha){
		if(s[i]==s[n-1-i]){
			first.pb(s[i]);
		}
		else{
			j=i-1;
			break;
		}
	}
	string second=first;// first palindrome
	reverse(second.begin(), second.end()); // second store last palindrome
	string mid=s.substr(j+1, n-(2*(j+1))); // middle stores middle string
	string rmid=mid;
	reverse(srt(rmid));
	int ans1=max_PrefPalindrome(mid);
	int ans2=max_PrefPalindrome(rmid);
	if(ans1>ans2){
		cout << first << mid.substr(0, ans1) << second << endl;
	}
	else{
		string text=rmid.substr(0, ans2);
		reverse(text.begin(), text.end());
		cout << first << text << second << endl;
	}
	return 0;
}
signed main()
{
	boostIO 
	int t;
	cin >> t;
	rep(i,1,1000004){
		powe[i]=(powe[i-1]*p)%m;
	}
	while(t--)idiot();
	return 0;	
}
