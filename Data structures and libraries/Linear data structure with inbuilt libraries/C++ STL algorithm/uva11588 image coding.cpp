#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	int t, r, test = 0, c, ir, nir;
	cin >> t;
	char x;
	while(t--){
		cin >> r >> c >> ir >> nir;
		vi<int> count(26);
		for(int i=0; i<r; ++i){
			for(int j=0; j<c; ++j){
				cin >> x;
				++count[x-'A'];
			}
		}
		int mx = *max_element(count.begin(), count.end());
		int ret = 0, total = 0;
		for(int &e:count){
			if(e == mx) ++total;
		} 
		ret = total*mx*ir+(r*c-total*mx)*nir;
		cout << "Case " << ++test << ": " << ret << "\n"; 
	}
	return 0;
}
