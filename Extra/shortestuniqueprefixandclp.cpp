#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node *>

class node {
public:
    char data;
    hashmap h;
    int fre;
    bool isTerminal;
    node (char da){
        data = da;
        fre = 1;
        isTerminal = false;
    }
};

class trie {
public:
    node *root;
    trie() {
        root = new node('\0');
        root->fre = 0;
    }

    void addword(string word,int k = 0) {
        node *temp = root;
        for (int i = k; word[i]; i++) {
            char ch = word[i];
            if (temp->h.count(ch) == 0) {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            } else {
                temp = temp->h[ch];
                temp->fre ++;
            }
        }
        temp->isTerminal = true;
    }
};

void findprefixUtil(node *n,char pre[],int ind){
    if(n == NULL){
        return;
    }
    if(n->fre == 1){
        pre[ind] = '\0';
        cout<<pre<<endl;
        return;
    }
    for ( auto it = n->h.begin(); it != n->h.end(); ++it ){
        pre[ind] = (*it).first;
        findprefixUtil(n->h[(*it).first],pre,ind+1);
    }
}

string lcp(node *n){
    string x = "";
    while(!n->isTerminal && n->h.size() == 1){
            auto it = n->h.begin();
         n = n->h[it->first];
         x += (*it).first;
    }
    return x;
}

void findprefixes(string arr[],int n){
    trie t;
    node *temp = t.root;
    for(int i=0;i<n;i++){
        t.addword(arr[i]);
    }
    char pre[10000];
    findprefixUtil(temp,pre,0);
    cout<<lcp(temp)<<endl;
}
int main(){
    string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof(arr)/sizeof(arr[0]);
    findprefixes(arr, n);
};