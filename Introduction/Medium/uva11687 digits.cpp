#include <bits/stdc++.h>

using namespace std;

int digits(int n){
	int ret = 0;
	while(n){
		++ret;
		n/=10;
	}
	return ret;
}

int main(){
	string s;
	while(1){
		cin >> s;
		if(s[0] == 'E') break;
		if(s == "1"){
			cout << "1\n";
			continue;
		}
		int current = s.size(), count = 1;
		while(current != 1){
			current = digits(current);
			++count;
		}
		cout << count+1 << "\n";
	}
	return 0;
}
