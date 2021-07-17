#include <bits/stdc++.h>
#define vi vector

using namespace std;

int main(){
	int n;
	while(cin >> n){
		vi<int> a(n);
		for(int &x:a) cin >> x;
		sort(a.begin(), a.end());
		int mid = n/2;
		int times = upper_bound(a.begin(), a.end(), a[mid])-lower_bound(a.begin(), a.end(), a[mid]);	
		if(n&1 || a[mid] == a[mid-1]) cout << a[mid] << " " << times << " " << "1\n"; 
		else{
			times += (upper_bound(a.begin(), a.end(), a[mid-1])-lower_bound(a.begin(), a.end(), a[mid-1]));
			cout << a[mid-1] << " " << times << " " << a[mid]-a[mid-1]+1 << "\n";
		}
	}
	return 0;
}
