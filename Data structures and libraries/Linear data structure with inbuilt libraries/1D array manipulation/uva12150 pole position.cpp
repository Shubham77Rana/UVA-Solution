#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

void test_case(vi<pair<int, int>> &pole, int n){
	vi<int> ret(n, 0);
	for(int i=0; i<n; ++i){
		int index = i+pole[i].second;
		if(index>=0 && index<n && !ret[index]){
			ret[index] = pole[i].first;
		}
		else{
			cout << -1 << "\n";
			return;
		}
	}
	int test = 0;
	for(int &x:ret){ 
		if(test++>0) cout << " ";
		cout << x;
	}
	cout << "\n";
}

int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin >> n){
		if(!n) break;
		vi<pair<int, int>> pole(n);
		for(auto &x:pole) cin >> x.first >> x.second;
		test_case(pole, n);
	}
	return 0;
}
