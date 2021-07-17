#include <bits/stdc++.h>
#define vi vector
using namespace std;

int main(){
	int t;
	cin >> t;
	string s1, s2, s3;
	while(t--){
		unordered_map<char, int> light, heavy;
		set<char> nonans;
		for(int i=0; i<3; ++i){
			cin >> s1 >> s2 >> s3;
			if(s3[0] == 'e'){
				for(char &x:s1) light.erase(x), heavy.erase(x), nonans.insert(x);
				for(char &x:s2) light.erase(x), heavy.erase(x), nonans.insert(x);
			}
			else if(s3[0] == 'u'){
				for(char &x:s1){
					if(!nonans.count(x)) ++heavy[x];
				}
				for(char &x:s2){
					if(!nonans.count(x)) ++light[x];
				} 
			}
			else if(s3[0] == 'd'){
				for(char &x:s1){
					if(!nonans.count(x)) ++light[x];
				}
				for(char &x:s2){
					if(!nonans.count(x)) ++heavy[x];
				}
			}
		}
		int hmx=0, lmx=0;
		char hmxc, lmxc;
		for(auto &x:heavy){
			if(hmx<x.second) hmx = x.second, hmxc = x.first;
		}
		for(auto &x:light){
			if(lmx<x.second) lmx = x.second, lmxc = x.first;
		}
		if(hmx>lmx) cout << hmxc;
		else cout << lmxc;
		cout << " is the counterfeit coin and it is ";
		if(hmx>lmx) cout << "heavy.\n";
		else cout << "light.\n";
	}
	return 0;
}
