#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		vi<int> index;
		for(int i=0; i<32; ++i){
			if(n>>i&1) index.pb(i);
		}
		int ret1 = 0, ret2 = 0;
		for(int i=0; i<index.size(); ++i){
			if(i&1) ret2|=(1<<index[i]);
			else ret1|=(1<<index[i]);
		}
		cout << ret1 << " " << ret2 << "\n";
	}
	return 0;
}
