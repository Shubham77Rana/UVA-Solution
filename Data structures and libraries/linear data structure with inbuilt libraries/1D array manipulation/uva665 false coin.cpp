#include <bits/stdc++.h>
#define vi vector

using namespace std;

int main(){
	int t, test = 0;
	cin >> t;
	while(t--){
		int n, k, m;
		char c;
		cin >> n >> k;
		vi<int> w(n+1);
		set<int> nonans;
		for(int i=0; i<k; ++i){
			cin >> m;
			vi<int> a(2*m);
			for(int &x:a) cin >> x;
			cin >> c; 
			if(c == '<'){
				for(int i=0; i<m; ++i) --w[a[i]];
				for(int i=m; i<2*m; ++i) ++w[a[i]];
			}
			else if(c == '>'){
				for(int i=0; i<m; ++i) ++w[a[i]];
				for(int i=m; i<2*m; ++i) --w[a[i]];
			}
			else{
				for(int i=0; i<2*m; ++i)
					nonans.insert(a[i]);
			}
		}
		int mx = 0, mxf = 0;
		for(int i=1; i<n+1; ++i){
			if(!nonans.count(i)) mx = max(mx, abs(w[i]));
		}
		int ans = 0;
		for(int i=1; i<n+1; ++i){
			if(!nonans.count(i) && abs(w[i]) == mx){
				++mxf;
				ans = i;
			}
		}
		if(test++>0) cout << "\n";
		if(mxf == 1) cout << ans << "\n";
		else cout << "0\n";
	}
	return 0;
}
