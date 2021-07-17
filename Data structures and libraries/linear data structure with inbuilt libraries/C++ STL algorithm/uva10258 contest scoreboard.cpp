#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	int test;
	cin >> test;
	string s;
	getline(cin, s);
	getline(cin, s);
	for(int t=0; t<test; ++t){
		if(t > 0) cout << "\n";
		vi<vi<int>> incorrect(101, vi<int>(10));
		vi<vi<bool>> solved(101, vi<bool>(10));
		int con, pro, time;
		char c;
		vi<bool> seen(101);
		vi<vi<int>> ret(101, vi<int>(2));
		while(getline(cin, s) && s.size()>0){
			stringstream ss(s);
			ss >> con >> pro >> time >> c;
			seen[con] = true;
			if(!solved[con][pro] && c == 'C'){
				++ret[con][0];
				ret[con][1]+=time;
				if(incorrect[con][pro]) ret[con][1]+=20*incorrect[con][pro];
				solved[con][pro] = true;
			}
			if(c == 'I') ++incorrect[con][pro];
		}
		vi<vi<int>> ans;
		for(int i=1; i<101; ++i){
			if(seen[i]) ans.push_back({i, ret[i][0], ret[i][1]});
		}
		sort(ans.begin(), ans.end(), [](vi<int> &a, vi<int> &b){
			if(a[1] == b[1]){
				if(a[2] == b[2]) return a[0] < b[0];
				return a[2] < b[2];
			}
			return a[1] > b[1];
		});
		
		for(auto &x:ans){
			cout << x[0] << " " << x[1] << " " << x[2] << "\n"; 
		}
	}
	return 0;
}
