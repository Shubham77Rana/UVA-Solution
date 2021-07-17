#include <bits/stdc++.h>
#define vi vector
using namespace std;

int main(){
	int n;
	string card, word;
	while(cin >> n){
		if(!n) break;
		vi<string> a(n, "");
		int pos = -1;
		for(int i=0; i<n; ++i){
			cin >> card >> word;
			int size = 0;
			while(size<word.size()){
				++pos;
				pos%=n;
				if(a[pos]=="") ++size;
			}
			a[pos] = card;
		}
		for(int i=0; i<n-1; ++i)
			cout << a[i] << " ";
		cout << a[n-1];
		cout << "\n";
	}
	return 0;
}
