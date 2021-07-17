#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &a, vector<int> &b, int loss, const set<int> &used){
	if(b.empty()){
		if(loss>1) return -1;
		else if(loss>0){ 
			int ret = a.back()+1;
			while(used.count(ret))
				++ret;
			if(ret>52) return -1;
			return ret;
		}
		else{
			int ret = 1;
			while(used.count(ret))
				++ret;
			if(ret>52) return -1;
			return ret;
		}
	}
	if(b.back()>a.back()){
		b.pop_back();
		a.erase(a.begin());
		return solve(a, b, loss, used);
	}
	auto index = lower_bound(a.begin(), a.end(), b.back());
	a.erase(index);
	b.pop_back();
	return solve(a, b, loss+1, used);
}

int main(){
	while(1){
		vector<int> a(3), b(2);
		for(int i=0; i<3; ++i) cin >> a[i];
		cin >> b[0] >> b[1];
		if(!a[0]) break;
		set<int> used;
		for(int &x:a) used.insert(x);
		for(int &x:b) used.insert(x);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		cout << solve(a, b, 0, used) << "\n";
	}
}
