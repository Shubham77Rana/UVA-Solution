#include <bits/stdc++.h>

using namespace std;

vector<int> dir = {1,-1,0};

void test_case(vector<string> &grid, vector<string> &touch, int n){
	vector<vector<int>> board(n, vector<int>(n));
	bool mine = false;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(grid[i][j] == '*'){
				if(touch[i][j] == 'x')
					mine = true;
				board[i][j] = -1;
				for(int &x:dir){
					for(int &y:dir){
						if(!x&&!y) continue;
						int dx = x+i, dy = y+j;
						if(dx>=0&&dx<n&&dy>=0&&dy<n&&grid[dx][dy]!='*'){
							++board[dx][dy];
						}
					}
				}
			}
		}
	}
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(mine && grid[i][j] == '*')
				cout << grid[i][j];
			else if(touch[i][j] == 'x'){
				cout << board[i][j];
			}
			else
				cout << '.';
		}
		cout << "\n";
	}
}

int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	int test = 0;
	while(t--){
		int n;
		cin >> n;
		vector<string> grid(n);
		for(auto &x:grid) cin >> x;
		vector<string> touch(n);
		for(auto &x:touch) cin >> x;
		if(test>0) cout << "\n";
		++test;
		test_case(grid, touch, n);
	}
}
