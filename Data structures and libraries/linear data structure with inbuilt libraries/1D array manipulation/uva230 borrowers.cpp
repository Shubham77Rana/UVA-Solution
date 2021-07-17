#include <bits/stdc++.h>
#define vector vi

using namespace std;

pair<string, string> process(string &s){
	string book = "", author = "";
	int size = s.size();
	for(int i=0; i<size; ++i){
		
	}
	
}

int main(){
	string command, s;
	vi<pair<string, string>> books;
	vi<bool> shelve;
	while(getline(cin >> ws, s)){
		if(s == "END") break;
		books.push_back(process(s));
		shelve.push_back(true);
	} 
	while(1){
		cin >> command;
		if(command == "END") break;
		getline(cin >> ws, s);
		if(s == "END") break;
		if(s == "")
	}
	return 0;
}
