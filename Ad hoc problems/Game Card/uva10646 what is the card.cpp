#include <bits/stdc++.h>

using namespace std;

int cardvalue(string s){
	if(s[0] >= '2' && s[0] <= '9')
		return s[0]-'0';
	return 10;
}

int main(){
	int test;
	cin >> test;
	string s;
	for(int t=1; t<=test; ++t){
		vector<string> deck, hand;
		for(int i=0; i<27; ++i){
			cin >> s;
			deck.push_back(s);
		}
		for(int i=27; i<52; ++i){
			cin >> s;
			hand.push_back(s);
		}
		int y = 0;
		for(int i=0; i<3; ++i){
			int x = cardvalue(deck.back());
			deck.pop_back();
			y += x;
			int size = 10-x;
			while(size-- && !deck.empty())
				deck.pop_back();
		}
		--y;
		cout << "Case " << t << ": ";
		if(y < deck.size()) cout << deck[y] << "\n";
		else{
			y -= deck.size();
			cout << hand[y] << "\n";
		}
	}
}
