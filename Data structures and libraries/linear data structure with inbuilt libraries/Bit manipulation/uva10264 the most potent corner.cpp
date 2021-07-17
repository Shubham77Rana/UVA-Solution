#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

bool connected(int x, int n){
	int ret = x^n;
	return (ret&(-ret))==ret;
}

int main(){
	int n;
	while(cin >> n){
		int size = 1<<n;
		vi<int> a(size), potent(size);
		for(int &x:a) cin >> x;
		for(int i=0; i<size; ++i){
			for(int j=0; j<size; ++j){
				if(i==j) continue;
				if(connected(i, j)) potent[i]+=a[j];
			}
		}
		int mx = INT_MIN;
		for(int i=0; i<size; ++i){
			for(int j=0; j<size; ++j){
				if(i==j) continue;
				if(connected(i, j)) mx = max(mx, potent[i]+potent[j]);
			}
		}
		cout << mx << "\n";
	}
	return 0;
}
