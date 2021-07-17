#include <bits/stdc++.h>

using namespace std;

int test_case(string &ns, string &s, vector<int> &hashs, int strong, int weak){
	if(ns.size() == s.size()){
		int ms = 0, mw = 0;
		vector<int> hashns(10);
		for(int i=0; s[i]; ++i){
			if(s[i] == ns[i]) ++ms;
			++hashns[ns[i]-'0'];
		}
		for(int i=1; i<10; ++i){
			mw += min(hashs[i], hashns[i]);
		}
		mw = mw - ms;
		if(ms == strong && mw == weak) return 1;
		return 0;
	}
	int count = 0;
	for(int i=1; i<10; ++i){
		ns.push_back(i+'0');
		count += test_case(ns, s, hashs, strong, weak);
		ns.pop_back();
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	string s;
	int strong, weak;
	while(n--){
		cin >> s >> strong >> weak;
		vector<int> hashs(10);
		for(int i=0; s[i]; ++i){
			++hashs[s[i]-'0'];
		}
		string ns = "";
		int ret = test_case(ns, s, hashs, strong, weak);
		cout << ret << "\n";
	}
	return 0;
}
