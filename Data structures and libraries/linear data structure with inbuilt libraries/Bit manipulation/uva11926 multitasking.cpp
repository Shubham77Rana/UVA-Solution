#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

const int MX = 1e6;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, l, r, inter;
	while(cin >> n >> m){
		if(!n&&!m) break;
		vi<bool> vis(MX);
		bool flag = false;
		for(int i=0; i<n; ++i){
			cin >> l >> r;
			for(int j=l; j<r; ++j){
				if(vis[j]) flag = true;
				vis[j] = true;
			}
		}
		for(int i=0; i<m; ++i){
			cin >> l >> r >> inter;
			int sl = l, sr = r;
			while(sl<=MX){
				for(int j=sl; j<min(sr, MX); ++j){
					if(vis[j]) flag = true;
					vis[j] = true;
				}
				sl += inter;
				sr += inter;
			}
		}
		if(flag) cout << "CONFLICT\n";
		else cout << "NO CONFLICT\n";
	}
	return 0;
}
