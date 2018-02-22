#include<bits/stdc++.h>
using namespace std;
#define hashmap unordered_map<char,node *>

class node {
public:
    char data;
    hashmap h;
    list<string> *list1;
    bool isTerminal;
    node (char da){
        data = da;
        isTerminal = false;
        list1 = new list<string>;
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
            if(islower(ch)){
                continue;
            }
            if (temp->h.count(ch) == 0) {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            } else {
                temp = temp->h[ch];
            }
        }
        temp->list1->push_back(word);
        temp->isTerminal = true;
    }

    void printallword(node *temp){
        if(temp->isTerminal){
            for(string s : *temp->list1){
                cout<<s<<endl;
            }
        }

        if(!temp->h.empty()) {

            for (auto it = temp->h.begin(); it != temp->h.end(); it++) {
                if (temp->h.count((*it).first)){
                    printallword((*it).second);
                }
            }
        }
    }

    bool search(string pattern) {
        node *temp = root;
        for (int i = 0; i < pattern.length(); i++) {
            if (temp->h.count(pattern[i]) == 0) {
                cout<<pattern[i]<<" "<<root->h.count(pattern[i]);
                return false;
            }
            temp = temp->h[pattern[i]];
        }
        printallword(temp);
    }

};

int main(){
    string arr[] = {"Hi", "Hello", "HelloWorld", "HiTech", "HiGeek",
            "HiTechWorld", "HiTechCity", "HiTechLab"};
    trie t;
    for(string s: arr){
        t.addword(s);
    }
    string pattern = "HT";
    t.search(pattern);
};