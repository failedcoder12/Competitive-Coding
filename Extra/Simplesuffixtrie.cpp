#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node *>

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

    void addword(string word,int k) {
        node *temp = root;
        for (int i = k; word[i]; i++) {
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
    int countnode(node* n){
        if(n == NULL){
            return 0;
        }
        int count = 0;
        for(auto c : n->h){
            count += countnode(c.second);
        }
        return 1+count;
    }
};
int main(){
    trie t;
    string s = "ababa";
    for(int i=0;i<s.length();i++){
        t.addword(s,i);
    }
    cout<<t.countnode(t.root)<<endl;
}
