#include <bits/stdc++.h>

using namespace std;

int main(){
	int test;
	cin >> test;
	while(test--){
		int q, n;
		cin >> q;
		cin >> n;
		while(q--){
			int x, y, x1, y1;
			cin >> x >> y >> x1 >> y1;
			if(x==x1 && y == y1) cout << "0\n";
			else if(x+y == x1+y1 || x-y == x1-y1) cout << "1\n";
			else if((x+y-x1-y1)%2 == 0) cout << "2\n";
			else cout << "no move\n";
		}
	}
	return 0;
}
