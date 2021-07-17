#include <bits/stdc++.h>
#define vi vector
#define pb push_back
using namespace std;

int main(){
	int t, n, e, test=1;
	cin >> t;
	while(t--){
		set<int> a[3];
		vi<int> s[3];
		for(int i=0; i<3; ++i){
			cin >> n;
			for(int j=0; j<n; ++j){
				cin >> e;
				a[i].insert(e);
			}
		}
		for(int i=0; i<3; ++i){
			for(auto &x:a[i]){
				int count = 0;
				for(int j=0; j<3; ++j){
					if(i == j) continue;
					if(a[j].count(x)) ++count;
				}
				if(count == 0) s[i].pb(x);
			}
		}
		int index = 0;
		for(int i=1; i<3; ++i){
			if(s[i].size()>s[index].size())
				index = i;
		}
		cout << "Case #" << test++ << ":\n";
		for(int i=0; i<3; ++i){
			if(s[index].size() != s[i].size()) continue;
			cout << i+1 << " ";
			if(s[i].size()) cout << s[i].size() << " ";
			else cout << "0";
			sort(s[i].begin(), s[i].end());
			int temp = 0;
			for(int &x:s[i]){
				if(temp++>0) cout << " ";
				cout << x;
			}
			cout << "\n";
		}
	}
	return 0;
}
