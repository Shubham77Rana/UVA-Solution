#include <bits/stdc++.h>
#define vi vector

using namespace std;

int main(){
	int t, n, m, x;
	cin >> t;
	while(t--){
		cin >> n >> m;
		vi<bool> a(pow(2, n), true);
		for(int i=0; i<m; ++i){
			cin >> x;
			a[x-1] = false;
		}
		int count = 0, matches = pow(2, n-1);
		while(matches){
			for(int i=0; i<matches; ++i){
				bool first = a[2*i], second = a[2*i+1];
				if(first^second) ++count;
				a[i] = first || second;
			}
			matches/=2;
		}
		cout << count << "\n";
	}
	return 0;
}
