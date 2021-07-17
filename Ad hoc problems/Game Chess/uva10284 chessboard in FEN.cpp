#include <bits/stdc++.h>

using namespace std; 

void moves(vector<string> &grid, int cx, int cy, int x, int y){
	while(cx >=0 && cx<8 && cy>=0 && cy<8){
		if(grid[cx][cy] == '.' || grid[cx][cy] == '*'){
			grid[cx][cy] ='*';
		}
		else break;
		cx += x;
		cy += y;
	}
}

int test_case(vector<string> &grid){
	vector<int> dir = {+2, 1, -2, -1};
	vector<int> dir2 = {+1, -1, 0};
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if(grid[i][j] == 'p'){
				if(i+1<8&&j+1<8&&grid[i+1][j+1] == '.') grid[i+1][j+1] = '*';
				if(i+1<8&&j-1>=0&&grid[i+1][j-1] == '.') grid[i+1][j-1] = '*';
			}
			else if(grid[i][j] == 'P'){
				if(i-1>=0&&j+1<8&&grid[i-1][j+1] == '.') grid[i-1][j+1] = '*';
				if(i-1>=0&&j-1>=0&&grid[i-1][j-1] == '.') grid[i-1][j-1] = '*';
			}
			if(grid[i][j] == 'b' || grid[i][j] == 'B' || grid[i][j] == 'q' || grid[i][j] == 'Q'){
				moves(grid, i+1, j+1, 1, 1);
				moves(grid, i-1, j-1, -1, -1);
				moves(grid, i+1, j-1, 1, -1);
				moves(grid, i-1, j+1, -1, 1);
			}
			if(grid[i][j] == 'q' || grid[i][j] == 'Q' || grid[i][j] == 'r' || grid[i][j] == 'R'){
				moves(grid, i+1, j, 1, 0);
				moves(grid, i-1, j, -1, 0);
				moves(grid, i, j+1, 0, 1);
				moves(grid, i, j-1, 0, -1);
			}
			if(grid[i][j] == 'k' || grid[i][j] == 'K'){
				for(int &x:dir2){
					for(int &y:dir2){
						if(!x&&!y) continue;
						int dx = i+x, dy = j+y;
						if(dx>=0&&dx<8&&dy>=0&&dy<8&&grid[dx][dy]  == '.')
							grid[dx][dy] = '*';
					}
				}
			}
			if(grid[i][j] == 'n' || grid[i][j] == 'N'){
				for(int &x:dir){
					for(int &y:dir){
						if(abs(x) == abs(y)) continue;
						int dx = i+x, dy = j+y;
						if(dx>=0&&dx<8&&dy>=0&&dy<8&&grid[dx][dy] == '.')
							grid[dx][dy] = '*';
					}
				}
			}
		}
	}
	
	int ret = 0;
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if(grid[i][j] == '.') ++ret;
		}
	}
	return ret;
}

int main(){
	string s;
	while(cin >> s){
		vector<string> grid(8);
		int last = 0, size = s.size();
		for(int i=0; i<8; ++i){
			grid[i] = "";
			for(int j=last; j<size; ++j){
				if(s[j] == '/'){
					last = j+1;
					break;
				}
				if(s[j] >= '1' && s[j] <= '8'){
					int t = s[j]-'0';
					while(t--) grid[i].append(1, '.');
				}
				else grid[i].append(1, s[j]);
			}
		}
		cout << test_case(grid) << "\n";
	}
	return 0;
}
