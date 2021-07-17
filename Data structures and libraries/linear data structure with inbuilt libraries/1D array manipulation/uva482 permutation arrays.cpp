#include <bits/stdc++.h>
#define vi vector
#define pb push_back
using namespace std;

void test_case(){
	string s;
	getline(cin >> ws, s);
	stringstream ss(s);
	vi<int> perm;
	vi<string> a;
	int x;
	string sx;
	while(ss >> x) perm.pb(x);
	getline(cin >> ws, s);
	ss.clear(); ss.str(s);
	while(ss >> sx) a.pb(sx);
	int size = perm.size();
	vector<string> ret(size);
	for(int i=0; i<size; ++i){
		ret[perm[i]-1] = a[i];
	}
	for(auto &e:ret)
		cout << e << "\n";
}

int main(){
	int t, test = 0;
	cin >> t;
	while(t--){
		if(test++>0) cout << "\n";
		test_case();
	}
	return 0;
}
