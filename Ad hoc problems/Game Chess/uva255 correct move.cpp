#include <bits/stdc++.h>

using namespace std;

int main(){
	int k, q, next;
	while(cin >> k >> q >> next){
		if(k == q){
			cout << "Illegal state\n";
			continue;
		}
		if(next == k || next == q){
			cout << "Illegal move\n";
			continue;
		}
		vector<int> km;
		if(k-8>=0) km.push_back(k-8);
		if(k+8<64) km.push_back(k+8);
		if(k%8!=0) km.push_back(k-1);
		if((k+1)%8!=0) km.push_back(k+1);
		if(q/8 == next/8 || q%8 == next%8){
			if(q/8 == next/8 && q/8 == k/8){
				if((q<k && k<next)||(next<k && k<q)){
					cout << "Illegal move\n";
					continue;
				}
			}
			if(q%8 == next%8 && q%8 == k%8){
				if((q<k && k<next)||(next<k && k<q)){
					cout << "Illegal move\n";
					continue;
				}
			}
			bool flag = false;
			for(int &x:km){
				if(next == x){
					flag = true;
					 break;
				}
			}
			if(flag){ 
				cout << "Move not allowed\n";
				continue;
			}
			flag = false;
			for(int &x:km){
				if(x/8 != next/8 && x%8 != next%8){
					flag = true;
					break;
				}
			}
			if(flag) cout << "Continue\n";
			else cout << "Stop\n";
		}
		else cout << "Illegal move\n";
	}
	return 0;
}
