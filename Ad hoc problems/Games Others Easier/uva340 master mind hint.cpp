#include <bits/stdc++.h>

using namespace std;

int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n, x, test = 1;
	while(cin >> n){
		if(!n) break;
		vector<int> a(n);
		for(int &e:a) cin >> e; 
		cout << "Game " << test++ << ":\n";
		while(1){
			vector<int> g(n);
			int strong = 0, weak = 0;
			for(int &x:g) cin >> x;
			if(!g[0]) break;
			unordered_map<int, int> s;
			for(int &e:a) ++s[e];
			for(int i=0; i<n; ++i){
				if(a[i] == g[i]) ++strong;
				if(s.count(g[i])&&s[g[i]]){ 
					++weak;
					--s[g[i]];
				}
			}
			cout << "    (" << strong << "," << weak-strong << ")\n";
		}
	}
	return 0;
}
