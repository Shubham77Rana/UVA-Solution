#include <bits/stdc++.h>

using namespace std;

bool ispalin(string &s, int low, int high){
	while(low<high){
		if(s[low++]  != s[high--]) 
			return false;
	}
	return true;
}

int test_case(string &s){
	int size = s.size(), ret = 0;
	unordered_set<string> sett;
	for(int i=0; i<size; ++i){
		for(int j=i; j<size; ++j){
			string str = s.substr(i, j-i+1);
			if(!sett.count(str) && ispalin(s, i, j)){
				++ret;
				sett.insert(str);
			}
		}
	}
	
	return ret;
}

int main(){
	string s;
	while(cin >> s){
		cout << "The string '" << s << "' contains " << test_case(s) << " palindromes.\n"; 
	}
	return 0;
}
