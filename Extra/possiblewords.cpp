#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node *>
#define hashmap1 unordered_map<char,bool>

class node {
public:
    char data;
    hashmap h;
    bool isTerminal;
    node (char da){
        data = da;
        isTerminal = false;
    }
};

class trie {
public:
    node *root;

    trie() {
        root = new node('\0');
    }

    void addword(string word) {
        node *temp = root;
        for (int i = 0; word[i]; i++) {
            char ch = word[i];
            if (temp->h.count(ch) == 0) {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            } else {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }
    void searchword(node *n,hashmap1 h1,string s){
        if(n->isTerminal){
            cout<<s<<endl;
        }
        for(auto c:h1){
            if(h1[c.first] == false && n->h.count(c.first)){
                searchword(n->h[c.first],h1,s+c.first);
//                cout<<s<<endl;
            }
        }
    }
    void printallpossible(char a[],int n){
        hashmap1 h1;
        for(int i=0;i<n;i++){
            h1[a[i]] = false;
        }
        node *temp = root;
        string s="";
        for(auto c: h1){
            if(h1[c.first] == false && temp->h.count(c.first)){
                searchword(temp->h[c.first],h1,s+c.first);
            }
        }
    }
};
int main(){
    trie t;
    string a[] = {"go","bat","me","eat","goal","boy", "run"};
    for(int i=0;i<7;i++){
        t.addword(a[i]);
    }
    char arr[] = {'e', 'o', 'b', 'a', 'm', 'g', 'l'} ;
    t.printallpossible(arr,7);
}
