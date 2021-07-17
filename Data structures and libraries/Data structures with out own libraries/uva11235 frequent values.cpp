#include <bits/stdc++.h>
#define left(x) 2*x
#define right(x) 2*x+1
#define trans(x) (x+(int)10e5+1)

using namespace std;

const int MX = 2*(int)10e5+10;
vector<pair<int, int>> first_last;

int getf(int x, int low, int high){
	int first = first_last[trans(x)].first, last = first_last[trans(x)].second;
	if(first == -1) return 0;
	if(low<=first && high>=last) return last-first+1;
	if(low<=first && high<last) return high-first+1;
	if(low>first && high>=last) return last-low+1;
	else return high-low+1;
}

int build(vector<int> &st, vector<int> &a, int root, int low, int high){
	if(low == high){
		st[root] = a[low];
		return st[root];
	}
	int mid = low + (high - low)/2;
	int leftchild = build(st, a, left(root), low, mid);
	int rightchild = build(st, a, right(root), mid+1, high);
	int leftfreq = getf(leftchild, low, high);
	int rightfreq = getf(rightchild, low, high);
	if(a[mid] == a[mid+1]){
		int midfreq = getf(a[mid], low, high);
		st[root] = leftfreq>rightfreq?(leftfreq>midfreq?leftchild:a[mid]):(rightfreq>midfreq?rightchild:a[mid]);
	}
	else st[root] = leftfreq>rightfreq?leftchild:rightchild;
	return st[root];
}

int query(vector<int> &st, vector<int> &a, int root, int low, int high, int l, int r){
	if(l>high || r<low) return -trans(0);
	if(l<=low && r>=high) return st[root];
	int mid = low + (high-low)/2;
	int leftchild = query(st, a, left(root), low, mid, l, r);
	int rightchild = query(st, a, right(root), mid+1, high, l, r);
	int leftfreq = getf(leftchild, max(low, l), min(high, r));
	int rightfreq = getf(rightchild, max(low, l), min(high, r));
	//cout << low << " " << high << " -> ";
	//cout << leftchild << ":" << leftfreq << " " << rightchild << ":" << rightfreq << "\n";
	if(a[mid] == a[mid+1] && leftfreq && rightfreq){
		int midfreq = getf(a[mid], max(low, l), min(high, r));
		return (leftfreq>rightfreq?(leftfreq>midfreq?leftchild:a[mid]):(rightfreq>midfreq?rightchild:a[mid]));
	}
	return (leftfreq>rightfreq?leftchild:rightchild);
}

void buildfreq(vector<int> &a){
	int size = a.size();
	first_last.resize(MX);
	fill(first_last.begin(), first_last.end(), make_pair(-1, -1));
	for(int i=0; i<size; ){
		int current = a[i];
		first_last[trans(current)].first = i;
		while(current == a[i]){
			++i;
		}
		first_last[trans(current)].second = i-1;
	}
}

void test_case(int n, int q){
	vector<int> a(n);
	vector<int> st(4*n);
	for(int &x:a) cin >> x;
	buildfreq(a);
	build(st, a, 1, 0, n-1);
	int l, r;
	for(int i=0; i<q; ++i){
		cin >> l >> r;
		cout << getf(query(st, a, 1, 0, n-1, l-1, r-1), l-1, r-1) << "\n";
	}
}

int main(){
	int n, q;
	while(cin >> n){
		if(!n) break;
		cin >> q;
		test_case(n, q);
	}
	return 0;
}
