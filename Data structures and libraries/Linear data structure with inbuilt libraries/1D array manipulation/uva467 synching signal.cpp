#include <bits/stdc++.h>
#define vi vector
using namespace std;

int getint(string &s, int low, int high){
	int ret = 0;
	for(int i=low; i<=high; ++i)
		ret = ret*10+(s[i]-'0');
	return ret;
}

void process(string &s, vi<int> &c){
	s.append(1, ' ');
	int size = s.size(), last=0;
	for(int i=0; i<size; ++i){
		if(s[i] == ' '){
			c.push_back(getint(s, last, i-1));
			last = i+1;
		}
	}
}

bool green(int x, int time){
	time = time%(2*x);
	if(time<x-5) return true;
	return false;	
}

void test_case(string &s){
	vi<int> c;
	process(s, c);
	int start=2*c[0];
	for(int &x:c) start=min(start, 2*x);
	for(int time = start; time<=3600; ++time){
		bool all = true;
		for(int &x:c){
			if(!green(x, time)){
				all = false;
				break;
			}
		}
		if(all){
			cout << "synchs again at " << time/60 << " minute(s) and " << time%60 << " second(s) after all turning green.\n";
			return;
		}
	}
	cout << "is unable to synch after one hour.\n";
}

int main(){
	string s;
	int t=1;
	while(getline(cin >> ws, s)){
		cout << "Set " << t++ << " ";
		test_case(s);
	}
	return  0;
}
