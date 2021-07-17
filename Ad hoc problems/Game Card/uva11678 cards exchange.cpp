#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, x;
	while(1){
		cin >> n >> m;
		if(!n&&!m) break;
		vector<int> a, b;
		set<int> as, bs;
		for(int i=0; i<n; ++i){
			cin >> x;
			if(!as.count(x))
				a.push_back(x), as.insert(x);
		}
		for(int i=0; i<m; ++i){
			cin >> x;
			if(!bs.count(x))
				b.push_back(x), bs.insert(x);
		}
		for(int &x:a){
			if(bs.count(x)) bs.erase(x);
		}
		for(int &x:b){
			if(as.count(x)) as.erase(x);
		}
		cout << min(as.size(), bs.size()) << "\n";
	}
	return 0;
}
