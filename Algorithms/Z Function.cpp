void Z-Function(string &s){
	int n=s.length();
	int arr[n];
	int l=0, r=-1;
	rep(i,1,n){
		arr[i]=(i>r ? 0 : min(r-i+1, arr[i-l]));
		while(i+arr[i]<n && arr[i+arr[i]]==arr[arr[i]]){
			arr[i]++;
		}
		if(i+arr[i]-1>r){
			l=i;
			r=i+arr[i]-1;
		}
	}
}
