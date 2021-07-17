#include <bits/stdc++.h>
#define vi vector
using namespace std;

int main(){
	int n, x;
	while(cin >> n){
		vi<bool> vis(n, false);
		vi<int> a(n);
		for(int &x:a) cin >> x;
		for(int i=1; i<n; ++i){
			if(abs(a[i]-a[i-1])<n)
				vis[abs(a[i]-a[i-1])] = true;
		}
		int ret = 0;
		for(int i=1; i<n; ++i)
			if(!vis[i]) ++ret;
		if(!ret) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
	return 0;
}
