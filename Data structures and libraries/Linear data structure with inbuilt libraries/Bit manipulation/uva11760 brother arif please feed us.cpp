#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	int r, c, n, x, y, t = 0;
	while(cin >> r >> c >> n){
		if(!r&&!c&&!n) break;
		vi<bool> row(r), col(c);
		for(int i=0; i<n; ++i){
			cin >> x >> y;
			row[x] = true, col[y] = true;
		}
		vi<int> dir = {0, 1, -1};
		bool flag = true;
		cin >> x >> y;
		if(!row[x]&&!col[y]) flag = false;
		for(int dx:dir){
			for(int dy:dir){
				if(abs(dx) == abs(dy)) continue;
				if(x+dx>=0&&x+dx<r&&y+dy>=0&&y+dy<c&&!row[x+dx]&&!col[y+dy]) flag = false;
			}
		}
		cout << "Case " << ++t << ": ";
		if(flag) cout << "Party time! Let's find a restaurant!\n";
		else cout << "Escaped again! More 2D grid problems!\n";
	}
	return 0;
}
