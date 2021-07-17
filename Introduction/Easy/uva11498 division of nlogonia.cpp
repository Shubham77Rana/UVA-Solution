#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	while(cin >> k){
		if(!k) break;
		int dx, dy, x, y;
		cin >> dx >> dy;
		while(k--){
			cin >> x >> y;
			x=x-dx;
			y=y-dy;
			if(!x || !y) cout << "divisa\n";
			else if(x>0&&y>0) cout << "NE\n";
			else if(x>0) cout << "SE\n";
			else if(y>0) cout << "NO\n";
			else cout << "SO\n";
		}
	}
	return 0;
}
