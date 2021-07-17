#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

void backtrack(int si, int ti, string &s, string &t, stack<char> &st, string &ret){
	if(si == s.size() && ti == t.size()){
		cout << ret[0];
		for(int i=1; i<ret.size(); ++i) cout << " " << ret[i];
		cout << "\n";
		return;
	}
	if(si<s.size()){
		ret.append(1, 'i');
		st.push(s[si]);
		backtrack(si+1, ti, s, t, st, ret);
		ret.pop_back();
		st.pop();
	}
	if(!st.empty() && ti<t.size() && st.top() == t[ti]){
		ret.append(1, 'o');
		char x = st.top(); st.pop();
		backtrack(si, ti+1, s, t, st, ret);
		ret.pop_back();
		st.push(x);
	}
}

int main(){
	string s, t;
	while(cin >> s){
		cin >> t;
		stack<char> st;
		string ret = "";
		cout << "[\n";
		backtrack(0, 0, s, t, st, ret);
		cout << "]\n";
	}
	return 0;
}
