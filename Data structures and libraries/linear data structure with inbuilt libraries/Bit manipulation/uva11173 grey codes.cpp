#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, x;
	cin >> t;
	while(t--){
		cin >> n >> x;
		cout << (x^(x>>1)) << "\n";
	}
	return 0;	
}
