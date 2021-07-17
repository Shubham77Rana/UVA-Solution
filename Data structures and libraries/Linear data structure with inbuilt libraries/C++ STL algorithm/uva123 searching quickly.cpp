#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

struct node{
	string s;
	int windex;
	int sindex;
};

string uppercase(string s){
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, sx;
	set<string> words;
	while(cin >> s){
		if(s == "::") break;
		words.insert(s);
	}
	vi<vi<string>> sentence;
	vi<node> ret;
	int si = 0, wi = 0;
	while(getline(cin >> ws, s)){
		stringstream ss(s);
		sentence.pb(vi<string>());
		wi = 0;
		while(ss >> sx){
			transform(sx.begin(), sx.end(), sx.begin(), ::tolower);
			sentence.back().pb(sx);
			if(!words.count(sx))
				ret.pb({sx, wi, si});
			++wi;
		}
		++si;
	}
	
	sort(ret.begin(), ret.end(), [](node &a, node &b){
		if(a.s == b.s){
			if(a.sindex == b.sindex) return a.windex < b.windex;
			return a.sindex < b.sindex;
		} 
		return a.s < b.s;
	});
	
	for(auto &v:ret){
		for(int i=0; i<sentence[v.sindex].size(); ++i){
			if(i>0) cout << " ";
			if(i == v.windex) cout << uppercase(sentence[v.sindex][i]);
			else cout << sentence[v.sindex][i];
		}
		cout << "\n";
	}
	
	return 0;
}
