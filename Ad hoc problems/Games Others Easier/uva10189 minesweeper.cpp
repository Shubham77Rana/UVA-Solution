#include <bits/stdc++.h>

using namespace std;

vector<int> dir = {-1, +1, 0};

void test_case(vector<string> &b, int n, int m){
	vector<vector<int>> mines(n, vector<int>(m));
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(b[i][j] == '*'){
				mines[i][j] = -1;
				continue;
			}
			for(int &x:dir){
				for(int &y:dir){
					int dx = i+x, dy = j+y;
					if(dx>=0&&dx<n&&dy>=0&&dy<m&&b[dx][dy] == '*')
						++mines[i][j];
				}
			}
		}
	}
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(~mines[i][j]) cout << mines[i][j];
			else cout << "*";
		}
		cout << "\n";
	} 
}

int main(){
	int n, m, test = 1;
	while(cin >> n >> m){
		if(!n&&!m) break;
		vector<string> b(n);
		for(auto &x:b) cin >> x;
		if(test>1) cout << "\n";
		cout << "Field #" << test++ << ":\n";
		test_case(b, n, m);
	}
	return 0;
}
