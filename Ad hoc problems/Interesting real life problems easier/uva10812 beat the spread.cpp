#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, sum, diff;
	cin >> t;
	while(t--){
		cin >> sum >> diff;
		int a, b;
		if((sum+diff)%2==0) a = (sum+diff)/2;
		else{
			cout << "impossible\n";
			continue;
		}
		b = sum-a;
		if(b<0) {
			cout << "impossible\n";
			continue;
		}
		if(a<b) swap(a, b);
		cout << a << " " << b << "\n"; 
	}
	return 0;
}
