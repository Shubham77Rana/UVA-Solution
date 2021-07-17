#include <bits/stdc++.h>
#define vi vector

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int test=0; test<t; ++test){
		cout << "Case " << test+1 << ": ";
		int n;
		cin >> n;
		vi<int> a(n), b(n);
		for(int &x:a) cin >> x;
		for(int &x:b) cin >> x;
		int count = 2*n, start = 0, current = 0, petrol = 0;
		bool flag = false;
		while(count--){
			petrol += a[current]-b[current];
			if(petrol>=0 && (current == start-1 || (start == 0 && current == n-1))){
				flag = true;
				break;
			}
			if(petrol<0){
				petrol = 0;
				start = (current+1)%n;
			}
			current = (current+1)%n;
			
			
		}
		if(flag) cout << "Possible from station " << start+1 << "\n";
		else cout << "Not possible\n";
	}
}
