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
    trie(){
        root = new node('\0');
    }
    void addword(string word){
        node *temp = root;
        for(int i=0;word[i];i++){
            char ch = word[i];
            if(temp->h.count(ch) == 0){
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }else {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }
    bool searchword(string word) {
        node *temp = root;
        for (int i = 0; word[i]; i++) {
            char ch = word[i];
            if(temp->h.count(ch)){
                temp = temp->h[ch];
            }else {
                return false;
            }
        }
        return temp->isTerminal;
    }
    void deletehelper(string word){
        node *temp = root;
        int len = word.length();
        if(len>0){
            cout<<deleteword(word,0,len,temp)<<endl;
        }
    }
    bool deleteword(string word,int s,int e,node *temp){
        if(temp){
            if(s == e){
                temp->isTerminal = false;
                return temp->h.empty();
            }else {
                if(deleteword(word,s+1,e,temp->h[word[s]])){
                    delete temp->h[word[s]];
                    temp->h.erase(word[s]);
                    cout<<temp->h.count(word[s])<<" "<<word[s]<<temp->h.count('1')<<endl;
                    return (temp->h.empty() && !temp->isTerminal);
                }
            }
        }
        return false;
    }
};

int main(){

}