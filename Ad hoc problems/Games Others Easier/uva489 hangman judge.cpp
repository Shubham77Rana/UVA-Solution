#include <bits/stdc++.h>

using namespace std;

string test_case(string s, string g){
	int guess = 0, complete = 0, size = s.size();
	vector<int> hash(26);
	for(char x:s) ++hash[x-'a'];
	for(char x:g){
		if(!hash[x-'a']) ++guess;
		else{
			complete += hash[x-'a'];
			hash[x-'a'] = 0;
		}
		if(guess > 6) return "You lose.";
		if(complete == size) return "You win.";
	}
	return "You chickened out.";
}

int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s, g;
	while(cin >> n){
		if(!~n) break;
		cin >> s;
		cin >> g;
		cout << "Round " << n << "\n" << test_case(s, g) << "\n";
	}
	return 0;
}
