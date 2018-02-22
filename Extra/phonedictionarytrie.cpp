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
            }
        }
        temp->isTerminal = true;
    }
    void display(node* n,string s){
        if(n->isTerminal){
            cout<<s<<endl;
        }
        for(auto p : n->h){
            display(p.second,s+p.first);
        }
    }
    void suggesstions(string s){
        node *previous = root;
        string prefix = "";
        int l = s.length();
        int i;
        for(i=0;i<l;i++) {
            prefix += s[i];
            char last = prefix[i];
            previous = previous->h[last];
            if(previous == NULL){
                cout << "No Result for " << prefix << endl;
                i++;
                break;
            }
            cout << "Suggestion based on " << prefix << " are \n";
            display(previous, prefix);
        }

        for (; i < l; i++) {
            prefix += s[i];
            cout << "No Result for " << prefix << endl;
        }
    }
};

int main(){
    string contacts[] = {"gforgeeks" , "geeksquiz"};
    trie t;
    for(auto c:contacts){
        t.addword(c);
    }
    string query = "gek";
    t.suggesstions(query);
};