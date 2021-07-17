#include <bits/stdc++.h>

using namespace std;

int face(string s){
	if(s[1] == 'A') return 4;
	if(s[1] == 'J') return 1; 
	if(s[1] == 'Q') return 2;
	if(s[1] == 'K') return 3;
	return 0;
}

bool play(vector<string> &game, vector<string> &p, vector<string> &op, int &last, bool &lastface){
	int t = last;
	cout << "To game: ";
	last = 0;
	while(t-- && !p.empty()){
		cout << p.back() << " ";
		last += face(p.back());
		game.push_back(p.back());
		p.pop_back();
	}
	if(t) false;
	if(last) lastface = true; 
	cout << "\n";
	
	if(!last && lastface){
		int size = op.size();
		//reverse(game.begin(), game.end());
		for(int i=0; i<size; ++i){
			game.push_back(op[i]);
		}
		op.clear();
		size = game.size();
		for(int i=0; i<size; ++i){
			op.push_back(game[i]);
		}
		game.clear();
		lastface = false;
		/*cout << "Player New: ";
		for(int i=size-1; i>=0; --i)
			cout << op[i] << " ";
		cout << "\n";*/
	}
	if(!last) last = 1;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(1){
		cin >> s;
		if(s == "#") break;
		vector<string> p1, p2;
		p2.push_back(s);
		for(int i=1; i<52; ++i){
			cin >> s;
			if(i%2) p1.push_back(s);
			else p2.push_back(s);
		} 
		for(int i=25; i>=0; --i)
			cout << p2[i] << " ";
		cout << "\n";
		for(int i=25; i>=0; --i)
			cout << p1[i] << " ";
		cout << "\n";
		int turn = 2;
		vector<string> game;
		int last = 1;
		bool lastface = false;
		while(1){
			if(turn == 1){ 
				if(p1.empty()) break;
				cout << "Player1: ";
				if(!play(game, p1, p2, last, lastface))
					break;
			}
			else{
				if(p2.empty()) break;
				cout << "Player2: ";
				if(!play(game, p2, p1, last, lastface))
					break;
			}
			turn = (turn%2)+1;
		}
		
		if(!p1.empty()) cout << "1 " << p1.size() << "\n";
		else cout << "2 " << p2.size() << "\n";
	}
	return 0;
}
