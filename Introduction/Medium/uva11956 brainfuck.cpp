#include <bits/stdc++.h>

using namespace std;

string hexa(int n){
	if(n == 0) return "00";
	string ret = "";
	while(n){
		if(n%16 < 10) ret.append(1, char(n%16+'0'));
		else ret.append(1, char(n%16-10+'A'));
		n/=16;
	}
	if(ret.size() == 1) ret.append(1, '0');
	reverse(ret.begin(), ret.end());
	return ret;
}

int main(){
	int test;
	cin >> test;
	string s;
	for(int t=0; t<test; ++t){
		cin >> s;
		vector<int> a(100);
		int size = s.size();
		int pointer = 0;
		cout << "Case " << t+1 << ": ";
		for(int i=0; i<size; ++i){
			switch(s[i]){
				case '>': pointer = (pointer + 1)%100; break;
				case '<': pointer = (pointer - 1 + 100)%100; break;
				case '+': a[pointer] = (a[pointer]+1)%256; break;
				case '-': a[pointer] = (a[pointer]-1+256)%256; break;
				case '.': break;
			}
		}
		for(int i=0; i<99; ++i){
			cout << hexa(a[i]) << " ";
		}
		cout << hexa(a[99]) << "\n";
	}
	return 0;
}
