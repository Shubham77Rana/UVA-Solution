#include <bits/stdc++.h>
#define vi vector
#define pb push_back
#define pob pop_back

using namespace std;

vi<int> ret;
int size;
vi<vi<int>> ans;

void solve(int index, int n){
	for(int i=index; i*i<=n; ++i){
		if(n%i==0){
			ret.pb(i);
			solve(i, n/i);
			ret.pob();
		}
	}
	ret.pb(n);
	ans.pb(ret);
	ret.pob();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	while(cin >> n){
		if(!n) break;
		ans.clear();
		for(int i=2; i*i<=n; ++i){
			if(n%i==0){
				ret.pb(i);
				solve(i, n/i);
				ret.pob();
			}
		}
		cout << ans.size() << "\n";
		for(auto &v:ans){
			int t=0;
			for(int &x:v){
				if(t++>0) cout << " ";
				cout << x;
			}
			cout << "\n";
		}
	}
	return 0;
}