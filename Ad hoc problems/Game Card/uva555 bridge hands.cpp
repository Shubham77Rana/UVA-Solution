#include <bits/stdc++.h>

using namespace std;

void filldeck(vector<pair<int, int>> &deck, string s){
	int size = s.size();
	for(int i=0; i<size; i+=2){
		pair<int, int> x;
		if(s[i] == 'C') x.first = 1;
		else if(s[i] == 'D') x.first = 2;
		else if(s[i] == 'S') x.first = 3;
		else x.first = 4;
		if(s[i+1] == 'T') x.second = 10;
		else if(s[i+1] == 'J') x.second = 11;
		else if(s[i+1] == 'Q') x.second = 12;
		else if(s[i+1] == 'K') x.second = 13;
		else if(s[i+1] == 'A') x.second = 14;
		else x.second = s[i+1]-'0';
		deck.push_back(x);
	}
}

string actual(pair<int, int> x){
	string ret = "";
	if(x.first == 1) ret.append(1, 'C');
	else if(x.first == 2) ret.append(1, 'D');
	else if(x.first == 3) ret.append(1, 'S');
	else ret.append(1, 'H');
	if(x.second == 10) ret.append(1, 'T');
	else if(x.second == 11) ret.append(1, 'J');
	else if(x.second == 12) ret.append(1, 'Q');
	else if(x.second == 13) ret.append(1, 'K');
	else if(x.second == 14) ret.append(1, 'A');
	else ret.append(1, '0'+x.second);
	return ret;
}

int main(){
	char d;
	string s;
	while(1){
		cin >> d;
		if(d == '#') break;
		vector<pair<int, int>> deck, hands[4]; 
		cin >> s;
		filldeck(deck, s);
		cin >> s;
		filldeck(deck, s);
		int index;
		if(d == 'N') index = 2;
		else if(d == 'E') index = 3;
		else if(d == 'S') index = 0;
		else index = 1;
		
		index=(index+1)%4;
		for(int i=0; i<52; ++i){
			hands[index].push_back(deck[i]);
			index = (index+1)%4;
		}
		for(int i=0; i<4; ++i){
			sort(hands[i].begin(), hands[i].end());
		}
		vector<char> suits = {'S', 'W', 'N', 'E'};
		for(int i=0; i<4; ++i){
			cout << suits[i] << ": ";
			for(int j=0; j<12; ++j){
				cout << actual(hands[i][j]) << " ";
			}
			cout << actual(hands[i][12]) << "\n";
		}
	}
	return 0;
}
