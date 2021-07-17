#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, b;
	while(cin >> n >> b){
		if(!n&&!b) break;
		vector<int> bag(b);
		unordered_set<int> s;
		for(int &x:bag){ 
			cin >> x;
			s.insert(x);
		}
		bool found = true;
		for(int i=0; i<=n; ++i){
			bool flag = false;
			for(int &x:bag){
				int target = x-i;
				if(s.count(target)){
					flag = true; 
					break;
				}
			}
			if(!flag){
				found = false;
				break;
			}
		}
		cout << (found?"Y":"N") << "\n";
	}
	return 0;
}
