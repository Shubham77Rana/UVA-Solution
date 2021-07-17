#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dir = {{1, 0},{-1,0},{0,1},{0,-1}};

bool validstraight(char x, char k){
	if(k > 90 && x > 90) return false;
	else if(k < 90 && x < 90) return false;
	if(x == 'r' || x == 'R' || x == 'q' || x == 'Q') return true;
	return false;
}

bool validdiag(char x, char k, int d1, int d2){
	if(k > 90 && x > 90) return false;
	else if(k < 90 && x < 90) return false;
	if(x == 'p'&&abs(d1)==1&&abs(d2)==1){
		if(d1<0) return true;
	}
	if(x == 'P'&&abs(d1)==1&&abs(d2)==1){
		if(d1>0) return true;
	}
	if(x == 'b' || x == 'B' || x == 'q' || x == 'Q') return true;
	return false; 
}

bool found(vector<string> &grid, int sx, int sy, int cx, int cy, int xi, int yi){
	while(cx<8 && cx>=0 && cy<8 && cy>=0){
		if(validstraight(grid[cx][cy], grid[sx][sy])){
			//cout << "found Straight "<< grid[cx][cy] << " " << cx << " " << cy << "\n";
			return true;
		}
		if(grid[cx][cy] != '.') return false;
		cx += xi;
		cy += yi;
	}
	return false;
}

bool founddiag(vector<string> &grid, int sx, int sy, int cx, int cy, int xi, int yi){
	while(cx<8 && cx>=0 && cy<8 && cy>=0){
		if(validdiag(grid[cx][cy], grid[sx][sy], cx-sx, cy-sy)){
			//cout << "found Diag "<< grid[cx][cy] << " " << cx << " " << cy << "\n";
			return true;
		}
		if(grid[cx][cy] != '.') return false;
		cx += xi;
		cy += yi;
	}
	return false;
}

void print(char x){
	if(x == 'K')
		cout << "white king is in check.\n";
	else
		cout << "black king is in check.\n";
}

bool test_case(vector<string> &grid, int test){
	vector<pair<int, int>> kings;
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if(grid[i][j] == 'k' || grid[i][j] == 'K')
				kings.push_back({i, j});
		}
	}
	if(kings.size() < 2) return false; 
	cout << "Game #" << test << ": ";
	for(auto &x:kings){
		//cout << x.first << " " << x.second << " " << grid[x.first][x.second] << "\n";
		if(found(grid, x.first, x.second, x.first+1, x.second, 1, 0)){
			print(grid[x.first][x.second]);
			return true;
		}
		if(found(grid, x.first, x.second, x.first-1, x.second, -1, 0)){
			print(grid[x.first][x.second]);
			return true;
		}
		if(found(grid, x.first, x.second, x.first, x.second+1, 0, 1)){
			print(grid[x.first][x.second]);
			return true;
		}
		if(found(grid, x.first, x.second, x.first, x.second-1, 0, -1)){
			print(grid[x.first][x.second]);
			return true;
		}
		if(founddiag(grid, x.first, x.second, x.first+1, x.second+1, 1, 1)){
			print(grid[x.first][x.second]);
			return true;
		}
		if(founddiag(grid, x.first, x.second, x.first-1, x.second-1, -1, -1)){
			print(grid[x.first][x.second]);
			return true;
		}
		if(founddiag(grid, x.first, x.second, x.first+1, x.second-1, 1, -1)){
			print(grid[x.first][x.second]);
			return true;
		}
		if(founddiag(grid, x.first, x.second, x.first-1, x.second+1, -1, 1)){
			print(grid[x.first][x.second]);
			return true;
		}
		vector<int> dir = {+2, -1, -2, +1};
		for(int xx:dir){
			for(int y:dir){
				if(abs(xx) == abs(y)) continue;
				int dx = x.first + xx, dy = x.second + y;
				if(dx>=0&&dx<8&&dy>=0&&dy<8){
					if(grid[x.first][x.second]=='k'&&grid[dx][dy]=='N'){
						print('k');
						return true;
					}
					if(grid[x.first][x.second]=='K'&&grid[dx][dy]=='n'){
						print('K');
						return true;
					}
				}
			}
		}
	}
	cout << "no king is in check.\n";
	return true;
}

int main(){
	int test = 1;
	while(1){
		vector<string> grid(8);
		for(int i=0; i<8; ++i)
			cin >> grid[i];
		if(!test_case(grid, test)) 
			break;
		++test;
	}
}
