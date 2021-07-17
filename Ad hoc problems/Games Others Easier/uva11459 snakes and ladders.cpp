#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, p, die, ls, start, end, x;
	cin >> t;
	while(t--){
		cin >> p >> ls >> die;
		unordered_map<int, int> lad;
		for(int i=0; i<ls; ++i){
			cin >> start >> end;
			lad[start] = end;
		}
		vector<int> rolls(die);
		for(int &e:rolls) cin >> e;
		vector<int> pos(p, 1);
		for(int i=0; i<die; ++i){
			int player = i%p;
			x = rolls[i];
			x += pos[player];
			if(lad.count(x)) x = lad[x];
			if(x > 100) x = 100;
			pos[player] = x;
			if(x == 100) break;
		}
		for(int i=0; i<p; ++i)
			cout << "Position of player " << i+1 << " is " << pos[i] << ".\n";
	}
	return 0;
}
