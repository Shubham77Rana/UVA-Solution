#include <bits/stdc++.h>

using namespace std;

int main(){
	int rows, cols;
	while(cin >> rows >> cols){
		if(!rows&&!cols) break;
		if(rows == 0 || cols == 0){
			cout << 0;
		}
		else if(rows == 1){
			cout << cols;
		}
		else if(cols == 1){
			cout << rows;
		}
		else if(min(rows, cols) == 2){
			int col = max(rows, cols);
			cout << (col%2?col+1:((col/2)%2?col+2:col));
		}
		else{
			cout << max(4.0, ceil(rows/2.0)*ceil(cols/2.0)+floor(rows/2.0)*floor(cols/2.0));
		}
		cout << " knights may be placed on a " << rows << " row " << cols << " column board.\n";
	}
	return 0;
}
