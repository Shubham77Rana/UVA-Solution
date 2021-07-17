#include <bits/stdc++.h>

using namespace std;

int main(){
	int qx, qy, x, y;
	while(cin >> qx >> qy >> x >> y){
		if(!qx) break;
		if(qx == x && qy == y) cout << "0\n";
		else if(abs(qx-x) == abs(qy-y)) cout << "1\n";
		else if(qx == x || qy == y) cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}
