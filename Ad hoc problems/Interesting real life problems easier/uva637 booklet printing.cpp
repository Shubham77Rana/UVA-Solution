#include <bits/stdc++.h>
#define vi vector
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		int pages = ceil(n/4.0);
		int total = pages*4+1;
		cout << "Printing order for " << n << " pages:\n";
		int page = 1;
		for(int i=0; i<pages; ++i){
			cout << "Sheet " << i+1 << ", front: ";
			if(total-page <= n) cout << total-page << ", " << page << "\n";
			else cout << "Blank, " << page << "\n";
			++page;
			if(page<=n){
				cout << "Sheet " << i+1 << ", back : ";
				if(total-page <= n) cout << page << ", " << total-page <<"\n";
				else cout << page << ", Blank\n"; 
				++page; 
			}
		}
	}
	return 0;
}
