#include <bits/stdc++.h>
#define vi vector
#define pb push_back
#define ll long long
using namespace std;

void print(ll r, ll c){
	cout << "Line = " << r << ", column = " << c << ".\n";
}

int main(){
	int n;
	ll x;
	while(cin >> n >> x){
		if(!n&&!x) break;
		ll root = ceil(sqrt(x));
		if(!(root%2)) ++root;
		ll offset = (n-root)/2;
		if(root*root == x){
			print(root+offset, root+offset);
			continue;
		}
		int pos = (4*root-4)-(root*root-x);
		if(pos<root){
			print(root+offset, root+offset-pos);
		}
		else if(pos<2*root-1){
			print(2*root-1-pos+offset, offset+1);
		}
		else if(pos<3*root-2){
			print(offset+1, pos-2*root+3+offset);
		}
		else{
			print(pos-3*root+4+offset , root+offset);
		}
	}
	return 0;
}
