#include <bits/stdc++.h>

using namespace std;

void revbin(bitset<32> &bin, int low, int high){
	while(low < high){
		int bit = bin[low];
		bin[low] = bin[high];
		bin[high] = bit;
		++low;
		--high;
	}
}

int main(){
	int n;
	while(cin >> n){
		bitset<32> bin;
		for(int i=0; i<32; ++i){
			if(n>>i&1) bin[i]=1;
		}
		for(int i=0; i<4; ++i){
			revbin(bin, i*8, (i+1)*8-1);
		}
		revbin(bin, 0, 31);
		int ret = bin.to_ulong();
		cout << n << " converts to " << ret << "\n";
	}
	return 0;
}
