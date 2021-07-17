#include <bits/stdc++.h>
#define vi vector
#define pb push_back
using  namespace std;

void test_case(int n){
	vi<int> a(n);
	int sum = 0;
	for(int &x:a){
		cin >> x;
		sum += x;
	}
	int mean = sum/n;
	int ret = 0;
	for(int &x:a){
		ret += abs(mean-x);
	}
	cout << "The minimum number of moves is " << ret/2 << ".\n";
}

int main(){
	int n, t = 1;
	while(cin >> n){
		if(!n) break;
		cout << "Set #" << t++ << "\n";
		test_case(n);
		cout <<"\n";
	}
	return 0;
}
