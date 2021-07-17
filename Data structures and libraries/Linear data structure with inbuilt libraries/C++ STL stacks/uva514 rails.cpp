#include <bits/stdc++.h>
#define vi vector
#define pb push_back

using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(!n) break;
		while(1){
			vi<int> a(n);
			stack<int> st;
			cin >> a[0];
			if(!a[0]){
				cout << "\n";
				break;
			}
			for(int i=1; i<n; ++i) cin >> a[i];
			int current = 0;
			for(int i=1; i<n+1; ++i){
				while(!st.empty()&&st.top()==a[current]){
					st.pop();
					++current;
				}
				st.push(i);
			}
			while(!st.empty()&&st.top()==a[current]){
				st.pop();
				++current;
			}
			if(st.empty()&&current==n) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}
