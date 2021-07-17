#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x:a) cin >> x;
	priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>> minheap;
	for(int &x:a){
		minheap.push({x+x+x-5, x+x+1});
	}
	while(1){
		pair<int, int> top = minheap.top();
		minheap.pop();
		while(!minheap.empty()){
			pair<int, int> stop = minheap.top();
			if(top.second <= stop.second && top.first >= stop.first)
		}
	}
	return 0;
}
