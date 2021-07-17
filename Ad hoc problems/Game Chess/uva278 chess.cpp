#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		char c;
		int rows, cols;
		cin >> c >> rows >> cols;
		if(c == 'r' || c == 'Q'){
			cout << min(rows, cols) << "\n";
		}
		else if(c == 'k'){
			cout << ceil(rows/2.0)*ceil(cols/2.0)+floor(rows/2.0)*floor(cols/2.0) << "\n";
		}
		else{
			cout << ceil(rows/2.0)*ceil(cols/2.0) << "\n";
		}
	}
	return 0;
}
