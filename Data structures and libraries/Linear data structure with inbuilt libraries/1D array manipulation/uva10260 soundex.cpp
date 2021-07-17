#include <bits/stdc++.h>
#define vi vector

using namespace std;

int main(){
	string s;
	vi<int> sound(256);
	sound['B'] = sound['F'] = sound['P'] = sound['V'] = 1;
	sound['C'] = sound['G'] = sound['J'] = sound['K'] = sound['Q'] = sound['S'] = sound['X'] = sound['Z'] = 2;
	sound['D'] = sound['T'] = 3;
	sound['L'] = 4;
	sound['M'] = sound['N'] = 5;
	sound['R'] = 6;
	while(cin >> s){
		string ret = "";
		int size = s.size();
		for(int i=0; i<size; ){
			int x = sound[s[i]];
			if(x) ret.append(1, x+'0');
			while(i<size&&sound[s[i]] == x) ++i;
		}
		cout << ret << "\n";
	}
	return 0;
}
