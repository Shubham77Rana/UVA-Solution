#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		vi<int> a(n);
		for(int &x:a) cin >> x;
		a.pb(a[0]);
		int ret = 0;
		for(int i=1; i<n+1; ){
			int peak = a[i]-a[i-1];
			while((peak<0&&a[i]-a[i-1]<0)||(peak>0&&a[i]-a[i-1]>0))
				++i;
			++ret;
		}
		if((a[1]-a[0]<0&&a[n]-a[n-1]<0)||(a[1]-a[0]>0&&a[n]-a[n-1]>0))
			--ret;
		cout << ret << "\n";
	}
	return 0;
}
