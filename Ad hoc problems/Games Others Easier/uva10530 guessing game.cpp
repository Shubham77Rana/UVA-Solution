#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	int mn=0, mx=11;
	bool lie = false;
	while(1){
		cin >> n;
		if(!n) break;
		//cout << mn+1 << " " << mx-1 << "\n";
		getline(cin >> ws, s);
		if(s[0] == 'r'){
			if(n >= mx || n <= mn) cout << "Stan is dishonest\n";
			else cout << "Stan may be honest\n";
			mn = 0, mx = 11, lie = false;
		}
		else if(s[4] == 'l') 
			mn = max(mn, n);
		else if(s[4] == 'h') 
			mx = min(mx, n);
	}
	return 0;
}
