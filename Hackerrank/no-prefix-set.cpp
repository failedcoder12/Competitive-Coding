#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define hashmap unordered_map<ll,node*>

class node {
public:
    char data;
    hashmap h;
    bool isTerminal;
    node(char data){
        this->data = data;
        isTerminal = false;
    }
};

string ans;
ll whether = 0;
class tree {
public:
    node *root;
    tree(){
        root = new node('\0');
    }

    void add_word(string word){

        node *temp = root;
        for(ll i=0;word[i];i++){
            char c;
            if(temp->h.count(word[i])==0){
                temp->h[word[i]] = new node(word[i]);
                temp = temp->h[word[i]];
            }else {
                if(temp->isTerminal){
                    whether = 1;
                }
                temp = temp->h[word[i]];
                if(temp->isTerminal&&whether == 0){
                    whether = 1;
                    string ans(word);
                }
            }
        }
        temp->isTerminal = true;
        for(auto cc:temp->h){
            if(cc.first){
                    whether = 1;
                    string ans(word);
                return;
            }
        }
    }
};

int main() {
    tree t;
    ll n;
    cin>>n;
    string ss[n];
    for(ll i=0;i<n;i++){
        cin>>ss[i];
    }
    for(ll i=0;i<n;i++){
        t.add_word(ss[i]);
        if(whether == 1){
            cout<<"BAD SET"<<endl;
            cout<<ss[i]<<endl;
            return 0;
        }
    }
            cout<<"GOOD SET"<<endl;
}
