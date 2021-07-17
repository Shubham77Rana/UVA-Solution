#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(cin >> s){
		if(s == "#") break;
		int index = s.size()-2;
		for( ; ~index; --index){
			if(s[index] < s[index+1]) break;
		}
		if(!~index){
			cout << "No Successor\n";
			continue;
		}
		string ret = "";
		for(int i=0; i<index; ++i) ret.pb(s[i]);
		int last = s.size()-1;
		while(s[last] <= s[index]) --last;
		ret.pb(s[last]);
		string rets = "";
		for(int i=s.size()-1; i>last; --i) rets.pb(s[i]);
		for(int i=index; i<last; ++i) rets.pb(s[i]);
		sort(rets.begin(), rets.end());
		cout << ret+rets << "\n";
	}
	return 0;
}
