#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class node {
	public: 
		char data;
		node *left;
		node *right;
		bool isTerminal;
		ll da;
	node(char d){
		data = d;
		left = NULL;
		right = NULL;
		isTerminal = false;
		da = -1;
	}
};

class trie {
	node *root;
	public:
		trie(){
			root = new node('\0');
		}
	void addword(char *word,ll a){
		node *temp = root;
		for(int i=0;word[i]!='\0';i++){
				if(word[i] == '0'){
					if(temp->left == NULL){
						temp->left = new node('0');
						temp = temp->left;
					}else {
						temp = temp->left;
					}
				}
				if(word[i] == '1'){
					if(temp->right == NULL){
						temp->right = new node('1');
						temp = temp->right;
					}else {
						temp = temp->right;
					}
				}
			}
		temp->da = a;
		temp->isTerminal = true;
	}

	ll search12(char *word,ll y){
		node *temp = root;
		return search(word,y,root);
	}

	ll search(char *word,ll y,node *r){
		if(word == NULL){
			return 0;
		}
		if(word[0] == '0'){
			r=r->left;
			if(r->da > 0){
				r->da = r->da - y;
				if(r->da == 0){
					r->da = 0;
					return 1+search(word+1,y,r);
				}else {
					return search(word+1,y,r);
				}
			}
		}else {
			ll left ,right;
			node *yy = r->right;
			r=r->left;
			if(r->da > 0){
				r->da = r->da - y;
				if(r->da == 0){
					r->da = 0;
					left = 1+search(word+1,y,r);
				}else {
					left = search(word+1,y,r);
				}
			}else {
				left = search(word+1,y,r);
			}

			if(yy->da > 0){
				yy->da = yy->da - y;
				if(yy->da == 0){
					yy->da = 0;
					right = 1+search(word+1,y,yy);
				}else {
					left = search(word+1,y,yy);
				}
			}else {
				left = search(word+1,y,yy);
			}
			return left+right;
	}
	}
};

string ccc(ll a){
	string aa = "";
	while(a){
		aa += (char)a+'0';
		a=a/2;
	}
	return aa;
}

int main(){
	trie t;
	for(ll i=0;i<5;i++){
		ll a;
		cin>>a;
		string aa = ccc(a);
		char tab2[aa.length()];
		strncpy(tab2, aa.c_str(), sizeof(tab2));
		tab2[sizeof(tab2) - 1] = 0;
		t.addword(tab2,a);
	}
	for(ll i=0;i<5;i++){
		ll x,y;
		x=1;y=1;
		string aaaa = ccc(x);
		char tab22[aaaa.length()];
		strncpy(tab22, aaaa.c_str(), sizeof(tab22));
		tab22[sizeof(tab22) - 1] = 0;
		cout<<t.search(tab2,y);
	}
}

