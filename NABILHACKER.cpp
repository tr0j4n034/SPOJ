#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	Node* prev = NULL;
	Node* next = NULL;
	char ch;

	Node(char chh) {
		ch = chh;
	}
};

Node* head = NULL;
Node* current = NULL;

string str;
int t;

int main() {
		
	cin>>t;

	for(int j = 0; j < t; ++j) {
		cin>>str;
		head = NULL;
		current = NULL;
		for(int i = 0; i < str.size(); ++i) {
			if(str[i] != '<' && str[i] != '>' && str[i] != '-') {
				if(current == NULL) {
					current = new Node(str[i]);
					current->next = head;
					if(head != NULL)
						head->prev = current;
					head = current;
				} else {
					Node* newNode = new Node(str[i]);
					newNode->next = current->next;
					newNode->prev = current;
					if(current->next != NULL) {
						current->next->prev = newNode;
					}
					current->next = newNode;
					current = newNode;
				}
			} else if(str[i] == '<') {
				if(current == NULL)
					continue;
				current = current->prev;
			} else if(str[i] == '>') {
				if(current == NULL) {
					current = head;
				} else {
					if(current->next != NULL)
						current = current->next;
				}
			} else {
				if(current == NULL) {
					continue;
				}
				if(current->prev == NULL) {
					head = current->next;
					current = NULL;
					if(head != NULL)
						head->prev = NULL;
				} else {
					current->prev->next = current->next;
					if(current->next != NULL)
						current->next->prev = current->prev;
					current = current->prev;
				}
			}
		}

		while(head != NULL) {
			cout<<head->ch;
			head = head->next;
		}
		cout<<endl;
	}
	
}
