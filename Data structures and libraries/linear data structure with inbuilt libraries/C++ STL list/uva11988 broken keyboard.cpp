#include <bits/stdc++.h>

using namespace std;

struct node{
	char c;
	node *next;
	node *prev;
};

int main(){
	string s;
	while(cin >> s){
		bool start = false;
		node *head = new node;
		head->c = '#';
		node *temphead = NULL, *last = head;
		for(char &x:s){
			if(x == '['){
				start = true;
				if(temphead) head = temphead;
				temphead = NULL;
			}
			else if(x == ']'){
				start = false;
				if(temphead) head = temphead;
				temphead = NULL;
			}
			else{
				node *temp = new node;
				temp->c = x;
				if(start){
					if(head->prev) head->prev->next = temp;
					temp->next = head;
					temp->prev = head->prev;
					head->prev = temp;
					if(!temphead) temphead = temp;
				}
				else{
					temp->next = NULL;
					temp->prev = last;
					last->next = temp;
					last = temp;
				}
			}
		}
		if(temphead) head = temphead;
		while(head){
			if(head->c != '#') cout << head->c;
			head=head->next;
		}
		cout << "\n";
	}
	return 0;
}
