#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	int test = 0;
	while(cin >> s){
		if(s[0] == 'e') break;
		set<char> sets, tops;
		for(char &x:s){
			sets.insert(x);
			auto pos = lower_bound(tops.begin(), tops.end(), x);
			if(pos!=tops.end()){
				tops.erase(pos);
				tops.insert(x);
			}
			else tops.insert(x);
		}
		cout << "Case " << ++test << ": " << min(tops.size(), sets.size()) << "\n";
	}
	return 0;
}