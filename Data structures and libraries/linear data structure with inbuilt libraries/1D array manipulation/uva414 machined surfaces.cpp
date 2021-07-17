#include <bits/stdc++.h>
#define vi vector
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		string s;
		vi<int> total(n);
		int mx = 0;
		for(int i=0; i<n; ++i){
			getline(cin >> ws, s);
			int first = -1, second = s.size();
			int size = second;
			for(int j=0; j<size; ++j){
				if(s[j] != 'X') break;
				else first = j;
			}
			for(int j=size-1; j>=0; --j){
				if(s[j] != 'X') break;
				else second = j;
			}		
			if(second<first) total[i] = size;
 			else total[i] = first+1+size-second;
			mx = max(mx, total[i]);
		}
		int ret = 0;
		for(int &x:total){
			ret += mx-x;
		}
		cout << ret << "\n";
	}
	return 0;
}
