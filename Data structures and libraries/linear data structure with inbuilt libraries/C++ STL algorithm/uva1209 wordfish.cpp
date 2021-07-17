#include <bits/stdc++.h>
#define pb push_back
#define vi vector

using namespace std;

int main(){
	string s;
	while(cin >> s){
		string ps = s;
		vi<string> list;
		for(int i=0; i<10; ++i){
			prev_permutation(ps.begin(), ps.end());
			list.pb(ps);
		}
		reverse(list.begin(), list.end());
		list.pb(s);
		for(int i=0; i<10; ++i){
			next_permutation(s.begin(), s.end());
			list.pb(s);
		}
		int mx = 0;
		string rets;
		for(auto &x:list){
			int mn = INT_MAX;
			for(int i=0; i<x.size()-1; ++i)
				mn = min(mn, abs(x[i]-x[i+1]));
			if(mx < mn){
				rets = x;
				mx = mn;
			}
		}
		cout << rets << mx << "\n";
	}
	return 0;
}
