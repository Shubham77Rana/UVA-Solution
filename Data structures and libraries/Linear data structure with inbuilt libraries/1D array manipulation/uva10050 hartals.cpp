#include <bits/stdc++.h>
#define vi vector
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, p;
		cin >> n;
		vi<bool> vis(n+1, false);
		cin >> p;
		vi<int> part(p);
		for(int &x:part) cin >> x;
		for(int i=1; i<=n; ++i){
			for(int &x:part){
				if(i%7==6 || i%7==0) break;
				if(i%x == 0){
					vis[i] = true;
					break;
				}
			}
		}
		int ret = 0;
		for(int i=1; i<=n; ++i)
			if(vis[i]) ++ret;
		cout << ret << "\n";
	}
	return 0;
}
