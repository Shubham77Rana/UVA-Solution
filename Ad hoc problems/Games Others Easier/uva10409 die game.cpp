#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, temp;
	while(cin >> n){
		if(!n) break;
		string s;
		vector<int> face = {1, 2, 3};
		for(int i=0; i<n; ++i){
			cin >> s;
			if(s[0] == 'n'){
				swap(face[0], face[1]);
				face[0] = 7-face[0];
			}	
			else if(s[0] == 's'){
				swap(face[0], face[1]);
				face[1] = 7-face[1];
			}
			else if(s[0] == 'e'){
				swap(face[0], face[2]);
				face[2] = 7-face[2];
			}
			else{
				swap(face[0], face[2]);
				face[0] = 7-face[0];
			}
			//cout << face[0] << " " << face[1] << " " << face[2] << "\n";
		}
		cout << face[0] << "\n";
	}
	return 0;
}
