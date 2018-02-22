#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node *>

class node {
public:
    char data;
    hashmap h;
    bool isterminal;
    list <string> *l;
    node (char da){
        data = da;
        l = new list<string>;
        isterminal = false;
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
        string ss = word;
        sort(word.begin(),word.end());
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
        temp->l->push_back(ss);
        temp->isterminal = true;
    }

    void printutil(node *n){
        if(n->isterminal){
            for(auto s:*(n->l)){
                cout<<s<<" ";
            }
            cout<<endl;
        }
        for(auto c: n->h){
            printutil(c.second);
        }
    }
    void printanagram(){
        node *temp = root;
        for(auto c: temp->h){
            printutil(c.second);
        }
    }

};
int main(){

    trie t;
    string wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    for(int i=0;i<6;i++){
        t.addword(wordArr[i]);
    }

    t.printanagram();

};