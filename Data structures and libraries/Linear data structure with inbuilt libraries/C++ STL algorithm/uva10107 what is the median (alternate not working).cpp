#include <bits/stdc++.h>
#define vi vector
#define pb push_back
#define MX 10001

using namespace std;

vi<int> ft(MX);

void update(int x){
	for( ; x<MX; x+=x&-x)
		++ft[x];
}

int query(int x){
	int ret = 0;
	for( ; x; x-=(x&-x))
		ret+=ft[x];
	return ret;
}

int bisearch(int index, vector<int> &a){
	int low = 1, high = MX;
	while(low < high){
		int mid = low + (high-low)/2;
		int k = query(mid);
		if(k<index) low = mid+1;
		else high = mid;
	}
	return low-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, n = 0;
	vi<int> a;
	while(cin >> x) a.pb(x);
	vi<int> at(a.size()), index(a.size());
	iota(index.begin(), index.end(), 0);
	sort(index.begin(), index.end(), [&](int i, int j){
		return a[i] < a[j];
	});
	int c = 0;
	for(int &x:index){
		at[x] = ++c;
	}
	for(int &x:at){
		++n;
		cout << x << " ";
		update(x);
		//if(n&1) cout << bisearch(n/2+1) << "\n";
		//else cout << int((bisearch(n/2+1)+bisearch(n/2))/2.0) << "\n";
	}
	return 0;
}
