#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	while(cin >> n >> k){
		if(!n&&!k) break;
		vi<int> left(n+1), right(n+1);
		for(int i=1; i<n+1; ++i){
			left[i] = i-1;
			right[i] = i+1;
		}
		left[1] = 0, right[n] = 0;
		for(int i=0; i<k; ++i){
			int x, y;
			cin >> x >> y;
			right[left[x]] = right[y];
			left[right[y]] = left[x];
			if(left[x]) cout << left[x] << " ";
			else cout << "* ";
			if(right[y]) cout << right[y] << "\n";
			else cout << "*\n";
		}
		cout << "-\n";
	}
	return 0;
}
