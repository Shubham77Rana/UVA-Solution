#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using  namespace std;

bool goneg(long long &count, int &cr, int cc, long long x, int row){
	int size = cr-row;
	for(--cr ;cr>=size; --cr){
		if(++count == x) return true;
	}
	++cr;
	return false;
}

bool gopos(long long &count, int &cr, int cc, long long x, int row){
	int size = cr+row;
	for(++cr ; cr<=size; ++cr){
		if(++count == x) return true;
	}
	--cr;
	return false;
}

void test_case(int n, long long tar){
	int dis = 1;
	long long count = 1;
	int cr = n/2, cc = n/2;
	if(tar == 1){
		cout << "Line = " << n-cr << ", column = " << cc+1 << ".\n";
		return;
	}
	while(count<1LL*n*n+1){
		if(goneg(count, cr, cc, tar, dis)){
			cout << "Line = " << n-cr << ", column = " << cc+1 << ".\n";
			return;
		}
		if(goneg(count, cc, cr, tar, dis)){
			cout << "Line = " << n-cr << ", column = " << cc+1 << ".\n";
			return;
		}
		++dis;
		if(gopos(count, cr, cc, tar, dis)){
			cout << "Line = " << n-cr << ", column = " << cc+1 << ".\n";
			return;
		}
		if(gopos(count, cc, cr, tar, dis)){
			cout << "Line = " << n-cr << ", column = " << cc+1 << ".\n";
			return;
		}
		++dis;
	}
	assert(false);
}

int main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long num;
	while(cin >> n >> num){
		if(!n&&!num) break;
		test_case(n, num);
	}
}
