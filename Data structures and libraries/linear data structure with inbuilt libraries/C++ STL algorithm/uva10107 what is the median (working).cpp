#include <bits/stdc++.h>
#define heap priority_queue
#define vi vector

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	heap<int> maxheap;
	heap<int, vi<int>, greater<int>> minheap;
	long long x, med, mxsize = 0, mnsize = 0;
	while(cin >> x){
		if(mxsize <= mnsize){
			if(mnsize > 0 && x > minheap.top()){
				maxheap.push(minheap.top());
				minheap.pop();
				minheap.push(x);
			}
			else maxheap.push(x);
			if(mxsize == mnsize) med = maxheap.top();
			else med = (1LL*maxheap.top()+minheap.top())/2.0;
			++mxsize;
		}
		else{
			if(x < maxheap.top()){
				minheap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(x);
			}
			else minheap.push(x);
			med = (1LL*maxheap.top()+minheap.top())/2.0;
			++mnsize;
		}
		cout << med << "\n";
	}
	return 0;
}
