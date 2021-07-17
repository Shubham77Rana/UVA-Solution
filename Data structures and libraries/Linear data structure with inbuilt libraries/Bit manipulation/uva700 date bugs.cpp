#include <bits/stdc++.h>
#define vi vector

const int MX = 10000;

using namespace std;

int main(){
	int n, t = 0;
	while(cin >> n){
		if(!n) break;
		vi<vi<int>> a(n, vi<int>(3));
		for(auto &x:a) cin >> x[0] >> x[1] >> x[2];
		vi<int> count(MX);
		int mx = INT_MIN;
		for(auto &x:a){
			for(int year=x[0]; year<MX; year+=(x[2]-x[1]))
				++count[year];
			mx = max(mx, x[1]);
		}
		bool flag = true;
		cout << "Case #" << ++t << ":\n";
		for(int year=mx; year<MX; ++year){
			if(count[year] == n){
				cout << "The actual year is " << year << ".\n"; 
				flag = false;
				break;
			}
		}
		if(flag) cout << "Unknown bugs detected.\n";
		cout << "\n";
	}
	return 0;
}
