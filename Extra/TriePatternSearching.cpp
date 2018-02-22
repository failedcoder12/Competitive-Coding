#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node *>

class node {
public:
    char data;
    hashmap h;
    list <int> *l;
    node (char da){
        data = da;
        l = new list<int>;
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
                temp->l->push_back(i);
                temp->h[ch] = child;
                temp = child;
            } else {
                 temp->l->push_back(i);
                temp = temp->h[ch];
            }
        }
    }

    list<int>* searchword(string word) {
        node *temp = root;
        for (int i = 0; word[i]; i++) {
            char ch = word[i];
            if (temp->h.count(ch)) {
                temp = temp->h[ch];
            } else {
                return NULL;
            }
        }
        return temp->l;
    }
};
int main(){

    trie t;
    string txt = "geeksforgeeks.org";
    for(int i=0;i<txt.length();i++){
        t.addword(txt,i);
    }

    list<int> *l;
    list<int>::iterator i;
    string s = "ee";
    l = t.searchword(s);
    cout<<"ee"<<endl;
    for(i = l->begin();i!=l->end();i++){
        cout<<"Pattern is "<<*i - s.length()<<endl;
    }
    s = "geek";
    l = t.searchword(s);
    cout<<"geek"<<endl;
    for(i = l->begin();i!=l->end();i++){
        cout<<"Pattern is "<<*i - s.length()<<endl;
    }
    s = "e";
    l = t.searchword(s);
    cout<<"e"<<endl;
    for(i = l->begin();i!=l->end();i++){
        cout<<"Pattern is "<<*i - s.length()<<endl;
    }
    s = "forgeeks";
    l = t.searchword(s);
    cout<<s<<endl;
    for(i = l->begin();i!=l->end();i++){
        cout<<"Pattern is "<<*i - s.length()<<endl;
    }
    s = "geeksforgeeks.org";
    l = t.searchword(s);
    cout<<s<<endl;
    for(i = l->begin();i!=l->end();i++){
        cout<<"Pattern is "<<*i - s.length()<<endl;
    }

    s = "g";
    l = t.searchword(s);
    cout<<s<<endl;
    for(i = l->begin();i!=l->end();i++){
        cout<<"Pattern is "<<*i - s.length()<<endl;
    }
    s = "eequiz";
    l = t.searchword(s);
    if( l == NULL) {
        cout<<"Not Found"<<endl;
        return 0;
    }
    cout<<s<<endl;
    for(i = l->begin();i!=l->end();i++){
        cout<<"Pattern is "<<*i - s.length()<<endl;
    }

};