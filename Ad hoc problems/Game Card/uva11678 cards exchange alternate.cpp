#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, x;
	while(1){
		cin >> n >> m;
		if(!n&&!m) break;
		vector<int> a, b;
		int last = 0;
		for(int i=0; i<n; ++i){
			cin >> x;
			if(x != last) a.push_back(x);
			last = x;
		}
		last = 0;
		for(int i=0; i<m; ++i){
			cin >> x;
			if(x != last) b.push_back(x);
			last = x;
		}
		n = a.size(), m = b.size();
		int count = 0;
		int ai = 0, bi = 0;
		while(ai<n && bi<m){
			if(a[ai] == b[bi]) ++count, ++ai, ++bi;
			else if(a[ai] < b[bi]) ++ai;
			else ++bi;
		}
		cout << min(n-count, m-count) << "\n";
	}
	return 0;
}
