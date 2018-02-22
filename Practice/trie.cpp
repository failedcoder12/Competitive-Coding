// Trie Data Structure in C++

#include<bits/stdc++.h>
using namespace std;

#define hashmap unordered_map<char,node *>

class node {
	public: 
		char data;
		hashmap h;
		bool isTerminal;
	node(char d){
		data = d;
		isTerminal = false;
	}
};

class trie {
	node *root;
	public:
		trie(){
			root = new node('\0');
		}
	void addword(char *word){
		node *temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];	
			if(temp->h.count(ch)==0){
				node *child = new node(ch);
				temp->h[ch] = child;
				temp = child;
			}else {
				temp = temp->h[ch];
				}
			}
		temp->isTerminal = true;
	}
	bool search(char *word){
		node *temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];
			if(temp->h.count(ch)){
				temp=temp->h[ch];
			}else {
				return false;
			}
		}
		return temp->isTerminal;
	}
};

int main(){
	char word[10][100] = {"divyansh verma","hello","coding blocks","pokemon"};
	trie t;
	for(int i=0;i<4;i++){
		t.addword(word[i]);
	}
	if(t.search("divyansh verma")){
		cout<<"Found"<<endl;
	}else {
		cout<<"Not Found"<<endl;
	}
	if(t.search("divyansh")){
		cout<<"Found"<<endl;
	}else {
		cout<<"Not Found"<<endl;
	}

}