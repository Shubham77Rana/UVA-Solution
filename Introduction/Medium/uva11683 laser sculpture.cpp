#include <bits/stdc++.h>

using namespace std;

int main(){
	int h, n, x;
	while(1){
		cin >> h >> n;
		if(!h) break;
		int sum = 0, sub = 0, last = 0;
		for(int i=0; i<n; ++i){
			cin >> x, x = h-x;
			sum += x;
			sub += min(last, x);
			last = x;
		}
		cout << sum-sub << "\n";
	}
	return 0;
}
